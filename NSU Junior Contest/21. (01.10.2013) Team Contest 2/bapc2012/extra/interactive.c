#include "interactive.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <time.h>

/* Program name */
char *progname;

const struct timespec killdelay = { 0, 100000000L }; /* 0.1 seconds */

/* Define input and output */
FILE *child_stdin;
FILE *child_stdout;

/* Some global variables */
pid_t child_pid;
int pipe_stdin[2];
int pipe_stdout[2];
bool isKilled;

/* Array indices for input/output file descriptors as used by pipe() */
#define PIPE_IN  1
#define PIPE_OUT 0

/* Utility function for error messages */
void err(const char *msg, ...) {
	va_list arg;
	va_start(arg, msg);
	fprintf(stderr, "%s error: ", progname);
	vfprintf(stderr, msg, arg);
	fprintf(stderr, "\n");
	va_end(arg);
	exit(1);
}

/* Signal handler that kills the child process and then exits */
void signal_handler(int signo) {
	(void)signo;  /* unused */
	exit(interactive_kill());
}

void interactive_init(int argc, char **argv) {
	int i;
	char **nargv;
	
	/* Set global name of this executable */
	progname = argv[0];
	isKilled = false;

	/* Check arguments */
	if (argc-1 < 1) err("Invalid number of arguments. Usage: %s <submission command>", progname);

	/* Open pipes for IO redirection */
	if (pipe(pipe_stdin)!=0 ) err("Could not create stdin pipe.");
	if (pipe(pipe_stdout)!=0 ) err("Could not create stdout pipe.");

	/* Create argv for child process */
	if ((nargv=(char **) malloc(argc*sizeof(char **)))==NULL) err("Could not create argv.");
	for(i = 0; i < argc - 1; i++)
	  nargv[i] = argv[i+1];
	nargv[argc-1] = NULL;
	
	/* Fork child process */
	switch ( child_pid = fork() ) {
	case -1: /* error */
		err("Could not create child process.");
		
	case  0: /* child process */
		/* Redirect stdin */
		if ( dup2(pipe_stdin[PIPE_OUT],STDIN_FILENO)<0 ) err("Could not redirect stdin.");
		close(pipe_stdin[PIPE_OUT]);
		close(pipe_stdin[PIPE_IN]);

		/* Redirect stdout */
		if ( dup2(pipe_stdout[PIPE_IN],STDOUT_FILENO)<0 ) err("Could not redirect stdout.");
		close(pipe_stdout[PIPE_IN]);
		close(pipe_stdout[PIPE_OUT]);

		/* Replace child with command */
		execvp(nargv[0],nargv);
		abort();

	default: /* parent process */
		/* IO redirection */
		close(pipe_stdin[PIPE_OUT]);
		close(pipe_stdout[PIPE_IN]);
		if((child_stdin = fdopen(pipe_stdin[PIPE_IN], "w")) == NULL) err("Could not open stdin pipe for writing.");
		if((child_stdout = fdopen(pipe_stdout[PIPE_OUT], "r")) == NULL) err("Could not open stdout pipe for reading.");

		/* Make child stdin/stdout unbuffered*/
		if (setvbuf(child_stdin,  NULL, _IONBF, 0)!=0)  err("Could not make stdin unbuffered.");
		if (setvbuf(child_stdout,  NULL, _IONBF, 0)!=0)  err("Could not make stdin unbuffered.");
		
		{	/* Register signal handler to kill child on SIGTERM: */
			struct sigaction sa;
			sa.sa_handler = &signal_handler;
			sigemptyset(&sa.sa_mask);
			sa.sa_flags = 0;
			if (sigaction(SIGTERM, &sa, NULL) != 0) err("Could not install SIGTERM handler.");
		}
		
		/* Now do the communication and wait for interactive_exit to be called */
		return;
	}

	err("This should never be reached.");
}

int interactive_exit() {
	int status;

	/* Close IO redirections */
	fclose(child_stdin);
	close(pipe_stdin[PIPE_IN]);
	fclose(child_stdout);
	close(pipe_stdout[PIPE_OUT]);

	/* Wait for the child command to finish */
	waitpid(child_pid, &status, 0);
	
	/* Check return code */
	if ( ! WIFEXITED(status) ) {
		if ( WIFSIGNALED(status) ) {
			if(isKilled && WTERMSIG(status) == SIGKILL) {
				/* We killed the submission so everything is fine */
				fprintf(stderr,"%s ended succesfully.\n", progname);
				return 0;
			}
			fprintf(stderr, "%s: submission terminated with signal %d\n",progname,WTERMSIG(status));
			return 128+WTERMSIG(status);
		} else {
			err("exit status unknown: %d",status);
			return 1;
		}
	} else {
		/* Everything went fine! */
		fprintf(stderr,"%s ended succesfully.\n", progname);
		return WEXITSTATUS(status);
	}
}

int interactive_kill() {
  if(kill(child_pid,SIGKILL) != 0) err("Could not send SIGKILL: %s",strerror(errno));
  
  /* Wait another while to make sure the process is killed by now. */
  nanosleep(&killdelay,NULL);

  isKilled = true;
  return interactive_exit();
}

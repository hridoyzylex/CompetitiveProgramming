#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <stdio.h>

/*
 * Start the child process and setup all
 * interactive communication. Must be called
 * from main before doing anything else.
 */
void interactive_init(int argc, char **argv);

/*
 * Wait for the child to finish and clean up
 * all resources. Returns the return code of
 * the child process. This must always be
 * called as last function.
 */
int interactive_exit();

/* 
 * The stdin of the child, so data can only
 * be written to this stream.
 */
extern FILE *child_stdin;

/* 
 * The stdout of the child, so data can only
 * be read from this stream.
 */
extern FILE *child_stdout;

/*
 * Kill the submission and generate a run
 * error. This should always be called as
 * final function and the return code
 * returned from main.
 */
int interactive_kill();

#endif

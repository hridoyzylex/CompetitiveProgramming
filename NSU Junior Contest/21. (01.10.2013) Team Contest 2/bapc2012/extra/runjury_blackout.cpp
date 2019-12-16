#include "interactive.h"
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

// For H = 5, W = 6: run precalc.cpp first!

//const int H = 2, W = 3;
//const int H = 5, W = 4;
const int H = 5, W = 6;
const int S = 1 << (H*W), M = H*W*(H+W)/2; // S = #states, M = #moves

int Move[M];
char Losing[S >> 3];
int MoveIdx[H][W][H][W];
int MoveR1[M];
int MoveC1[M];
int MoveR2[M];
int MoveC2[M];


/*** Determine all possible moves ***/

void moves()
{ int m = 0, i, j, i2, j2;
	memset(MoveIdx, -1, sizeof(MoveIdx));
	// Single squares
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++) {
			MoveIdx[i][j][i][j] = m;
			MoveR1[m] = i;
			MoveC1[m] = j;
			MoveR2[m] = i;
			MoveC2[m] = j;
			Move[m++] = 1 << (i*W+j);
		}
	// Horizontal
	for (i = 0; i < H; i++)
		for (j = 0; j < W-1; j++) {
			MoveIdx[i][j][i][j+1] = m;
			MoveR1[m] = i;
			MoveC1[m] = j;
			MoveR2[m] = i;
			MoveC2[m] = j+1;
			Move[m++] = (1 << (i*W+j)) | (1 << (i*W+j+1));
			for (j2 = j+2; j2 < W; j2++) {
				MoveIdx[i][j][i][j2] = m;
				MoveR1[m] = i;
				MoveC1[m] = j;
				MoveR2[m] = i;
				MoveC2[m] = j2;
				Move[m] = Move[m-1] | (1 << (i*W+j2));
				m++;
			}
		}
	// Vertical
	for (j = 0; j < W; j++)
		for (i = 0; i < H-1; i++) {
			MoveIdx[i][j][i+1][j] = m;
			MoveR1[m] = i;
			MoveC1[m] = j;
			MoveR2[m] = i+1;
			MoveC2[m] = j;
			Move[m++] = (1 << (i*W+j)) | (1 << (i*W+j+W));
			for (i2 = i+2; i2 < H; i2++) {
				MoveIdx[i][j][i2][j] = m;
				MoveR1[m] = i;
				MoveC1[m] = j;
				MoveR2[m] = i2;
				MoveC2[m] = j;
				Move[m] = Move[m-1] | (1 << (i2*W+j));
				m++;
			}
		}
}


/*** Determine evaluation for all states ***/

// Returns whether state s is losing
bool losing (int s)
{ return Losing[s >> 3] & (1 << (s&7));
}

void precalc()
{ int s, i;
  memset(Losing, 0, sizeof(Losing)); // Set all states to winning
  Losing[(S>>3) - 1] = 128; // Set state S-1 to losing
  for (s = S - 2; s >= 0; s--)
  { // Look for winning move
    for (i = 0; i < M; i++)
      if (losing(s | Move[i]))
        break;
    if (i == M) // No winning move found
      Losing[s >> 3] |= 1 << (s&7);
  }
}


/*** Read evaluations from file ***/

void read()
{ FILE* in = fopen("precalc.in", "r");
  fread(Losing, 1, 1 << (H*W-3), in);
  fclose(in);
}


/*** Miscellaneous ***/

// Checks that all states with rotational symmetry (and center row completely black) are losing
void show (int);
bool symmetric(int);
void test_symmetry()
{ int s;
  for (s = 0; s < S; s++)
  { if (((~s & (7<<8)) == 0) && symmetric(s) && !losing(s)) // H=5, W=4
    //if (((~s & (31<<12)) == 0) && symmetric(s) && !losing(s)) // H=5, W=6
    { printf("%s\n", losing(s) ? "Losing" : "Winning");
      show(s);
      return;
    }
  }
}

// Prints some statistics
void stats()
{ long long k = 0, m = 0, u = 0, w = 0, uw = 0;
  int s, s2, i;
  for (s = 0; s < S; s++)
  { set<int> Seen;
    if (losing(s))
      k++;
    for (i = 0; i < M; i++)
      if ((s2 = s | Move[i]) > s)
      { m++;
        if (!Seen.count(s2))
        { Seen.insert(s2);
          u++;
          if (losing(s2))
          { w++;
            uw++;
          }
        }
        else if (losing(s2))
          w++;
      }
  }
  printf("Total number of states and moves:\n  %d %d\n", S, M);
  printf("Losing states (total, ratio):\n  %lld %lf\n", k, (double)k / S);
  printf("Number of moves (total, average):\n  %lld %lf\n", m, (double)m / S);
  printf("Number of unique moves (total, average):\n  %lld %lf\n", u, (double)u / S);
  printf("Number of winning moves (total, average, average per winning state):\n  %lld %lf %lf\n", w, (double)w / S, (double)w / (S-k));
  printf("Number of unique winning moves (total, average, average per winning state):\n  %lld %lf %lf\n", uw, (double)uw / S, (double)uw / (S-k));
}


/*** Returns symmetry-preserving move (intended solution) ***/

// Returns whether state s has rotational symmetry
bool symmetric (int s)
{ int i, a, b;
  for (i = 0; i < H*W/2; i++)
  { a = (1 << i) | (1 << (H*W-1-i));
    b = s & a;
    if (b > 0 && b < a)
      return false;
  }
  return true;
}

int symmetricmove (int s)
{ int s2, i;
  if (s == 0) // First move
  { s2 = 0;
    if (H%2 == 1 && W%2 == 0) // Center row
      for (i = 0; i < W; i++)
        s2 |= 1 << ((H/2)*W + i);
    else if (H%2 == 0 && W%2 == 1) // Center column
      for (i = 0; i < H; i++)
        s2 |= 1 << (i*W + (W/2));
    else
      return -1;
    for (i = 0; i < M; i++)
      if (Move[i] == s2)
        return i;
  }
  else
    for (i = 0; i < M; i++)
      if ((s2 = s | Move[i]) > s && symmetric(s2))
        return i;
  return -1;
}


/*** Jury player ***/

set<int> Played;
bool Legal[M];
int Seen[M], Moves[M], Unique[M], Winning[M], UniqueWinning[M];
int RandomNumber[M];

// Returns (pseudo)random integer
long long rseed = 42;
int randnr()
{ return (int)(rseed = (16807 * rseed) % 0x7fffffff);
}

// Rotates the state 180 degrees
int rotate (int s)
{ int s2 = 0, i;
  for (i = 0; i < H*W; i++)
    if (s & (1 << i))
      s2 |= 1 << (H*W-1-i);
  return s2;
}

// Flips the state horizontally
int flip_horiz (int s)
{ int s2 = 0, i, j;
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++)
      if (s & (1 << (i*W + j)))
        s2 |= 1 << (i*W + W-1-j);
  return s2;
}

// Flips the state vertically
int flip_vert (int s)
{ int s2 = 0, i, j;
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++)
      if (s & (1 << (i*W + j)))
        s2 |= 1 << ((H-1-i)*W + j);
  return s2;
}

// Returns whether Move[i] is better than Move[j]
// Order of preference:
// - Move is legal (obviously)
// - Renders a previously unseen state (including symmetrically equivalent states)
// - Renders a previously unseen state (excluding symmetry)
// - Renders a state with relatively fewest winning moves (as given by Winning[i] / Moves[i])
// - RandomNumber[i] < RandomNumber[j]
bool compare_moves (int i, int j)
{ return Legal[i] && (!Legal[j] ||
         Seen[i] <  Seen[j] ||
        (Seen[i] == Seen[j] && (Winning[i] * Moves[j] <  Winning[j] * Moves[i] ||
                               (Winning[i] * Moves[j] == Winning[j] * Moves[i] && RandomNumber[i] < RandomNumber[j]))));
}

int jurymove (int s)
{ int i;
  if (!losing(s)) // Winning state: return any winning move
    for (i = 0; i < M; i++)
      if (losing(s | Move[i]))
        return i;
  int s2, s3, j, m;
  memset(Moves, 0, M*sizeof(int)); // Moves[i] = Number of moves the next player has (after move i)
  memset(Unique, 0, M*sizeof(int)); // Number of unique states that can result
  memset(Winning, 0, M*sizeof(int)); // Number of winning moves the next player has
  memset(UniqueWinning, 0, M*sizeof(int)); // Number of unique losing states that can result
  // Try all moves for jury
  for (i = 0; i < M; i++)
  { s2 = s | Move[i]; // State for the other player
    if (!(Legal[i] = (s2 > s))) // Determine/check legality
      continue;
    RandomNumber[i] = randnr() % 1234567;
    Seen[i] = (Played.count(s2) ? 2 : Played.count(rotate(s2)) || Played.count(flip_horiz(s2)) || Played.count(flip_vert(s2)) ? 1 : 0);
    // Seen[i] = 2 if state s2 was already seen, 1 if a symmetric state was already seen, 0 if not seen at all
    set<int> States;
    // Try all moves for next player
    for (j = 0; j < M; j++)
      if ((s3 = s2 | Move[j]) > s2) // Check if legal
      { Moves[i]++;
        if (!States.count(s3)) // Check if the resulting state is new
        { States.insert(s3);
          Unique[i]++;
          if (losing(s3)) // Check if it's a winning move
          { Winning[i]++;
            UniqueWinning[i]++;
          }
        }
        else if (losing(s3)) // Check if it's a winning move
          Winning[i]++;
      }
  }
  // Look for best move as based on function compare_moves
  m = 0;
  for (i = 1; i < M; i++)
    m = min(m, i, compare_moves);
  //printf("%d  %d %d  %d %d\n", Seen[m], Winning[m], Moves[m], UniqueWinning[m], Unique[m]); // Debug output
  Played.insert(s | Move[m]); // Add new state to set of played states
  return m;
}


/*** Simulate games ***/

// Prints the state (or move)
// 'x' = black square, '*' = new black square
void show (int s, int prev)
{ int i, j;
  for (i = 0; i < H; i++)
  { for (j = 0; j < W; j++)
      printf("%c", !(s & (1 << (i*W+j))) ? '.' : prev & (1 << (i*W+j)) ? 'x' : '*');
    printf("\n");
  }
  printf("\n");
}

// No previous state
void show (int s)
{ show(s, s);
}

// Lets two bots play against each other
//   type == 0: jurymove() vs. jurymove()
//   type == 1: symmetricmove() vs. jurymove()
// Returns the winner (0 for player one, 1 for player two, -1 if something went wrong)
int play (int type = 1)
{ int s = 0, t, m;
  for (t = 0; s < S-1 && t < H*W+10; t++)
  { if (t%2 == 0) // Player 1
      m = (type == 1 ? symmetricmove(s) : jurymove(s));
    else // Player 2
      m = jurymove(s);
    if (m < 0 || m >= M || (s | Move[m]) == s) // Check legality
      return -1;
    printf("Player %d\n", t%2+1);
    show(s | Move[m], s);
    s |= Move[m];
  }
  printf("----------\n\n");
  return 1 - t%2;
}

void simulate (int type = 1)
{ Played = set<int>();
  int c, res;
  for (c = 0; c < 50; c++)
  { res = play(type);
    if (res == -1)
    { printf("Something went wrong!\n");
      return;
    }
    if (res == 1)
    { printf("Player 2 wins! Wtf?\n");
      return;
    }
  }
}


/*int main()
{ moves();
  //precalc();
  //read();
  if (H == 5 && W == 6)  read();  else  precalc();
  //test_symmetry(); return 0;
  //stats(); return 0;
  simulate(1); return 0;
}*/

/*** Interactive communication ***/
bool readmove(int *m) {
	int r1, c1, r2, c2;
	char line[256];

	/* Read one line from child */
	if(fgets(line,255,child_stdout) == NULL) {
		fprintf(stderr, "EOF found.\n");
		return false;
	}
	
	/* Read 4 integers from this line */
	if(sscanf(line, "%d %d %d %d\n", &r1, &c1, &r2, &c2) != 4) {
		fprintf(stderr, "Invalid format: \"%s\"\n", line);
		return false;
	}
	
	/* Check if within bounds */
	if(r1 < 1 || r2 < r1 || r2 > H || c1 < 1 || c2 < c1 || c2 > W) {
		fprintf(stderr, "Invalid coordinates: %d %d %d %d\n", r1, c1, r2, c2);
		return false;
	}
	
	/* Check if valid move */
	*m = MoveIdx[r1-1][c1-1][r2-1][c2-1];
	if(*m < 0) {
		fprintf(stderr, "Invalid move: %d %d %d %d\n", r1, c1, r2, c2);
		return false;
	}

	/* Correct move */
	return true;
}

/* Print the move in r1 r1 r2 r2 format */
void printmove(FILE *out, int m) {
	fprintf(out, "MOVE %d %d %d %d\n", MoveR1[m]+1, MoveC1[m]+1, MoveR2[m]+1, MoveC2[m]+1);
}

int main(int argc, char **argv) {
	/* Init interactive communication */
	interactive_init(argc, argv);

	/* Make sure precalculated data is ready */
	moves();
	if (H == 5 && W == 6)
		read();
	else
		precalc();

	/* Read number of testcases */
	int cases;
	scanf("%d\n", &cases);

	/* Pass number of cases to submission */
	fprintf(child_stdin, "%d\n", cases);
	
	/* Play a game for each testcase */
	while(cases--) {
		int s = 0;
		int t = 0;
		while(s < S - 1) {
			int m;
			if(t % 2) {
				/* Do jury move */
				m = jurymove(s);
				if ((s | Move[m]) == S-1)
				{ t++;
				  break;
				}
				printmove(child_stdin, m);
			} else {
				/* Do submission move */
				if(!readmove(&m))
					return interactive_kill();
			}
			
			/* Check legality */
			if (m < 0 || m >= M || (s | Move[m]) == s) {
				fprintf(stderr, "Invalid move %d in state %d\n", m, s);
				return interactive_kill();
			}

			/* Do the move */
			s |= Move[m];
			t++;
		}

		/* Print result to output, child, and stderr (for debugging) */
		printf("%s\n", t % 2 ? "Submission wins" : "Jury wins");
		//fprintf(stderr, "%s in %d steps\n", t % 2 ? "Submission wins" : "Jury wins", t);
		fprintf(child_stdin, "GAME\n");
	}
	
	/* Cleanup and exit gracefully */
	return interactive_exit();
}

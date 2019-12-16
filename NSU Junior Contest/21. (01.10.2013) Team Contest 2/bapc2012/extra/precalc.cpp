#include <cstdio>
#include <cstring>
using namespace std;

const int H = 5, W = 6;
const int S = 1 << (H*W), M = H*W*(H+W)/2; // S = #states, M = #moves

int Move[M];
char Losing[S >> 3];

// Determines all possible moves
void moves()
{ int m = 0, i, j, i2, j2;
  // Single squares
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++)
      Move[m++] = 1 << (i*W+j);
  // Horizontal
  for (i = 0; i < H; i++)
    for (j = 0; j < W-1; j++)
    { Move[m++] = (1 << (i*W+j)) | (1 << (i*W+j+1));
      for (j2 = j+2; j2 < W; j2++)
      { Move[m] = Move[m-1] | (1 << (i*W+j2));
        m++;
      }
    }
  // Vertical
  for (j = 0; j < W; j++)
    for (i = 0; i < H-1; i++)
    { Move[m++] = (1 << (i*W+j)) | (1 << (i*W+j+W));
      for (i2 = i+2; i2 < H; i2++)
      { Move[m] = Move[m-1] | (1 << (i2*W+j));
        m++;
      }
    }
}

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

int main()
{ moves();
  precalc();
  FILE* out = fopen("precalc.in", "w");
  fwrite(Losing, 1, S >> 3, out);
  fclose(out);
  return 0;
}


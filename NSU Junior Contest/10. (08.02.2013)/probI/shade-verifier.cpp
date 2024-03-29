#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_N = 200;
const double PI = acos(-1.0);

ifstream infile("shade.in");
ifstream outfile("shade.out");
ofstream vfyfile("shade-verifier.out");
ofstream tempfile("shade.tmp");

bool bad = false;

struct Circle
{
  int x, y, r;
};

istream &operator>>(istream &is, Circle &c)
{
  return is >> c.x >> c.y >> c.r;
}

bool solve(int id)
{
  int N;
  infile >> N;
  if (!N) return false;

  Circle c[MAX_N];
  for (int i = 0; i < N; i++) {
    infile >> c[i];
  }

  double best_shade = 0.0;
  //  int best_time;

  for (int t = 0; t < 24*60; t++) {
    double shade = 0.0;
    double angle = 2*PI*t/(24*60);
    double sun_x = 500.0 * sin(angle);
    double sun_y = 500 * cos(angle);

    for (int i = 0; i < N; i++) {
      double proj = (sun_x * c[i].x + sun_y * c[i].y) /
	sqrt(sun_x * sun_x + sun_y * sun_y);
      if (proj < 0) continue;
      double dist_sq = c[i].x*c[i].x + c[i].y*c[i].y - proj*proj;
      if (dist_sq > c[i].r*c[i].r) continue;

      shade += 2*sqrt(c[i].r*c[i].r - dist_sq);
    }

    if (shade > best_shade) {
      best_shade = shade;
      //      best_time = t;
    }
  }

  double ans;
  if (!(outfile >> ans)) {
    vfyfile << "missing Case " << id << endl;
    vfyfile << "WRONG ANSWER" << endl;
    bad = true;
    return true;
  }

  if (fabs(ans - best_shade) > 0.0015) {
    vfyfile << "Case " << id << endl;
    vfyfile << "WRONG ANSWER: " << fixed << setprecision(3) << ans << endl;
    vfyfile << "EXPECTING: " << fixed << setprecision(3) << best_shade << endl;
    vfyfile << "WRONG ANSWER" << endl;
    bad = true;
  }

  tempfile << fixed << setprecision(3) << ans << endl;
  
  return true;
}

int main()
{
  vfyfile << "shade-verifier" << endl;
  int id = 1;
  while (solve(id++))
    ;

  if (bad) {
    vfyfile << "WRONG OUTPUT" << endl;
    return 1;
  }

  if (system("diff shade.out shade.tmp > /dev/null 2>&1") != 0) {
    vfyfile << "PRESENTATION ERROR" << endl;
    return 2;
  }

  vfyfile << "CORRECT!" << endl;
  return 0;
}

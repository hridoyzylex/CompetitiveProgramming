#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double epsilon = 1.0e-12;
double kDelta = 1.0e-5;
struct Obs {
  double time;
  double x;
  double y;
  double s;
};

struct Car {
  Obs o[2];
  double a;
  Obs current;
};

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2)*(x1 - x2) +
              (y1 - y2)*(y1 - y2));
}

void calculatePositionAfterDelta(Car& c, double delta) {
  if (c.current.s < epsilon) return;

  double d = delta*c.current.s + 0.5*c.a*delta*delta;
  c.current.s = c.current.s + c.a*delta;
  if (c.current.s < epsilon) {
    c.current.s = 0.0;
  } else if (c.current.s > 80.0) {
    c.current.s = 80.0;
  }

  c.current.x += d*(c.o[1].x - c.o[0].x)/dist(c.o[0].x, c.o[0].y, c.o[1].x, c.o[1].y);
  c.current.y += d*(c.o[1].y - c.o[0].y)/dist(c.o[0].x, c.o[0].y, c.o[1].x, c.o[1].y);
  c.current.time += delta;
}

int main() {
  while(true) {
    Car cars[2];
    double maxT = 0.0;
    bool done = false;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> cars[i].o[j].time >> cars[i].o[j].x >> cars[i].o[j].y >> cars[i].o[j].s;
        if (cars[i].o[j].time < 0.0 && cars[i].o[j].s < 0.0) {
          done = true;
          break;
        }
        if (cars[i].o[j].time > maxT) {
          maxT = cars[i].o[j].time;
        }
      }
      if (done) break;
      cars[i].a = (cars[i].o[1].s - cars[i].o[0].s)/(cars[i].o[1].time - cars[i].o[0].time);
      cars[i].current = cars[i].o[1];
    }
    if (done) break;

    for (int i = 0; i < 2; i++) {
      while(cars[i].current.time < maxT) {
        calculatePositionAfterDelta(cars[i], kDelta);
      }
    }
    double minDist = dist(cars[0].current.x, cars[0].current.y, cars[1].current.x, cars[1].current.y);
    int totalSteps = (int)(30.0/kDelta);
    for (int i = 0; i < totalSteps; i++) {
        for (int j = 0; j < 2; j++) {
          calculatePositionAfterDelta(cars[j], kDelta);
        }
        double d = dist(cars[0].current.x, cars[0].current.y, cars[1].current.x, cars[1].current.y);
        if (minDist > d) {
          minDist = d;
        }
      }
           if (minDist < 19.0) {
             cout << 1 << endl;
           } else {
             cout << 0 << endl;
           }
  }
}

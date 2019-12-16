#include <iostream>
#include <algorithm>
#include <vector>
#define MAXTYPES 10000
#define MAXEACHTYPE 100000
#define MAXNUM MAXTYPES*MAXEACHTYPE
#define MAXCAP 100000
using namespace std;

struct Entry {
  int num;
  int cap;
  long long int numRun;
  long long int totalCapRun;
};

struct EntryComp {
  bool operator()(const Entry& one, const Entry& two) {
    return one.cap < two.cap;
  }
};

int main() {
  int N, M;
  while (cin >> N >> M) {
    if (N == 0 || M == 0) {
      break;
    }
    vector<Entry> C(N);
    vector<Entry> E(M);
    for (int i = 0; i < N; i++) {
      cin >> C[i].num >> C[i].cap;
    }
    for (int j = 0; j < M; j++) {
      cin >> E[j].num >> E[j].cap;
    }
    sort(C.begin(), C.end(), EntryComp());
    sort(E.begin(), E.end(), EntryComp());

    long long int numAcc = 0;
    long long int totalCapAcc = 0;
    for (int i = 0; i < N; i++) {
      C[i].totalCapRun = totalCapAcc + (C[i].cap*C[i].num);
      totalCapAcc = C[i].totalCapRun;
      C[i].numRun = numAcc + C[i].num;
      numAcc = C[i].numRun;
    }
    numAcc = 0;
    totalCapAcc = 0;
    for (int j = 0; j < M; j++) {
      E[j].totalCapRun = totalCapAcc + (E[j].cap*E[j].num);
      totalCapAcc = E[j].totalCapRun;
      E[j].numRun = numAcc + E[j].num;
      numAcc = E[j].numRun;
    }

    long long int minCut = 2*(long long int)MAXCAP*(long long int)MAXNUM;
    // Calculate the solution when
    // p > MAXCAP
    // Flow graph is Source - Cs - Es - Sink
    // p components are on the source side
    if (C[N-1].numRun > MAXCAP) {
      minCut = E[M-1].totalCapRun;
    }

    int cIndex = N-1;
    int eIndex = 0;
    for (int p = 0; p <= MAXCAP && p <= C[N-1].numRun; p++) {
      long long int cutCap = 0;
      // Find N-p lowest capacity Cs
      while (cIndex >= 0 &&
             C[cIndex].numRun - C[cIndex].num >= C[N-1].numRun - p) {
        cIndex--;
      }
      if (cIndex >= 0) {
        if (cIndex == 0) {
          cutCap += (C[N-1].numRun - p)*C[cIndex].cap;
        } else {
          cutCap += C[cIndex-1].totalCapRun +
            (C[N-1].numRun - p - C[cIndex-1].numRun)*C[cIndex].cap;
        }
      }

      // Now find the total capacity of all Es with capacity < p
      while (eIndex < M && E[eIndex].cap < p) {
        eIndex++;
      }
      if (eIndex > 0) {
        cutCap += E[eIndex-1].totalCapRun +
          (E[M-1].numRun - E[eIndex-1].numRun)*p;
      } else {
        cutCap += E[M-1].numRun*p;
      }
      if (cutCap < minCut) {
        minCut = cutCap;
      }
    }

    cout << (minCut >= C[N-1].totalCapRun) << endl;
  }
}

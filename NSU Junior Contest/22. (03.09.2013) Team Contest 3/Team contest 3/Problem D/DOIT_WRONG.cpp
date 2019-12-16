#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1000000
#define MAXP 78498

int FD[MAXN + 1] = {0};
int PR[MAXP + 1], np;

vector<int> K;
set<int> F;

typedef unsigned long long uint64;
set<uint64> X2;

struct XY{
    uint64 x, y;
};

struct XY_less{
    bool operator()(const XY& left, const XY& right) const{
        uint64 a = left.x * right.y;
        uint64 b = left.y * right.x;

        if (a < b) return true;
        if (a > b) return false;

        if (left.x < right.x) return true;
        if (left.x > right.x) return false;

        return false;
    }
};

void init(){
    PR[np = 1] = 2;

    for (int i = 3; i <= MAXN; i+=2)
        if (!FD[i]){
            PR[++np] = i;

            for (int j = 1; i * j <= MAXN; j+=2)
                FD[i * j] = np;
        }

    //cout << np << endl;
}

int nextDiv(int x){
    if (x % 2 == 0) return 1;
    return FD[x];
}

void fact(int b){
    if (b == 1){
        //cout << endl;
        return;
    }
    int pos = nextDiv(b);
    K[pos]++;
    F.insert(pos);
    //cout << PR[pos] << "*";
    fact(b / PR[pos]);
}

void go(int pos, uint64 x2, uint64 maxx2){
    X2.insert(x2);

    if (pos == MAXP + 1) return;
    uint64 z = PR[pos];

    while (x2 <= maxx2 / z){
        go(pos + 1, x2 * z, maxx2);
        z *= PR[pos];
    }

    if (z != PR[pos])
        go(pos + 1, x2, maxx2);
}

int main(){
    init();

    while (1){
        int b, n;
        cin >> b >> n;
        if (b == 0 && n == 0) break;

        K = vector<int>(np + 1, 0);
        F.clear();
        fact(b);

        uint64 x2 = 1;
        for (set<int>::iterator it = F.begin(); it != F.end(); it++){
            int pos = *it;
            K[pos] += K[pos] % 2;
            for (int k = 1; k <= K[pos]; k+=2)
                x2 *= PR[pos]; 
        }

        X2.clear();
        //cout << x2 << endl;
        go(1, x2, (uint64)b);

        set<XY, XY_less> ans;

        for (set<uint64>::iterator it = X2.begin(); it != X2.end(); it++){
            uint64 a = ((uint64)b * (uint64)b - (*it) * (*it)) / (uint64)b;
            if ((uint64)n * (*it) % (uint64)b) continue;
            XY z1;
            z1.x = a;
            z1.y = (uint64)n + (uint64)n * (*it) / (uint64)b;
            if (z1.y != (uint64)n) ans.insert(z1);

            XY z2;
            z2.x = a;
            z2.y = (uint64)n - (uint64)n * (*it) / (uint64)b;
            if (z2.y != (uint64)n) ans.insert(z2);
        }

        set<XY, XY_less>::iterator it = ans.begin();
        cout << it->x << "/" << it->y;
        it++;

        for (; it != ans.end(); it++){
            cout << " " << it->x << "/" << it->y;
        }

        cout << endl;
    }
    return 0;
}

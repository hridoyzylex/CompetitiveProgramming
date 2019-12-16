#include <cstdio>
using namespace std;

int max_fact (int x) {
    long long i;
    for (i = 2; i*i <= x; i++)
        while (x%i==0 && x > i)
            x /= i;
    return x;
}

int main() {
    int n, ret, i, x, e, y, cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf ("%d", &n);
        e = -1;
        for (i = 0; i < n; i++) {
            scanf ("%d", &x);
            y = max_fact (x);
            if (y > e) {
                e = y;
                ret = x;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}

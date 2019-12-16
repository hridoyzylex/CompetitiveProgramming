#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20005;

int N, B;
int heights [MAXN];

int solve () {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += heights [i];
        if (sum >= B)
            return i + 1;
    }
    return -1;                                      // should not happen
}

int main () {
    int cases;
    // freopen("/home/wasi/programming/nsu/ic-1/io/E.in", "r", stdin);
    scanf("%d", &cases);

    while (cases--) {
        scanf ("%d %d", &N, &B);
        for (int i = 0; i < N; i++)
            scanf ("%d", heights + i);
        sort (heights, heights + N);                   // sort in non-increasing order
        reverse (heights, heights + N);
        printf ("%d\n", solve ());
    }

    return 0;
}

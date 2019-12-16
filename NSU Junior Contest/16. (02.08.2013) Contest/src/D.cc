#include <stdio.h>

int height[50000];
int nstumps;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int i;
        scanf("%d", &nstumps);
        for (i = 0; i < nstumps; i++)
            scanf("%d", &height[i]);
        for (i = 0; i < nstumps; i++) {
            if (i > 0 && height[i-1] > height[i]) continue;
            if (i < nstumps-1 && height[i+1] > height[i]) continue;
            printf("%d\n", i+1);
        }
    }
    return 0;
}

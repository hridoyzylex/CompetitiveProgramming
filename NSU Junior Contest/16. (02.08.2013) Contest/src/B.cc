#include <stdio.h>
#include <math.h>

int coors[2000][2];	/* x,y */
int ans[2000][3];	/* cow ids */
int ncollinear;

int idcompare(int i, int j) {
    int k;
    for (k = 0; k < 3; k++) {
	if (ans[i][k] < ans[j][k]) return -1;
	if (ans[i][k] > ans[j][k]) return 1;
    }
    return 0;
}

int main () {
    int i, j, k, n, t;
    int x1,y1,  x2,y2, x3,y3, dx1,dy1, dx2,dy2;
    int cases;
    scanf("%d", &cases);
    while (cases--) {
            scanf("%d", &n);
        for (i = 0; i < n; i++)
        scanf("%d %d", &coors[i][0], &coors[i][1]);
        ncollinear = 0;
        for (i = 0; i < n; i++) {
        x1 = coors[i][0];
        y1 = coors[i][1];
        for (j = i+1; j < n; j++) {
            x2 = coors[j][0];
            y2 = coors[j][1];
            dx1 = x2 - x1;
            dy1 = y2 - y1;
            for (k = j+1; k < n; k++) {
                x3 = coors[k][0];
                y3 = coors[k][1];
            dx2 = x3 - x2;
            dy2 = y3 - y2;
            if (dy1 * dx2 == dy2 * dx1) {
                ans[ncollinear][0]  = i+1;	/* i,j,k already sorted */
                ans[ncollinear][1]  = j+1;
                ans[ncollinear][2]  = k+1;
                ncollinear++;
            }
            }
        }
        }
        printf("%d\n", ncollinear);
        for (i = 0; i < ncollinear; i++)
        printf ("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }

    return 0;
}

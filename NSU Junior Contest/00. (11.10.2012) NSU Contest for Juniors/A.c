#include<stdio.h>
#include<string.h>
int main()
{
    freopen("A.txt", "r", stdin);
    int a[10];
    int P, i, j, k, serial;
    int temp, pos;

    scanf("%d", &P);
    for(i=0; i<P; i++)
    {
        scanf("%d %d %d %d %d %d %d %d %d %d %d", &serial, &a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
        for(j=0; j<10; j++)
        {
        pos = j;
            for(k=j; k<10; k++)
            {
                if (a[k]<a[pos])
                pos = k;
            }
            temp = a[j];
            a[j] = a[pos];
            a[pos] = temp;
        }
        printf("%d %d\n", serial, a[7]);
    }
    return 0;
}

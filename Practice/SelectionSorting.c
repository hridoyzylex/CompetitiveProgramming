#include <stdio.h>
int main()
{
    int a[5] = {3,2,5,4,1};
    int i,j;
    int temp, MinPos;

    for (i=0; i<5; i++)
    {
    MinPos = i;
        for (j=i; j<5; j++)
        {
            if (a[j]<a[MinPos])
                MinPos = j;
        }
    temp = a[i];
    a[i] = a[MinPos];
    a[MinPos] = temp;
    }

    printf("%d %d %d %d %d", a[0], a[1], a[2], a[3], a[4]);


    return 0;
}

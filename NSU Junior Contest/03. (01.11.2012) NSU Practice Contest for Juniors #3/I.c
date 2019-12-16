#include <stdio.h>
#include <string.h>

int main()
{
    freopen("I.txt", "r", stdin);
    int i, N;
    double value;
    char a[5];
    char dummy[5];

    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%lf", &value);
        gets(a);

        if ((a[1]=='k')&&(a[2]=='g'))
            printf("%d %0.4lf lb\n", i+1, value*2.2046);
        if ((a[1]=='l')&&(a[2]=='b'))
            printf("%d %0.4lf kg\n", i+1, value*0.4536);
        if (a[1]=='l'&&(a[2]!='b'))
            printf("%d %0.4lf g\n", i+1, value*0.2642);
        if (a[1]=='g')
            printf("%d %0.4lf l\n", i+1, value*3.7854);
    }
    return 0;
}

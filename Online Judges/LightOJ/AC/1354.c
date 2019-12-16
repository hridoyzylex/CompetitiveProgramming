#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int a,b,c,d, w, x, y, z;
    int i, j, k, T, dec;
    char bin[37] = "";
    char garbage[2] = "";

    scanf("%d", &T);
    for (k=0; k<T; k++)
    {
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    gets(garbage);
    gets(bin);

    dec = 0;
    for (i=0, j=0; i<8; i++, j++)
    {
        dec = dec + (bin[i]-48)*pow(2,7-j);
        w = dec;
    }

    dec = 0;
    for (i=9, j=0; i<17; i++, j++)
    {
        dec = dec + (bin[i]-48)*pow(2,7-j);
        x = dec;
    }

    dec = 0;
    for (i=18, j=0; i<26; i++, j++)
    {
        dec = dec + (bin[i]-48)*pow(2,7-j);
        y = dec;
    }

    dec = 0;
    for (i=27, j=0; i<35; i++, j++)
    {
        dec = dec + (bin[i]-48)*pow(2,7-j);
        z = dec;
    }

    if((a==w)&&(b==x)&&(c==y)&&(d==z))
        printf("Case %d: Yes\n", k+1);
    else
        printf("Case %d: No\n", k+1);
    }

    return 0;
}

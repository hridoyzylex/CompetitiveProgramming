#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    char a[180];

    gets(a);

    for (i=0; a[i]==' '; i++)
    {
        for (j=i; j<179; j++)
        {
            a[j] = a[j+1];
        }
    }
    puts(a);
    return 0;
}

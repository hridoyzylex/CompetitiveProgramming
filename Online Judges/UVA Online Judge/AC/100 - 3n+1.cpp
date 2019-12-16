#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    //freopen("Input.txt", "r", stdin);
    int i,j,k,a,b, cycle, cycleMax;
    long long n;

    while ( scanf ("%d %d", &i, &j) != EOF )
    {
        a = i;
        b = j;
        if ( i > j ) swap (i, j);

        cycleMax = 0;

        for(k=i; k<=j; k++)
        {
            n = i;
            cycle = 1;

            while ( n > 1 )
            {
                if ( n % 2 == 1 )
                    n = 3 * n + 1;
                else
                    n /= 2;

                cycle++;
            }
            if ( cycle >= cycleMax )
                cycleMax = cycle;

            i++;
        }

        printf ("%d %d %d\n", a, b, cycleMax);
    }
    return 0;
}

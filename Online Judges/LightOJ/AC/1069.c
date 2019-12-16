#include <stdio.h>

int main()
{
    int T, i;
    int myPos, liftPos, time;

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        scanf("%d %d", &myPos, &liftPos);

        time  = (abs(liftPos-myPos))*4 + (3+5+3) + (myPos*4) + (3+5);

        printf("Case %d: %d\n", i+1, time);

    }
    return 0;
}

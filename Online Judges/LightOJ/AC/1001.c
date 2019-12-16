#include <stdio.h>
int main()
{
    int T, i, n;

    scanf("%d", &T);

    for (i=0; i<T; i++){
    scanf("%d", &n);
        if (n<=10)
            printf("%d %d\n", 0, n);
        else
            printf("%d %d\n", 10, n-10);
    }
    return 0;
}

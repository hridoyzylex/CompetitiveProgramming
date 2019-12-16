#include <stdio.h>
#include <string.h>

int main()
{
    freopen ("C.txt", "r", stdin);
    long long i,j,pos,t,counter = 0;
    long long N, B, H, sum = 0;
    int a[20000];

    scanf("%lld %lld", &N, &B);
    for (i=0; i<N; i++)
    {
        scanf("%lld", &H);
        a[i] = H;
    }
    for (i=0; i<N-1; i=i+1){
    pos=i;
        for (j=i; j<N; j=j+1){
            if (a[j]<a[pos])
                pos = j;
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }

    sum = 0;
    for (i=N-1; sum<B; i--)
    {
            sum = sum + a[i];
            counter++;
    }
    printf("%lld", counter);

    return 0;
}

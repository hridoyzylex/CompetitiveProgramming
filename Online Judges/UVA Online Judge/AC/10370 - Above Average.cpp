#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i, C,N,total,average, aboveAvg;
    int a[1005];

    cin>>C;
    while(C--)
    {
        total=average=aboveAvg=0;

        cin>>N;
        for(i=0; i<N; i++)
        {
            cin>>a[i];
            total = total + a[i];
        }
        average = total/N;

        for(i=0; i<N; i++)
        {
            if(a[i]>average)
                aboveAvg++;
        }

        printf("%0.3f%%\n", (float)aboveAvg/N*100);
    }
    return 0;
}

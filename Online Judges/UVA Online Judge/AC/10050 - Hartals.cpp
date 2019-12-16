#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int T,N,P,h,i,j,k,count;
    int Days[3655];

    cin>>T;
    for(i=0; i<T; i++)
    {
        count = 0;
        cin>>N;
        for(j=0;j<=N; j++)
            Days[j] = 0;

        cin>>P;
        for(j=0; j<P; j++)
        {
            cin>>h;
            for(k=h; k<=N; k=k+h)
                Days[k] = 1;
        }

        for(j=6; j<=N; j=j+7)
        {
            Days[j] = 0;
            Days[j+1] = 0;
            Days[j+7] = 0;

        }

        for(j=1; j<=N; j++)
        {
            if(Days[j]==1)
                count++;
        }
        cout<<count <<endl;
    }

    return 0;
}

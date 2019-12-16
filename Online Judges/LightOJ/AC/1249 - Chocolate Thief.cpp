#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

struct thief
{
    char name[25];
    int vol;
};

bool cmp(thief x, thief y)
{
    return x.vol < y.vol;
}
int main()
{
    //freopen("input.txt", "r", stdin);

    int i,j,T,n,L,H,W;
    thief th[105];

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        for(j=0; j<n; j++)
        {
            scanf("%s %d %d %d", &th[j].name, &L, &W, &H);
            th[j].vol = L*W*H;
        }

        sort(th, th+n, cmp);

        if(th[n-1].vol > th[0].vol)
            cout<<"Case " <<i+1 <<": " <<th[n-1].name <<" took chocolate from " <<th[0].name;
        else
            cout<<"Case " <<i+1 <<": no thief";
        cout<<endl;
    }


    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct st
{
    int time;
    int teamID;
    char problem;
    string verdict;
};
bool cmp(st x,st y)
{
    return x.time<y.time;
}

int main()
{
    freopen("H.txt", "r", stdin);

    int i,j,k,n,t,m, tim, team;
    char prob;
    string ver;
    char dummy[3];
    st s[1005];

    cin>>n>>t>>m;
    for(i=0; i<m; i++)
    {
        cin>>tim>>team;
        scanf("%c", &dummy[0]);
        cin>>prob>>ver;
        cout<<tim <<endl <<team <<endl <<prob <<endl <<ver <<endl;

        if(ver=="Yes")
        {
            s[i].time = tim;
            s[i].teamID = team;
            s[i].problem = prob;
            s[i].verdict = ver;
        }

        cout<<s[0].time <<" " <<s[0].teamID <<" " <<s[0].problem <<" " <<s[0].verdict<<endl;

        sort(s, s+m, cmp);


    }


    return 0;
}

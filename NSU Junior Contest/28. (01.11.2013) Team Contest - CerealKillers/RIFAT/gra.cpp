#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define pb push_back
#define ms(ar,val) memset(ar,val,sizeof(ar))
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)
#define hi 110
#define top front
using namespace std;
int r,c,gr,gc,lr,lc;
bool vis[hi][hi];
int x[]= {1,2,2,1,-1,-2,-2,-1};
int y[]= {2,1,-1,-2,-2,-1,1,2};
bool f1(int row)
{
    return (row>0 &&row<=r);
}
bool f2(int row)
{
    return (row>0 &&row<=c);
}
int main()
{
    //Read("in.txt");
    while(scanf("%d%d%d%d%d%d",&r,&c,&gr,&gc,&lr,&lc)==6)
    {
        queue <int> row,col,q;
        q.push(0);
        bool paisi=0;
        row.push(gr);
        col.push(gc);
        while(!q.empty())
        {
            int r1=row.top(),c1=col.top(),w=q.top();
            row.pop();
            col.pop();
            q.pop();
            if(r1==lr && lc==c1)
            {
                paisi=1;
                printf("%d\n",w);
                break;
            }
            vis[r1][c1]=1;
            for(int i=0; i<8; i++)
            {
                if(f1(r1+x[i]) && f2(c1+y[i]) && vis[r1+x[i]][c1+y[i]]==0 )
                {
                    q.push(w+1);
                    row.push(r1+x[i]);
                    col.push(c1+y[i]);
                    vis[r1+x[i]][c1+y[i]]=1;
                }
            }
        }
        if(!paisi)printf("impossible\n");//cout<<"impossible"<<endl;
        for(int i=0;i<r+1;i++)
            for(int j=0;j<c+1;j++)
                vis[i][j]=0;
    }

    return 0;
}

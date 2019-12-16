#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    long long m,p,l,e,r,s,n,bff;
    while(cin>>m>>p>>l>>e>>r>>s>>n)
    {
        //cerr<<m<<" "<<p<<" "<<l<<e<<" "<<r<<" "<<s<<" "<<n<<endl;
        for(int i=0;i<(int)n;i++)
        {
            //cerr<<i<<" :"<<m<<" "<<p<<" "<<l<<endl;
            bff = p/s;
            p = l/r;
            l = m*e;
            m = bff;
        }
        printf("%lld\n",m);
    }
    return 0;
}


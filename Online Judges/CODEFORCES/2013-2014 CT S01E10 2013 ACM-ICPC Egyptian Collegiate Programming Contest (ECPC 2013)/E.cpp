#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);
#define ms(ar,val) memset(ar,val,sizeof(ar))
#define lp(i,s,n) for(int i=s;i<n;i++)
#define rp(i,n) lp(i,0,n)
#define pb push_back
#define LL long long
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)
#define st(N,pos) (sts[N]=sts[N] | (1<<pos))
#define check(N,pos) ((bool)(sts[N] & (1<<pos)))
#define i_s(num)  static_cast<ostringstream*>( &(ostringstream() << num) )->str();
#define hi 10
using namespace std;

int main()
{
     #if defined( rifat_pc )
        //Write("out.txt");
        //Read("ghanophobia.in");
    #endif
    Read("ghanophobia.in");
    int t,cnt=1,a,b,e,g;
    cin>>t;

    while(t--)
    {
        e=1,g=6;
        scanf("%d:%d",&a,&b);
        e+=a;
        g+=b;
        printf("Case %d: ",cnt++);
        if(e>g)printf("YES\n");
        else if(e<g)printf("NO\n");
        else if(e==g && b==1)printf("PENALTIES\n");
        else if(b>1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

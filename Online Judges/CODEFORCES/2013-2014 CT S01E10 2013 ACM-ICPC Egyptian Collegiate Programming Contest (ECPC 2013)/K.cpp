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
#define hi 110
using namespace std;
int n,ar[hi];
deque <int> d;
int main()
{
#if defined( rifat_pc )
    //Write("out.txt");
    //Read("cubes.in");
#endif
    Read("cubes.in");
    int t,cnt=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rp(i,n)scanf("%d",&ar[i]);
        sort(ar,ar+n);

        rp(i,n)
        {
            if(i%2==1)
            {
                d.push_front(ar[i]);
            }
            else
            {
                d.push_back(ar[i]);
            }
        }
        printf("Case %d:\n",cnt++);
        bool m=0;

        while(!d.empty())
        {
            if(n%2)
            {
                if(m)printf(" %d",d.front());
                else
                {
                    m=1;
                    printf("%d",d.front());
                }
                d.pop_front();
            }
            else
            {
                if(m)printf(" %d",d.back());
                else
                {
                    m=1;
                    printf("%d",d.back());
                }
                d.pop_back();
            }
        }
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define i_s(num) static_cast<ostringstream*>(&(ostringstream()<<num))->str()
#define pb push_back
#define Read(x) freopen(x,"r",stdin)

unsigned long long ar[100];
unsigned long long dp(int i)
{
    if(i==0)return 1;
    if(i<0)return 0;
    if(ar[i]!=-1)return ar[i];
    return ar[i]=dp(i-2)+dp(i-1);
}
int x=0;

unsigned long long a;
vector <unsigned long long> v1,v2;
int main()
{
    int t,cnt=1,ans=0;
    //Read("in.txt");
    ar[0]=0;
    memset(ar,-1,sizeof(ar));
    for(int i=95; i>0; i--)dp(i);
    while(cin>>a)
    {
        unsigned long long w=a;
        int k=93;

        for(int i=1; i<k; i++)
        {
            if(a<=0)break;
            if(a==ar[i])
            {
                a-=ar[i];
                v1.pb(i);
                v2.pb(ar[i]);
                k=i-1;
                break;
            }
            if(ar[i]>a)
            {

                a-=ar[i-1];
                v1.pb(i-1);
                v2.pb(ar[i-1]);
                k=i-1;
                i=0;
                continue;
            }
            if(i+1==k)
            {
                a-=ar[i-2];
                v1.pb(i-2);
                v2.pb(ar[i-2]);
                k=i-2;
            }

        }
        cout<<w<<endl;
        for(int i=0; i<v1.size(); i++)printf("%llu ",v1[i]);
        cout<<endl;
        for(int i=0; i<v2.size(); i++)printf("%llu ",v2[i]);
        cout<<endl<<endl;
        v1.clear();
        v2.clear();
    }
    return 0;
}




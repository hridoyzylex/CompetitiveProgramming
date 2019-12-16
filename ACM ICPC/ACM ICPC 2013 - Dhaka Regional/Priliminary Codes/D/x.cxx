#include<iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>


using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair < int, int > pii;
typedef vector< pii > vii;

#define PI (2*acos(0))
#define EPS 1e-9
#define PB push_back
#define MAX max_element
#define MIN min_element
#define BS binary_search
#define MP make_pair
#define LN length()
#define SZ size()

#define ASZ(x) sizeof(x)/sizeof(__typeof(x[0]))
#define ALL(x) x.begin(), x.end()
#define LC(x,y) lexicographical_compare(ALL(x),ALL(y))
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define FOR(i,a,b) for(int i(a), _e(b); i<=_e; i++)
#define FORD(i,a,b) for(int i(a), _e(b); i>=_e; i--)
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )
#define F first
#define S second

pair<set<int>::iterator,bool> RET;// for checking if the item has been aded to a set or not

int w;
vi v;

int func()
{
    sort(v.begin(),v.end());
    // joto pari niye nilam
    int res=v[0];
    v[1]-=v[0];
    v[2]-=v[0];
    v[0]=0;

    // kom ta color kore joto pari nilam
    if(v[1]<=w)
    {
        w-=v[1];
        v[2]-=v[1];
        res+=v[1];
        v[1]=0;
    }
    else
    {
        res+=w;
        return res;
    }

    if(v[2]*2<=w){
        res+=v[2];
        w-=v[2]*2;
    }else{
        res+=w/2;
        return res;
    }

    res+=w/3;

    return res;

}

int main()
{
#ifdef _orfi_
    //freopen("in.txt","rt",stdin);
#endif
    v.resize(3);
    int T,cas=0;
    scanf(" %d",&T);
    while(T--)
    {
        REP(i,3)
        {
            scanf(" %d",&v[i]);
        }
        scanf(" %d",&w);

        printf("Case %d: %d\n",++cas,func());
    }

    return 0;
}

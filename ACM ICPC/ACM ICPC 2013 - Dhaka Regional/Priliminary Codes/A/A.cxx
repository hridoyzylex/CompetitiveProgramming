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

int n,m, init;
int candies[10];
bool edge[10][10];

int memo[10][1048580];

void printIn(int init){
    FORD(i,(n*2)-1,0){
        cerr<<((init>>i)&1);
    }
    cerr<<endl;
}

inline void input(){
    int x,y;
    init=0;
    SET(memo,128);
    SET(edge,false);
    SET(candies,0);
    scanf(" %d %d",&n,&m);
    REP(i,n){
        scanf(" %d",&x);
        if(x==1){
            init|=1<<(i*2+1);
        }
    }

    //printIn(init);

    REP(i,n){
        scanf(" %d",&x);
        candies[i]=x;
    }

    REP(i,m){
        scanf(" %d %d",&x,&y);
        edge[x-1][y-1]=true;
        edge[y-1][x-1]=true;
    }
}


int dp(int nod, int mask){

    if(memo[nod][mask]>=0){
        return memo[nod][mask];
    }


    int fl,new_mask,res=0, w=candies[nod];

    fl=(mask>>(nod*2))&3;

    if(fl==3){ // cannot visit this node
        return 0;
    }

    if(fl==1){//visited once
        w=0;
        new_mask= mask|(1<<(nod*2+1));
    }else{// unvisited
        new_mask=mask|(1<<(nod*2));
    }

    REP(i,n){
        if(edge[nod][i]){// path to i true
            res=max(res,dp(i,new_mask));
        }
    }

    return memo[nod][mask]=(w+res);

}


int main(){
    #ifdef _orfi_
    //freopen("in.txt","rt",stdin);
    #endif
    int T,cas=0,r;
    scanf(" %d",&T);
    while(T--){
        r=0;
        input();
        REP(i,n){
            r=max(r,dp(i,init));
        }
        printf("Case %d: %d\n",++cas,r);
    }

    return 0;
}

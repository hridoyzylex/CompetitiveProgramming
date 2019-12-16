#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define pb push_back
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)

using namespace std;

int main()
{
    //Read("A.txt");
    int n,i,j,flag=0;
    int choco[10];
    int juice[10];

    cin>>n;

    for(i=0; i<8; i++)
    {
        cin>>choco[i] >>juice[i];
    }

    /*for(i=0; i<8; i++)
        cout<<choco[i] <<" ";
        cout<<endl;
    for(i=0; i<8; i++)
        cout<<juice[i] <<" ";*/

    for(i=0, j=1; i<8; i=i+2, j++)
    {
        if(min(choco[i], juice[i]) + min(choco[i+1], juice[i+1]) <= n)
        {
            cout<<j <<" " <<min(choco[i], juice[i]) <<" " <<n-min(choco[i], juice[i]);
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"-1";

    return 0;
}


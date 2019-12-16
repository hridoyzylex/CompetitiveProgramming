#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#define pb push_back
#define Read(x) freopen(x,"r",stdin)
using namespace std;
string  b(int n)
{
    string s;
    while(n)
    {
        int r=n%2;
        if(r)s+="1";
        else s+="0";
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
string f(int n)
{
    if(n==1)return "0";
    string s=b(n);
    string s1=f(s.size()-1);
    return s1+s;

}
int main()
{

    //Read("in.txt");
    int n;
    while(cin>>n)
    {
        if(!n)break;
        cout<<f(n)<<endl;
    }


    return 0;
}



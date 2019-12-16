#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

bool check(string a, string b)
{
    if(b.size() < a.size())
        return false;

    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
            return false;
    }

    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,T,n;
    bool b;
    string s[10005];

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        for(j=0; j<n; j++)
        {
            cin>>s[j];
        }

        b = true;
        sort(s, s+n);

        for(j=0; j<n-1; j++)
        {
            if(check(s[j],s[j+1]))
            {
                b=false;
                break;
            }
        }

        if(b)
            cout<<"Case " <<i+1 <<": YES" <<endl;
        else
            cout<<"Case " <<i+1 <<": NO" <<endl;

    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("E.txt", "r", stdin);

    string s[200],p[100],r;
    int n,k,q;
    while(cin>>n)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            getline(cin,s[i]);
            getline(cin,p[i]);
        }
        cin>>q;
        getchar();
        while(q--)
        {
            getline(cin,r);
            for(int i=0;i<n;i++)
            {
                if(s[i]==r)
                {
                    cout<<p[i]<<endl;
                    break;
                }
            }
        }
    }
 return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

#define ll long long
#define pb push_back
#define ms(ar,val) memset(ar,val,sizeof(ar))
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)
using namespace std;
string s,d;
int main()
{

    int t;
    Read("in.txt");
    while(cin>>t)
    {
        scanf(" ");
        getline(cin,d);
        for(int i=0; i<t; i++)
        {

            //scanf("%s",s.c_str());
            string ans;
            getline(cin,s);
            //std::size_t
            unsigned found = s.find(d);
            //cout<<found<<endl;
            while(found!=std::string::npos)
            {
                s.erase(found,d.size());
                if(found-d.size()+2>=0)
                {

                    ans+=s.substr(0,found-d.size()+2);
                    s=s.substr(found-d.size()+2);
                    cout<<ans<<endl;

                }
                found=s.find(d);
            }
            cout<<s<<"\n";
        }
    }

    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int N,T;

    while(scanf("%d",&N)!=EOF)
    {
        string ans;
        int impossible=0;
        if(N>=10)
        {
            for(int i=9;i>1&&N>=10;i--)
            {
                while(!(N%i))
                {
                    ans+=(i+'0');
                    N/=i;
                }
            }
            if(N/10)
                impossible=1;

        }
        reverse(ans.begin(),ans.end());

        if(N==0)
            cout<<"10" <<endl;
        else if(!impossible)
            cout<<N<<ans<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}

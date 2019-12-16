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
int ar[4][14];
int f1(char c)
{
    if(c=='c')return 0;
    if(c=='d')return 1;
    if(c=='h')return 2;
    if(c=='s')return 3;
}
int f2(char c)
{
    if(isdigit(c))
    {
        return c-'0';
    }
    if(c=='A')return 1;
    if(c=='X')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;


}
int p[20];
int main()
{

    Read("in.txt");
    int t;
    while(cin>>t)
    {
        string s;
        ms(ar,0);
        for(int i=0; i<5; i++)
        {
            cin>>s;
            ar[f1(s[1])][f2(s[0])]=1;
            cout<<f1(s[1])<<" "<<f2(s[0])<<endl;

        }

        for(int i=0; i<t; i++)
        {
            int x1,x2,y1,y2;
            cin>>s;
            bool paisi=0;
            x1=f1(s[1]);
            x2=f2(s[0]);
            ar[x1][x2]=1;
            cin>>s;
            y1=f1(s[1]);
            y2=f2(s[0]);
            ar[y1][y2]=1;
//            for(int j=0; j<4; j++)
//            {
//                for(int k=1; k<13; k++)cout<<ar[j][k]<<" ";
//                cout<<endl;
//            }
            //royal flush
            if(!paisi)
            for(int j=0; j<4; j++)
            {
                for(int k=1; k<10; k++)
                {
                    if(ar[j][k]==1 && ar[j][k+1]==1 && ar[j][k+2]==1 && ar[j][k+3]==1 && ar[j][k+4]==1)
                    {
                        paisi=1;
                        p[t]=9;
                        cout<<"royal flush"<<endl;
                        break;
                    }
                }
                if(!paisi)
                if(ar[j][10]==1 && ar[j][11]==1 && ar[j][12]==1 && ar[j][13]==1 && ar[j][1]==1)
                {
                    paisi=1;
                    p[t]=9;
                    cout<<"royal flush"<<endl;
                    break;
                }

            }
            if(!paisi)
            for(int j=1; j<14; j++)
            {
                if(ar[0][j] && ar[1][j] && ar[2][j] && ar[3][j]  )
                {
                    paisi=1;
                    p[t]=8;
                    cout<<"pooker"<<endl;
                    break;
                }
            }
            if(!paisi)
            for(int j=1; j<14; j++)
            {
                int sum=ar[3][j]+ar[2][j]+ar[1][j]+ar[0][j];
                if(sum>2)
                {
                    for(int k=1; k<14; k++)
                    {
                        if(k==j)continue;
                        int sum2=ar[3][k]+ar[2][k]+ar[1][k]+ar[0][k];
                        if(sum2>1)
                        {
                            paisi=1;
                            p[t]=7;
                            cout<<"full house"<<endl;
                            break;
                        }
                    }
                }
            }
            if(!paisi)
            for(int j=0; j<4; j++)
            {
                int sum=0;
                for(int k=1; k<14; k++)
                {
                    sum+=ar[j][k];
                }
                if(sum>=5)
                {
                    p[t]=5;
                    cout<<"flush"<<endl;
                    break;
                }

            }
            int ri[14];
            ms(ri,0);
            for(int j=1; j<14; j++)ri[j]=ar[0][j]+ar[1][j]+ar[2][j]+ar[3][j];
            if(!paisi)
            for(int k=1; k<10; k++)
            {
                if(ri[k] && ri[k+1] && ri[k+2] && ri[k+3] && ri[k+4])
                {
                    paisi=1;
                    p[t]=4;
                    cout<<"straight"<<endl;
                    break;
                }
            }
            if(!paisi)
            if(ri[10] && ri[11] && ri[12] && ri[13] && ri[1])
            {
                paisi=1;
                p[t]=4;
                cout<<"straight"<<endl;
                break;
            }
            if(!paisi)
            for(int j=1;j<14;j++)
            {
                if(ri[j]>=3)
                {
                    paisi=1;
                    p[t]=3;
                    cout<<"three"<<endl;
                    break;
                }
            }
            if(!paisi)
            for(int j=1;j<14;j++)
            {
                if(ri[j]>=2)
                {
                    for(int k=j+1;k<14;k++)
                    {

                        if(ri[j]>=2)
                        {
                            p[t]=2;
                            paisi=1;
                            cout<<"two pair"<<endl;
                            break;
                        }
                    }
                }
            }
            if(!paisi)
            for(int j=1;j<14;j++)
            {
                if(ri[j]>=2)
                {
                    paisi=1;
                    p[t]=1;
                    cout<<"pair"<<endl;
                    break;
                }
            }

            ar[x1][x2]=0;
            ar[y1][y2]=0;

        }


    }

    return 0;
}


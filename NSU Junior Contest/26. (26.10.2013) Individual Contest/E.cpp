#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a,b;
    int i,j,k;
    char Opp[2];
    char dummy[5];

    for(i=0; Opp[0]!='E'; i++)
    {
        cin>>a;
        scanf("%c", &dummy[0]);
        scanf("%c", &Opp[0]);
        scanf("%c", &Opp[1]);
        cin>>b;

        //cout<<a <<" " <<Opp[0] <<" " <<Opp[1] <<b<<endl;

        if(Opp[0]=='>' && Opp[1]==' ')
        {
            if(a>b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='>' && Opp[1]=='=')
        {
            if(a>=b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='<' && Opp[1]==' ')
        {
            if(a<b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='<' && Opp[1]=='=')
        {
            if(a<=b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='=' && Opp[1]=='=')
        {
            if(a==b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='!' && Opp[1]=='=')
        {
            if(a!=b)
                cout<<"Case " <<i+1 <<": true" <<endl;
            else
                cout<<"Case " <<i+1 <<": false" <<endl;
        }

        else if(Opp[0]=='E')
            break;
    }


    return 0;
}

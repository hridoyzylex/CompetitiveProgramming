#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);
    int i,j,k,n,q,p,counterLeft, counterRight;
    string a[105];
    string Left;
    string Right;

    char x[5];

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        a[i] = x;
    }

    cin>>q;
    for(i=0; i<q; i++)
    {
        counterLeft = 0;
        counterRight = 0;

        cin>>p;

        if(a[p-1] != "?")
        {
            cout<<a[p-1] <<endl;
        }

        else
        {
            for(j=p-2; j>0; j--)
            {
                if(a[j]=="?")
                    counterLeft++;
                else
                {
                    Left = a[j];
                    break;
                }
            }

            for(j=p; j<n; j++)
            {
                if(a[j]=="?")
                    counterRight++;
                else
                {
                    Right = a[j];
                    break;
                }
            }
            if(p==1)
            {
                if(a[p-1]=="?")
                {
                    counterLeft = 105;
                }
            }

            if(p==n)
            {
                if(a[p-1]=="?")
                {
                    counterRight = 105;
                }
            }

            if(Left=="")
                counterLeft = 105;
            if(Right=="")
                counterRight = 105;


            if(counterLeft==counterRight)
                cout<<"middle of " <<Left <<" and " <<Right <<endl;
            else if(counterLeft > counterRight)
            {
                for(k=0; k<counterRight+1; k++)
                    cout<<"left of ";
                cout<<Right <<endl;
            }
            else
            {
                for(k=0; k<counterLeft+1; k++)
                    cout<<"right of ";
                cout<<Left <<endl;
            }
        }
    }

    return 0;
}

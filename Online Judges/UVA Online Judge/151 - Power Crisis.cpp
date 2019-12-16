#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,j,m,N,counter,count;
    int a[105];

    while(cin>>N && N!=0)
    {
        for(i=0; i<105; i++)        //to initialize the array with 0
            a[i] = 0;

        m=5;
        a[1]=1;
        counter=1;
        count = 0;

        for(j=2; counter!=N; j++)
        {
            if(a[j]==0)
            {
                a[j]=1;
                count++;
            }
            if(j==N)
            {
                j=1;
            }
            if(count==m)
            {
                counter++;
                count = 0;
                cout<<j <<" ";
            }
        }



    }

    return 0;
}

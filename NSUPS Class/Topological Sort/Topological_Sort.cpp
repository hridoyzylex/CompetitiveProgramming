#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);

    int m,n,x,y;
    int i,j,k,l,sum=1;
    int TOPSORT[100][100];
    int arr[4] = {0,0,0,0};
    int vis[4] = {0,0,0,0};

    cin>>m>>n;

    for(i=0; i<m; i++)              //To initialize all values to 0
        for(j=0; j<n; j++)
            TOPSORT[i][j] = 0;

    for(i=0; i<n; i++)              //To mark the graph
    {
        cin>>x>>y;
        TOPSORT[x][y] = 1;
    }

    for(i=0; i<m; i++)              //To print all the values
    {
        for(j=0; j<n; j++)
            cout<<TOPSORT[i][j] <<" ";
        cout<<endl;
    }
    cout<<endl;


    for(i=0; i<n; i++)              //arr[] stores the number things this particular item depends on
    {
        for(j=0; j<n; j++)
        {
            if(TOPSORT[i][j] == 1)
                arr[j] = arr[j] + 1;
        }
    }

    //done checking


    while(sum!=0){
    sum = 0;
    for(i=0; i<n; i++)
    {
        if (arr[i]==0 && vis[i]==0)
        {
            cout<<i <<" ";
            vis[i] = 1;

            for(j = 0; j<m; j++)
            {
                if(TOPSORT[i][j]==1)
                {
                    arr[j]--;
                }
            }
        }
        sum = sum + arr[i];
    }
    }

    return 0;
}

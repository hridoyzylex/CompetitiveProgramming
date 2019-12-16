#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool myfunction (int a, int b)
{
    return (a>b);
}

int main()
{
    //freopen("G.txt", "r", stdin);
    int i,j,k,l,n,command, value;
    int a[1005];
    int b[1005];
    int c[1005];
    int d[1005];

    int queueFlag, pQueueFlag, stackFlag;

    while(scanf("%d", &n) != EOF)
    {
        for(i=0,j=0,k=0; i<n; i++)
        {
            cin>>command >>value;

            d[i] = command;

            if(command==1)
            {
                a[j]=value;
                j++;
            }
            else
            {
                b[k]=value;
                k++;
            }
        }

        /*for(i=0; i<j; i++)
            c[i] = a[i];

        sort(c, c+j, myfunction);
        */

        for(i=0; i<n; i++)
            c[i]=-1;

        queueFlag = 1;
        pQueueFlag = 1;
        stackFlag = 1;

        //for Queue
        for(i=0; i<k; i++)
        {
            if(a[i]!=b[i])
                queueFlag = 0;
        }

        //for Priority Queue
        for(i=0,l=0; i<n; i++)
        {
            if(d[i]==1)
            {
                c[i]=a[i];
                sort(c, c+j, myfunction);
            }
            if(d[i]==2)
            {
                if(c[l]!=b[l])
                {
                    pQueueFlag = 0;
                    c[l]=-1;
                    l++;
                }
                sort(c, c+j, myfunction);
            }
        }

        //for Stack
        for(i=0; i<k; i++)
        {
            if(a[k-i-1]!=b[i])
                stackFlag = 0;
        }

        //cout<<queueFlag <<" " <<pQueueFlag <<" " <<stackFlag <<endl;
        if(queueFlag && !pQueueFlag && !stackFlag)
            cout<<"queue" <<endl;

        else if(!queueFlag && !pQueueFlag && stackFlag)
            cout<<"stack" <<endl;

        else if(!queueFlag && pQueueFlag && !stackFlag)
            cout<<"priority queue" <<endl;

        else if(queueFlag && pQueueFlag && !stackFlag)
            cout<<"not sure" <<endl;
        else if(!queueFlag && pQueueFlag && stackFlag)
            cout<<"not sure" <<endl;
        else if(queueFlag && !pQueueFlag && stackFlag)
            cout<<"not sure" <<endl;
        else if(queueFlag && pQueueFlag && stackFlag)
            cout<<"not sure" <<endl;

        else
            cout<<"impossible" <<endl;

    }
    return 0;
}

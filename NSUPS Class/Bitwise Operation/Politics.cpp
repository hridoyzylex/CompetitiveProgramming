#include <iostream>
using namespace std;

int main()
{

    int i, j, k;
    int sum, maxSum = 0;
    int a[4];


    int arr[4][4] = {{  0,    -100,   150,    5000  },
                     {-100,   0,      250,    2500  },
                     {150,    250,    0,      10000 },
                     {5000,   2500,   10000,  0     }};

    for(i=1; i<=15; i++)
    {
        sum =0;

        for(int k=0; k<4; k++)
            a[k] = 0;

        for(j=0; j<4; j++)
        {
            if( i&(1<<j) )
            {
                a[j] = 1;
            }

        }

        for(int i=0; i<4; i++)
        {
            if(a[i] == 1)
            {
                for(int j=i+1; j<4; j++)
                {
                    if(a[j] == 1)
                    {
                        sum = arr[i][j] + sum;
                    }
                }
            }
        }
        if(sum>maxSum)
            maxSum = sum;

    }
        cout<<maxSum;

    return 0;
}

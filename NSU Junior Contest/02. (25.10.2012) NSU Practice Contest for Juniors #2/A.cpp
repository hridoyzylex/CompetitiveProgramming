#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int i,j,k;
    int a, b;
    int sum, counter;

    cin>>a>>b;

    for(i=0; (a!=0)&&(b!=0); i++)
    {
        counter = 0;
        for (j=a; j+1<b; j++)
        {
            if (sqrt(j+1)==floor(sqrt(j+1)))
            {
                sum = 1;
                for (k=2; sum<=j; k++)
                {
                    sum = sum + k;
                    if (j==sum)
                    {
                        counter = counter + 1;
                        break;
                    }
                }
            }
        }
    cout<<"Case " <<i+1 <<": " <<counter <<endl;

    cin>>a>>b;
    }
    return 0;
}

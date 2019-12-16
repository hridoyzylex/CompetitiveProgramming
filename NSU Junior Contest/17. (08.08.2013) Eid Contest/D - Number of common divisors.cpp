#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("D.txt", "r", stdin);
    int T,i,j,k,x,y;
    int a,b,temp,counter;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        counter = 0;

        /*if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }*/

        x=a, y=b;

        while (y%x!=0)
        {
            temp=y%x;
            y=x;
            x=temp;
        }

        //cout<<x<<" ";

        /*if((a%2!=0) || (b%2!=0))
        {
            for(j=1; j<=x/2; j=j+2)
            {
                if( a%j==0 && b%j==0 )
                    counter++;
            }
        }

        else
        {
            for(j=1; j<=x/2; j++)
            {
                if( a%j==0 && b%j==0 )
                    counter++;
            }
        }*/

        for(int i=1; i<= x/2; i++)
        {
            if(x%i==0)
                counter++;
        }

        printf("%d \n", counter+1);
    }
    return 0;
}

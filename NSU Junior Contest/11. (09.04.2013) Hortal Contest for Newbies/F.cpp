#include <iostream>
#include <stdio.h>
using namespace std;

int binary[32];

void DecToBin(int n)
{
    int i,j,num=n;


    for(i=0; num>0; i++)
    {
        binary[i] = num%2;
        num = num / 2;
    }

    for(j=i-1; j>=0; j--)
        cout<<binary[j];

    cout<<endl;
}

int Power(int a, int b)
{
    int i;
    int total = 1;

    for(i=0; i<b; i++)
    {
        total = total*a;
    }

    return total;
}


int main()
{
    //freopen("Input.txt", "r", stdin);
    int i,j,T,num,a,b;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>num;
        if (num==1)
            cout<<0<<endl<<1<<endl;
        else
        {
            a = Power(2,num-1);
            b = Power(2, num) - 1;

            for(j=a; j<=b; j++)
            {
                DecToBin(j);
            }
        }
    }

    return 0;
}

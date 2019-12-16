#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
long long Power(int a, int b);
long long itob(long long n);

long long itob(long long n)
{
    int i,j,k,temp,onuroy=0;
    char s[64];

    for (i=0; n!=0; i++)
    {
        s[i] = n%2 + '0';
        n = n/2;
    }
    s[i] = '0';
    i++;
    s[i] = '\0';

    for(j=0; j<i/2; j++)
    {
        temp = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = temp;

    }

    next_permutation(s, s+i);

    for(j=i-1,k=0; j>=0; j--, k++)
    {
        onuroy = onuroy + ((s[j] - 48)*Power(2,k));
    }

    return onuroy;
}

long long Power(int a, int b)
{
    long long i=0;
    long long result = 1;

    while(i<b)
    {
        result = result*a;
        i++;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,T,N;
    int Onu;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>N;
        Onu = itob(N);
        cout<<"Case " <<i+1 <<": " <<Onu <<endl;

    }

    return 0;
}

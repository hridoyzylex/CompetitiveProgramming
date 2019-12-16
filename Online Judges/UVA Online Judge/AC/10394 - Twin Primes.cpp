#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

bool prime[20000010];
int tPrime[20000010];

void seive()
{
    prime[0] = prime[1] = false;
    int n = sqrt(20000010);
    for(int i=2; i<=n; i++)
    {
        if(prime[i]!=false)
        {
            for(int j=2*i ; j<=20000010; j=j+i)
            {
                prime[j] = false;
            }
        }
    }
}

void twin_prime()
{
    int i,j;
    for(i=3, j=1; i<=20000010; i++)
    {
        if(prime[i] && prime[i+2])
        {
            tPrime[j] = i;
            j++;
        }
    }
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    int n;
    memset(prime, 1, sizeof(prime));
    seive();
    twin_prime();
    while(scanf("%d", &n)==1)
    {
        cout<<"(" <<tPrime[n] <<", " <<tPrime[n]+2 <<")" <<endl;
    }

    return 0;
}

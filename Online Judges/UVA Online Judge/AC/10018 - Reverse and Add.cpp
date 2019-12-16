#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long ReverseInt(long long num)
{
    long long remainder=0,reverse=0;
    while(num!=0)
    {
        remainder=num%10;
        num=num/10;
        reverse=reverse*10+remainder;
    }
    //cout<<reverse;
    return reverse;
}

int main()
{
    //freopen("Input.txt", "r", stdin);

    long long i, n, num, counter;

    cin>>n;
    for(i=0; i<n; i++)
    {
        counter = 0;
        cin>>num;

        while(num!=ReverseInt(num))
        {
            num = num + ReverseInt(num);
            counter++;
        }
        cout<<counter <<" " <<num <<endl;
    }

    return 0;
}

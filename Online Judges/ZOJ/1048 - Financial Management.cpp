#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    float amount, total = 0;

    for(i=0; i<12; i++)
    {
        cin>>amount;
        total+=amount;
    }

    cout<<"$" <<total/12 <<endl;


    return 0;
}


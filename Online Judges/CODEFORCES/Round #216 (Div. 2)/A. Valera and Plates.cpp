#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i,n,m,k,a, ones=0, twoes=0, wash=0;

    cin>>n>>m>>k;
    for(i=0; i<n; i++)
    {
        cin>>a;
        if(a==1)
            ones++;
        else
            twoes++;
    }
    //cout<<ones <<" " <<twoes<<endl;

    if(ones>=m)
    {
        wash = wash + (ones-m);
        if(twoes>k)
            wash = wash + (twoes-k);

    }
    else
    {
        if(twoes >(k + (m-ones)))
            wash = wash + (twoes -(k + (m-ones)));
    }
    cout<<wash;


    return 0;
}

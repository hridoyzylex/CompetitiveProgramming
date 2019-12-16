#include <iostream>
#include <algorithm>

using namespace std;
struct st
{
    int a,b;
};
bool cmp(st x,st y)
{
    //use conditions according to ur need
    return x.a>y.a;
}

st ar[100];

int main()
{
    ar[0].a=2;
    ar[1].a=1;
    ar[2].a=3;

    sort(ar,ar+3,cmp);

    cout<<ar[0].a<<ar[1].a<<ar[2].a<<endl;

    return 0;
}

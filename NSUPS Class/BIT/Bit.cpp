#include <iostream>
#include <cstdio>
using namespace std;
#define N 7

int tree[] = {0,0,0,0,0,0,0};

void update(int idx, int v)
{
    while(idx<=N)
    {
        tree[idx] += v;
        idx += idx& - idx;
    }
}


int read(int idx)
{
    int res = 0;
    while(idx>0)
    {
        res += tree[idx];
        idx -= idx& -idx;
    }
    return res;
}


int main()
{
    int i;
    int a[] = {5,2,6,3,9,1,4};
    int cumSum[7];
    int bit[] = {0,0,0,0,0,0,0};

    cumSum[0] = 0;

    for(i=1; i<=7; i++)             //creating cumulative sum
    {
        cumSum[i] = cumSum[i-1] + a[i-1];
    }

    for(i=1; i<=7; i++)             //printing cumulative sum
    {
        cout<<cumSum[i] <<" ";
    }
    cout<<endl;

    update(1,5);
    update(2,2);
    update(3,6);
    update(4,3);
    update(5,9);
    update(6,1);
    update(7,4);
    cout<<read(1) <<" ";
    cout<<read(2) <<" ";
    cout<<read(3) <<" ";
    cout<<read(4) <<" ";
    cout<<read(5) <<" ";
    cout<<read(6) <<" ";
    cout<<read(7) <<" ";


    return 0;
}

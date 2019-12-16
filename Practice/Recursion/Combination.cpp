//Given n objects, how many different sets of size k can be chosen?

#include <iostream>
using namespace std;

int Combination(int n, int k)
{
    if(k==1)
        return n;
    if(n==k)
        return 1;
    else
    {
        return Combination(n-1, k) + Combination(n-1, k-1);
    }
}


int main()
{
    int n, k;

    cout<<"Input n: ";
    cin>>n;
    cout<<endl;
    cout<<"Input k: ";
    cin>>k;
    cout<<endl;

    int comb = Combination(n, k);
    cout<<"The Combination for "<<n <<"C" <<k <<" is: " <<comb <<endl;

    return 0;
}


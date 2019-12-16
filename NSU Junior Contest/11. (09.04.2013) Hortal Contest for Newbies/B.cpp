#include<iostream>
using namespace std;

int main()
{
    int T, N, i;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>N;

        if(N%3==0)
            cout<<N <<" is a multiple of 3"<<endl;
        else
            cout<<N <<" is not a multiple of 3"<<endl;
    }

    return 0;
}

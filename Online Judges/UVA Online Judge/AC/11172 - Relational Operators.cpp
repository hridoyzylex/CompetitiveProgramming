#include <iostream>
using namespace std;

int main()
{
    int T;
    long long a,b;

    cin>>T;
    while(T>0)
    {
        cin>>a>>b;

        if(a<b)
            cout<<"<" <<endl;
        else if(a>b)
            cout<<">" <<endl;
        else
            cout<<"=" <<endl;

        T--;
    }
    return 0;
}

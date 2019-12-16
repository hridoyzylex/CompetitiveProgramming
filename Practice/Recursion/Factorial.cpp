#include <iostream>
using namespace std;

int factorial(int f)
{
    if(f==0)
        return 1;
    else
    {
        return f*factorial(f-1);
    }
}


int main()
{
    int n;

    cout<<"Input a Number: ";
    cin>>n;

    int fact = factorial(n);

    cout<<"The factorial of "<<n <<" is: " <<fact <<endl;

    return 0;
}

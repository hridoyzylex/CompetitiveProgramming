#include <iostream>
using namespace std;

int main()
{

    int i,j,n,bottles, totalBottles;

    cin>>n;
    for(i=0; n!=0; i++)
    {
        bottles = 0;
        totalBottles = 0;

        if(n<3)
            totalBottles = 0;

        else
        {
        while(n>=2)
        {
            bottles = n/3;
            totalBottles = totalBottles + bottles;

            n = n - (3*bottles);

            if(bottles>2)
                n = n + bottles;

            if(n+bottles == 2)
                n++;
        }
        }


        cout<<totalBottles <<endl;

        cin>>n;
    }
    return 0;
}

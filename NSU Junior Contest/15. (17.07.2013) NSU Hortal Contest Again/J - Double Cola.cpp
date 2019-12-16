#include <iostream>
using namespace std;

int main()
{
    int i,j,n, total=0;
    int a[5] = {0,0,0,0,0};

    cin>>n;
    for(i=1; total<n; i=2*i)
    {
        for(j=0; j<5; j++)
        {
            if(total<n)
            {
                total = total + i;
            }
            else
                break;
        }
    }

    if(j==1)
        cout<<"Sheldon" <<endl;
    if(j==2)
        cout<<"Leonard" <<endl;
    if(j==3)
        cout<<"Penny" <<endl;
    if(j==4)
        cout<<"Rajesh" <<endl;
    if(j==5)
        cout<<"Howard" <<endl;

    return 0;
}

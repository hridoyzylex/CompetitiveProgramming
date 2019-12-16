#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i=1,j,k,T,n;
    int x[10000];
    int y[10000];

    cin>>T;
    while(T!=0)
    {
        cin>>n;

        int counter  = n;

        for(j=0; j<n; j++)
        {
            cin>>x[j] >>y[j];
            sort(x, x+n);
            sort(y, y+n);

            for(k=0; k<n-1; k++)
            {
                if(x[k]==x[k+1])
                    counter--;

                if(y[k]==y[k+1])
                    counter--;
            }

        }
        cin>>T;
        cout<<counter <<endl;
    }
    return 0;
}

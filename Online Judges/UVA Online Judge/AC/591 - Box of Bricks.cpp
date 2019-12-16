#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int stacks[53];
    int i,j,n,sum,height,moves;

    i=1;
    scanf("%d", &n);
    while(n!=0)
    {
        sum = 0;
        moves = 0;

        for(j=0; j<n; j++)
        {
            cin>>stacks[j];
            sum = sum + stacks[j];
        }
        height = sum/n;

        for(j=0; j<n; j++)
        {
            if(stacks[j]>height)
            {
                moves = moves + (stacks[j]-height);
            }
        }

        cout<<"Set #" <<i <<endl;
        cout<<"The minimum number of moves is " <<moves <<"." <<endl<<endl;

        i++;
        scanf("%d", &n);
    }

    return 0;
}

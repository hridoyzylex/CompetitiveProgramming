#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int i,j,T,N, scareCrow;
    char a[105];

    cin>>T;
    for(i=0; i<T; i++)
    {
        scareCrow = 0;
        cin>>N;
        cin>>a;

        for(j=0; j<N; )
        {
            if(a[j] == '.')
            {
                scareCrow++;
                j = j+3;
            }
            else
            {
                j++;
            }
        }
        cout<<"Case " <<i+1 <<": " <<scareCrow <<endl;
    }

    return 0;
}

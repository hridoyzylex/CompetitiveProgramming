#include<iostream>
using namespace std;

int main()
{
    int T,A,B,i,j,k;
    int flag, counter = 0;

    cin>>T;
    for(i=0; i<T; i++)
    {
        counter = 0;

        cin>>A>>B;
        for(j=A; j<=B; j++)
        {
            flag = 0;

            for(k=2; k<=j/2; k++)
            {
                if(j%k==0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==0)
                counter++;
        }
        if (A==1)
            counter--;

        cout<<"Case " <<i+1 <<": " <<counter <<endl;
    }

    return 0;
}

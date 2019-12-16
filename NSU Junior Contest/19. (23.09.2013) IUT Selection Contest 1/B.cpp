#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,k,T,Q,a,b,counter;
    int arr[100000];
    char c[3];

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        counter = 0;
        printf("Case %d:\n", i+1);

        for(k=0; k<=100000; k++)
            arr[k] = 0;

        scanf("%d", &Q);
        for(j=0; j<Q; j++)
        {
            scanf("%d %c  %d", &a, &c[0], &b);

            if(c[0]=='+')
            {
                if(arr[a]==0 && arr[b]==0)
                {
                    arr[a] = 1;
                    arr[b] = 1;
                    counter = counter + 2;
                }
                else if((arr[a]==0 && arr[b]==1)||(arr[a]==1 && arr[b]==0))
                {
                    arr[a] = 1;
                    arr[b] = 1;

                    if(arr[b]==1)
                        arr[b] = 2;
                    else
                        arr[a] = 2;

                    counter = counter + 1;
                }
            }
            else if(c[0]=='-')
            {
                if(arr[a]==1 && arr[b]==1)
                {
                    arr[a] = 0;
                    arr[b] = 0;
                    counter = counter - 2;
                }

                else if((arr[a]==1 && arr[b]==2)||(arr[a]==2 && arr[b]==1))
                {
                    arr[a] = 0;
                    arr[b] = 0;

                    if(arr[b]==2)
                        arr[b] = 1;
                    else
                        arr[a] = 1;

                    counter = counter - 1;
                }
            }
            printf("%d\n", counter);
        }
    }
    return 0;
}


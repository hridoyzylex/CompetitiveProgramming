#include <stdio.h>

int main()
{
    int i,j,k,N,num;
    int flag;

    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &num);
        for (j=num/2; j>1; j--)
        {
            flag = 0;
            if (num%j==0)
            {
                for (k=2; k<j/2; k++)
                {
                    if (j%k==0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag==0)
                {
                    Max = j;
                    break;
                }

            }
        }
    }

    return 0;
}

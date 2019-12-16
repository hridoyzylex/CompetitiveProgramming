#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, T, n, m, counter=0;
    int k=0;
    int l=0;
    char N[40] = {0};
    char M[40] = {0};
    char dummy[5];

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        scanf("%d", &n);
        gets(dummy);
        gets(N);
        scanf("%d", &m);
        gets(dummy);
        gets(M);

    if (N[0]==M[0])
    {
        counter++;

        k=1;
        l=1;

        for (j=1; j<n; j++)
        {
            for (k=k ; N[k]!=' '; k++);
            for (l=l ; M[l]!=' '; l++);

            if (N[k-1]==M[l-1])
            {
                counter++;
                //k++;
                //l++;
            }
            else
                break;


        }
    //if (counter==n)
      //  printf("SAME");
    //else
      //  printf("DIFFERENT");
    printf("%d", counter);
    }
    }

    return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //freopen("G.txt", "r", stdin);
    int T,i,j,k,l,m, length;
    char s[150];
    char New[150];
    char dummy[2];
    char temp;

    scanf("%d", &T);
    gets(dummy);

    for(i=0; i<T; i++)
    {
        k = 0;
        j = 0;
        gets(s);
        length = strlen(s);
        //strrev(s);

        for(m=0; m<strlen(s)/2; m++)
        {
            temp = s[m];
            s[m] = s[strlen(s)-1-m];
            s[strlen(s)-1-m] = temp;
        }
        while(length>0)
        {

            int start = j;
            for(j=j; s[j]!=' '; )
            {
                j++;
                if(s[j]=='\0')
                    break;

            }
            int finish=j;

            for(k=k; finish!=start; k++)
            {
                New[k] = s[finish-1];
                finish--;
                length--;
            }

            New[k] = ' ';
            k++;
            j++;

        }
        for(l=0; l<strlen(s); l++)
            printf("%c", New[l]);

        printf("\n");
    }

    return 0;
}

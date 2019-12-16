#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("G.txt", "r", stdin);
    int T, i,j,k,length;
    char s[150];
    char New[150];
    char dummy[2];

    cin>>T;
    gets(dummy);

    for(i=0; i<T; i++)
    {
        k = 0;
        j = 0;
        gets(s);
        length = strlen(s);
        strrev(s);

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
        for(int i=0; i<strlen(s); i++)
            cout<<New[i];

        cout<<endl;
    }

    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    freopen("I.txt", "r", stdin);
    int T,i,j,k,l;
    int lvol;
    int lcon;
    char dummy[2];
    char all[100];
    char vowel[100];
    char consonant[100];

    cin>>T;
    gets(dummy);
    for(i=0; i<T; i++)
    {
        lvol = 0;
        lcon = 0;
        k = 0;
        l = 0;

        gets(all);
        for(j=0; all[j]!='\0'; j++)
        {
            if((all[j]=='a')||(all[j]=='A')||(all[j]=='e')||(all[j]=='E')||(all[j]=='i')||(all[j]=='I')||(all[j]=='o')||(all[j]=='O')||(all[j]=='u')||(all[j]=='U'))
            {
                vowel[k] = all[j];
                k++;
                lvol++;
            }
            else
            {
                if (all[j]==' ')
                    continue;

                consonant[l] = all[j];
                l++;
                lcon++;
            }
        }
        cout<<"Case " <<i+1 <<":" <<endl;

        for(int i=0; i<lvol; i++)
            cout<<vowel[i];
        cout<<endl;

        for(int i=0; i<lcon; i++)
            cout<<consonant[i];
        cout<<endl;
        cout<<endl;
    }
    return 0;
}

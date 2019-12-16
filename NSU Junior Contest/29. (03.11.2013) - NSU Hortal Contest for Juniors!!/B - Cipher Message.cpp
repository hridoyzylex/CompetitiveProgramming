#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);

    int i,j,k,counter, flag;
    char a[200005];

    while(gets(a))
    {
        flag=1;

        while(flag)
        {
            for(i=0; a[i]!='\0'; i++)
            {
                if(a[i]==a[i+1])
                {
                    for(j=i; a[j]!='\0'; j++)
                    {
                        a[j]=a[j+2];
                    }
                }
                if(a[i]<'a' || a[i]>'z')
                {
                    for(j=i; a[j]!='\0'; j++)
                    {
                        a[j]=a[j+1];
                    }
                }

                for(k=0; a[k]!='\0'; k++)
                {
                    if(a[k]==a[k+1])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
        }
        cout<<a<<endl;
    }
    return 0;
}

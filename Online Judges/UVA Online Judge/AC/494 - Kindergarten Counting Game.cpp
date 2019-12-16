#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i, count,start;
    char ch[1000];
    while(gets(ch))
    {
        count=0;
        start=0;

        for(i=0; ch[i]!='\0'; i++)
        {
            if(((ch[i]>='a' && ch[i]<='z') || ( ch[i]>='A' && ch[i]<='Z')))
                start=1;
            else
            {
                if(start)
                {
                    count++;
                    start=0;
                }
            }

        }
        if(ch[i]=='\0' && start==1)
            count++;

        printf("%d\n",count);
    }
    return 0;
}

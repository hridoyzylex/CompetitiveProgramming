#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int soundex(char ch)
{
    if(ch=='B'||ch=='F'||ch=='P'||ch=='V')return 1;
    else if(ch=='C'||ch=='G'||ch=='J'||ch=='K'||ch=='Q'||ch=='S'||ch=='X'||ch=='Z')return 2;
    else if(ch=='D'||ch=='T')return 3;
    else if(ch=='L')return 4;
    else if(ch=='M'||ch=='N')return 5;
    else if(ch=='R')return 6;
    else return 0;
}

int main()
{
    freopen("Input.txt", "r", stdin);
    char code[25],x;
    int i,j,c,len,a[22];

    printf("         NAME                     SOUNDEX CODE\n");     //9spaces before NAME and 21 spaces before SOUNDEX CODE
    while(gets(code))
    {
        for(i=0; i<22; i++)     //to initialize the array with 0
            a[i]=0;

        len=strlen(code);
        printf("         ");
        printf("%s",code);      //print the name

        for(i=len; i<25; i++)
            printf(" ");        //print (25-lenghOfName) spaces

        printf("%c",code[0]);   //print the first character of the name

        a[0]=soundex(code[0]);
        j=1;
        for(i=1; i<len; i++)
        {
            c=soundex(code[i]);
            //cout<<"-" <<c <<"-";
            if(c!=soundex(code[i-1]) && c!=0)   //c != 0 and != it's previous number
            {
                a[j]=c;
                j++;
            }
        }
        for(i=1; i<=3; i++)     //print the a[1], a[2], a[3]
            printf("%d",a[i]);

        printf("\n");
    }
    printf("                   END OF OUTPUT\n");       //19 spaces before END

    return 0;
}

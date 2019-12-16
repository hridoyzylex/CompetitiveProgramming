#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,j,k,n,x,length;
    char line[2005], Inp[2005], Out[2005];
    char *tmp;

    cin>>n;
    getchar();

    for(i=0; i<n; i++)
    {
        cout<<"Message #" <<i+1 <<endl;
        gets(line);
        strcpy(Inp, line);
        //cout<<strlen(line) <<endl;
        //cout<<line<<endl;

        tmp = strtok(line, " ");
        for(k=0; tmp!=NULL; k++)
        {
            if(strcmp(tmp,".-" ) == 0) Out[k] = 'A';
            else if(strcmp(tmp,"-..." ) == 0) Out[k] = 'B';
            else if(strcmp(tmp,"-.-." ) == 0) Out[k] = 'C';
            else if(strcmp(tmp,"-.." ) == 0) Out[k] = 'D';
            else if(strcmp(tmp,"." ) == 0) Out[k] = 'E';
            else if(strcmp(tmp,"..-." ) == 0) Out[k] = 'F';
            else if(strcmp(tmp,"--." ) == 0) Out[k] = 'G';
            else if(strcmp(tmp,"...." ) == 0) Out[k] = 'H';
            else if(strcmp(tmp,".." ) == 0) Out[k] = 'I';
            else if(strcmp(tmp,".---" ) == 0) Out[k] = 'J';
            else if(strcmp(tmp,"-.-" ) == 0) Out[k] = 'K';
            else if(strcmp(tmp,".-.." ) == 0) Out[k] = 'L';
            else if(strcmp(tmp,"--" ) == 0) Out[k] = 'M';
            else if(strcmp(tmp,"-." ) == 0) Out[k] = 'N';
            else if(strcmp(tmp,"---" ) == 0) Out[k] = 'O';
            else if(strcmp(tmp,".--." ) == 0) Out[k] = 'P';
            else if(strcmp(tmp,"--.-" ) == 0) Out[k] = 'Q';
            else if(strcmp(tmp,".-." ) == 0) Out[k] = 'R';
            else if(strcmp(tmp,"..." ) == 0) Out[k] = 'S';
            else if(strcmp(tmp,"-" ) == 0) Out[k] = 'T';
            else if(strcmp(tmp,"..-" ) == 0) Out[k] = 'U';
            else if(strcmp(tmp,"...-" ) == 0) Out[k] = 'V';
            else if(strcmp(tmp,".--" ) == 0) Out[k] = 'W';
            else if(strcmp(tmp,"-..-" ) == 0) Out[k] = 'X';
            else if(strcmp(tmp,"-.--" ) == 0) Out[k] = 'Y';
            else if(strcmp(tmp,"--.." ) == 0) Out[k] = 'Z';
            else if(strcmp(tmp,"-----" ) == 0) Out[k] = '0';
            else if(strcmp(tmp,".----" ) == 0) Out[k] = '1';
            else if(strcmp(tmp,"..---" ) == 0) Out[k] = '2';
            else if(strcmp(tmp,"...--" ) == 0) Out[k] = '3';
            else if(strcmp(tmp,"....-" ) == 0) Out[k] = '4';
            else if(strcmp(tmp,"....." ) == 0) Out[k] = '5';
            else if(strcmp(tmp,"-...." ) == 0) Out[k] = '6';
            else if(strcmp(tmp,"--..." ) == 0) Out[k] = '7';
            else if(strcmp(tmp,"---.." ) == 0) Out[k] = '8';
            else if(strcmp(tmp,"----." ) == 0) Out[k] = '9';
            else if(strcmp(tmp,".-.-.-" ) == 0) Out[k] = '.';
            else if(strcmp(tmp,"--..--" ) == 0) Out[k] = ',';
            else if(strcmp(tmp,"..--.." ) == 0) Out[k] = '?';
            else if(strcmp(tmp,".----." ) == 0) Out[k] = '\'';
            else if(strcmp(tmp,"-.-.--" ) == 0) Out[k] = '!';
            else if(strcmp(tmp,"-..-." ) == 0) Out[k] = '/';
            else if(strcmp(tmp,"-.--." ) == 0) Out[k] = '(';
            else if(strcmp(tmp,"-.--.-" ) == 0) Out[k] = ')';
            else if(strcmp(tmp,".-..." ) == 0) Out[k] = '&';
            else if(strcmp(tmp,"---..." ) == 0) Out[k] = ':';
            else if(strcmp(tmp,"-.-.-." ) == 0) Out[k] = ';';
            else if(strcmp(tmp,"-...-" ) == 0) Out[k] = '=';
            else if(strcmp(tmp,".-.-." ) == 0) Out[k] = '+';
            else if(strcmp(tmp,"-....-" ) == 0) Out[k] = '-';
            else if(strcmp(tmp,"..--.-" ) == 0) Out[k] = '_';
            else if(strcmp(tmp,".-..-." ) == 0) Out[k] = '"';
            else if(strcmp(tmp,".--.-." ) == 0) Out[k] = '@';

            tmp = strtok(NULL, " ");
        }

        for(j=0, x=0; j<strlen(Inp)-1; j++)
        {
            if(Inp[j]!=' ' && Inp[j+1]==' ')
            {
                cout<<Out[x];
                x++;
            }
            else if (Inp[j]==' ' && Inp[j+1]==' ')
            {
                if(x!=0)
                    cout<<" ";
            }
        }
        cout<<Out[x++] <<endl <<endl;
    }
    return 0;
}


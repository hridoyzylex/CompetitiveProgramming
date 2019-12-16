#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int i,flag = 0;
    char pass[15] = "lenovo";
    char passCheck[15];

    cout<<"Input Password: ";
    gets(passCheck);

    for(i=0; passCheck[i]!='\0'; i++)
    {
        if (pass[i]!=passCheck[i])
        {
            flag = 1;
            cout<<"You have entered wrong password"<<endl;
            break;
        }
    }

    if(flag == 0)
        cout<<"Congrats!!! Password is Accepted"<<endl;

    return 0;
}

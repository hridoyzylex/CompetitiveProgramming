#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct country          //to creat STRUCT
{
    char name[100];
    int frequency;
};

bool cmp(country a, country b)      //sort name according to alphabets
{
    return (strcmp(a.name, b.name)<0);
}

int main()
{
    freopen("Input.txt", "r", stdin);

    country c[2005];
    int i,j,n,counter;
    char line[100];
    char *pch;

    counter = 0;

    cin>>n;
    getchar();

    for(i=0; i<n; i++)
    {
        gets(line);
        pch = strtok(line, " ");        //to get only the first word from the line

        for(j=0; j<counter; j++)
        {
            if(strcmp(pch, c[j].name )==0)      //the current name already exist then only increase the frequency
            {
                c[j].frequency++;
                break;
            }
        }
        if(j>=counter)
        {
            strcpy(c[counter].name, pch);   //else include the name and increase the frequency
            c[counter].frequency++;
            counter++;
        }
    }
    sort(c, c+counter, cmp);                //sort in alphabetical orders
    for(i=0; i<counter; i++)
    {
        cout<<c[i].name <<" " <<c[i].frequency <<endl;
    }

    return 0;
}

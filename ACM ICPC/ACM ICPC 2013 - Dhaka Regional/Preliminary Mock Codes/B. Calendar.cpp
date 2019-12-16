#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);
    int i,j,T,day, month, year,totalDays,flag;
    char c[5];
    int Leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int notLeap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    cin>>T;
    for(i=0; i<T; i++)
    {
        scanf("%d %c %c %c %c %c %d", &day, &c[0], &c[1], &c[2], &c[3], &c[4], &year);

        flag = 1;
        totalDays = 0;

        if(c[1]=='J' && c[2]=='A')
            month = 1;
        else if(c[1]=='F' && c[2]=='E')
            month = 2;
        else if(c[1]=='M' && c[2]=='A')
            month = 3;
        else if(c[1]=='A' && c[2]=='P')
            month = 4;
        else if(c[1]=='M' && c[2]=='A')
            month = 5;
        else if(c[1]=='J' && c[2]=='U' && c[3]=='N')
            month = 6;
        else if(c[1]=='J' && c[2]=='U' && c[3]=='L')
            month = 7;
        else if(c[1]=='A' && c[2]=='U')
            month = 8;
        else if(c[1]=='S' && c[2]=='E')
            month = 9;
        else if(c[1]=='O' && c[2]=='C')
            month = 10;
        else if(c[1]=='N' && c[2]=='O')
            month = 11;
        else if(c[1]=='D' && c[2]=='E')
            month = 12;


        if(month==1)
        {
            cout<<"Case " <<i+1 <<": " <<day <<" Hundreds" <<endl;
            flag = 0;
        }
        else if(( year%4 == 0 && year%100 != 0 )||( year%400 == 0 ))
        {
            for(j=0; j<month-1; j++)
                totalDays = totalDays + Leap[j];
            totalDays = totalDays + day;
        }
        else
        {
            for(j=0; j<month-1; j++)
                totalDays = totalDays + notLeap[j];
            totalDays = totalDays + day;
        }

        if(month!=1)
        {
            if(totalDays<=300)
                cout<<"Case " <<i+1 <<": " <<totalDays <<" Hundreds" <<endl;
            else if(totalDays>300 && totalDays<=360)
                cout<<"Case " <<i+1 <<": " <<totalDays-300 <<" Tens" <<endl;
            else if(totalDays>360)
                cout<<"Case " <<i+1 <<": " <<totalDays-360 <<" Ones" <<endl;
        }

    }


    return 0;
}

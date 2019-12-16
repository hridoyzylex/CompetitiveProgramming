#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int T,i,j, counter;
    int dStart, dEnd, yStart, yEnd;
    char mStart[10] = "";
    char mEnd[32] = "";
    char bin[5]="";

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        gets(bin);
        counter = 0;
        scanf("%s %d, %d", &mStart, &dStart, &yStart);
        scanf("%s %d, %d", &mEnd, &dEnd, &yEnd);

        counter = ((yEnd/4)-(yEnd/100)+(yEnd/400)) - ((yStart/4)-(yStart/100)+(yStart/400));

        if(((yStart%4==0)&&(yStart%100!=0)||(yStart%400==0)) && (strcmp(mStart, "January")==0|| strcmp(mStart, "February")==0))
        {
            counter++;
        }

        if(((yEnd%4==0)&&(yEnd%100!=0)||(yEnd%400==0)) && (strcmp(mEnd, "January")==0|| strcmp(mEnd, "February")==0))
        {
            if(strcmp(mEnd, "February")==0 && dEnd==29)
                counter = counter;
            else
                counter--;
        }

        if(yStart == yEnd)
        {
            if((strcmp(mStart, "January")==0|| strcmp(mStart, "February")==0))
            {
                if( (strcmp(mEnd, "January")!=0 && strcmp(mEnd, "February")!=0)||(strcmp(mEnd, "February")!=0 && dEnd==29))
                {
                    if( (yEnd%4==0)&&(yEnd%100!=0)||(yEnd%400==0) )
                        counter = 1;
                }
            }
        }

        printf("Case %d: %d\n", i+1, counter);
    }
    return 0;
}

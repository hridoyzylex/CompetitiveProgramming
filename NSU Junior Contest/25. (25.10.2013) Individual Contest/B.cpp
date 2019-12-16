#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    //freopen("B.txt", "r", stdin);
    int i,j,k,C,Steps;
    float Difference_Zero, Difference_One;
    int One_in_T, Zero_in_T, One_in_S, Zero_in_S;
    char S[105];
    char T[105];
    char dummy[1];

    cin>>C;
    scanf("%c", &dummy[0]);
    for(i=0; i<C; i++)
    {
        Steps = 0;
        Difference_Zero= 0;
        Difference_One= 0;
        One_in_T = 0;
        Zero_in_T = 0;
        One_in_S = 0;
        Zero_in_S = 0;

        gets(S);
        gets(T);


        for(j=0; S[j]!='\0'; j++)
        {
            if(S[j]=='0')
                Zero_in_S++;
            if(S[j]=='1')
                One_in_S++;
        }

        for(j=0; T[j]!='\0'; j++)
        {
            if(T[j]=='0')
                Zero_in_T++;
            else
                One_in_T++;
        }

        //cout<<Zero_in_T <<" " <<One_in_T <<endl;
        //cout<<Zero_in_S <<" " <<One_in_S <<endl;

        for(j=0; S[j]!='\0'; j++)
        {
            if(S[j]=='?')
            {
                if(T[j]=='0')
                {
                    if(Zero_in_S < Zero_in_T)
                    {
                        S[j] = '0';
                        Zero_in_S++;
                        Steps++;
                    }
                    else
                    {
                        S[j] = '1';
                        One_in_S++;
                        Steps++;
                    }
                }

                else if(T[j]=='1')
                {
                    if(One_in_S < One_in_T)
                    {
                        S[j] = '1';
                        One_in_S++;
                        Steps++;
                    }
                    else
                    {
                        S[j] = '0';
                        Zero_in_S++;
                        Steps++;
                    }
                }
            }
        }



        if(One_in_S > One_in_T)
            cout<<"Case " <<i+1 <<": " <<"-1" <<endl;
        else
        {
            for(j=0; S[j]!='\0'; j++)
            {
                if(S[j]=='0' && T[j]=='1')
                    Difference_Zero++;

                else if(S[j]=='1' && T[j]=='0')
                    Difference_One++;
            }

            if(Difference_One < Difference_Zero)
            {
                Steps = Steps + Difference_One + (Difference_Zero - Difference_One);
            }

            else if(Difference_One == Difference_Zero)
            {
                Steps = Steps + Difference_One;
            }

            cout<<"Case " <<i+1 <<": " <<Steps <<endl;
        }
    }

    return 0;
}

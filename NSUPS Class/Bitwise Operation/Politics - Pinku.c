#include<stdio.h>

int main()
{
    int i, j,k,v=0,V;
    int n[4];
    int m[4][4] = {0,-100,150,5000,-100,0,250,2500,150,250,0,10000,5000,2500,10000,0};

    for(i=1;i<=15;i++)
    {
        V=0;

        for(j=0;j<4;j++)
            n[j]=0;

        for(j=0;j<4;j++)
        {
            if(i&(1<<j))
                n[j]=1;
        }

        for(j=0;j<4;j++)
        {
            if(n[j])
            {
                for(k=j+1;k<4;k++)
                {
                    if(n[k])
                        V+=m[j][k];
                }
            }
        }

        if(V>v)v=V;
    }

    printf("Max=%d", v);
}

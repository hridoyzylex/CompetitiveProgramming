#include <iostream>
#include <stdio.h>
using namespace std;

int main()

{
    freopen("input.txt", "r", stdin);
    double t1,t2,dis,a,b,c,v1,v2,
    v3,a1,a2,t,i,j,g,m1,m2,aw,aq,s;
    scanf("%lf",&a);
    for(i=1;i<=a;i++)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        m1=v1*v1;
        m2=v2*v2;
        aw=m1/(2*a1);
        aq=m2/(2*a2);
        s=aw+aq;
        t1=v1/a1;
        t2=v2/a2;
        t=(t1>t2)?t1:t2;

        dis=v3*t;
        printf("Case %.0lf: %lf %lf\n",i,s,dis);
    }
   return 0;
}

#include <stdio.h>

int main()
{
    int T, a, b, c, i;
    double s, m, l;

    scanf("%d", &T);

    for(i=0; i<T; i++)
    {
    scanf("%d %d %d", &a, &b, &c);

    if ((a>b)&&(a>c)){
    l = a;
        if (b>c){
            s = c;
            m = b;
        }
        else{
            s = b;
            m = c;
        }
    }

    else if ((b>a)&&(b>c)){
    l = b;
        if (a>c){
            s = c;
            m = a;
        }
        else{
            s = a;
            m = c;
        }
    }
    else{
    l = c;
        if (a>b){
            s = b;
            m = a;
        }
        else{
            s = a;
            m = b;
        }
    }
    if (s*s + m*m == l*l)
        printf("Case %d: yes\n", i+1);
    else
        printf("Case %d: no\n", i+1);
    }

    return 0;
}

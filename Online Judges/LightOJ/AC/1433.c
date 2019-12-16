#include <stdio.h>
#include <math.h>

int main()
{
    freopen("input.txt", "r", stdin);
    int T, i;
    int Ox, Oy, Ax, Ay, Bx, By;
    double radius, chord, angle, cons, arc;


    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d %d %d %d %d %d", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
        radius = sqrt(pow(Ax-Ox, 2) + pow(Ay-Oy, 2));
        chord = sqrt(pow(Bx-Ax, 2) + pow(By-Ay, 2));
        cons = ((radius*radius + radius*radius - chord*chord)/(2*radius*radius));
        angle = acos(cons);
        arc = radius*angle;

        printf("Case %d: %0.8lf\n", i+1, arc);
    }
    return 0;
}

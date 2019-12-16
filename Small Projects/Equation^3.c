#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    float x1, x2;

    printf("For The Euation (ax2+bx+c)\n\n");

    printf("Input the value for a: ");
    scanf("%d", &a);
    printf("Input the value for b: ");
    scanf("%d", &b);
    printf("Input the value for c: ");
    scanf("%d", &c);

    x1 = ((-b+sqrt(b*b - 4*a*c))/(2*a));
    x2 = ((-b-sqrt(b*b - 4*a*c))/(2*a));

    printf("%0.2f %0.2f", x1, x2);

    return 0;
}

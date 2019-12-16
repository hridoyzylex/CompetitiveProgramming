#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    float page, total = 0;

    printf("Input the number of slides: \n");

    scanf("%f", &page);
    total = total + ceil(page/4);

    while(page!=0)
    {
        scanf("%f", &page);
        total = total + ceil(page/4);
    }

    printf("\n\nSo far you have printed %0.1f pages as handouts.\n\n", total);

    return 0;
}

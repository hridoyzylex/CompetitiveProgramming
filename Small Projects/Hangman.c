#include<stdio.h>

int main()
{
    int i, flag=0;
    char Word[5] = "Love";
	char Guess[5];

	printf("Input The Word: ");
	gets(Guess);

	for (i=0; i<5; i++)
	{
	    if(Guess[i]!=Word[i])
	    {
            printf(" (O.O)\n");
            printf("  ||\n");
            printf("//||\\\\ - Hanged to Death\n");
            printf("  ||\n");
            printf(" _||_\n");

            flag = 1;
            break;
        }
        if(flag==0)
        {
            printf("Perfect");
            break;
        }
	}
	return 0;
}

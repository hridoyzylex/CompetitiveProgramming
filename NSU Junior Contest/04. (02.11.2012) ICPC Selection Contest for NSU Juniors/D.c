#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int player1, player2;
    char p1[75];
    char p2[75];

    gets(p1);
    gets(p2);

    while (p1[0]!='E' && p2[0]!='E'){
    player1 = 0;
    player2 = 0;
    for (i=0; i<strlen(p1); i++)
    {
        if (p1[i]=='R' && p2[i]=='P')
            player2++;
        if (p1[i]=='R' && p2[i]=='S')
            player1++;
        if (p1[i]=='P' && p2[i]=='R')
            player1++;
        if (p1[i]=='P' && p2[i]=='S')
            player2++;
        if (p1[i]=='S' && p2[i]=='R')
            player2++;
        if (p1[i]=='S' && p2[i]=='P')
            player1++;
    }
    printf("P1: %d\n", player1);
    printf("P2: %d\n", player2);

    gets(p1);
    gets(p2);
    }
    return 0;
}

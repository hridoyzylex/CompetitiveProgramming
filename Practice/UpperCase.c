#include <stdio.h>
int main()
{
    char s[32] = "";
    int i;

    printf("Input A String: ");
    gets(s);

    for (i=0; s[i]!='\0'; i++){
        if((s[i] >= 'a') && (s[i] <= 'z'))
            s[i] = s[i] - ('a'-'A');
    }

    printf("The Sting in UPPERCASE: ");
    puts(s);

    return 0;
}

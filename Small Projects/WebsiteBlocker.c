#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char stString[] = "\n#                  127.0.0.1                ";
    char szString[32] = "";

    fflush(stdin);
    printf("\t\t!!!Welcome!!!\n!!!This Program Will Block Your Desired Website!!!\n\n");
    printf("Input The Website: ");
    gets(szString);

    FILE *hFile;
    hFile = fopen("C:\\Windows\\System32\\drivers\\etc\\test.txt", "w+");
    if (hFile == NULL)
    {
        printf("Unsuccessfull");
    }
    else
    {
        fwrite(stString, sizeof(char), strlen(stString), hFile);
        fwrite(szString, sizeof(char), strlen(szString), hFile);

        printf("\nThe Desired Website is Succesfully Blocked\n\n\tThanks For Using This Program\n\t   Owner: MD.TASIB HAIDER\n\n");


        fclose(hFile);
    }

    return 0;
}

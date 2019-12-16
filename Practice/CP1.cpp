#include <bits/stdc++.h>
using namespace std;

char digits[100];

int main()
{
    int N;

    scanf("%d", &N);
    while(N--)
    {
        scanf("0.%[0-9]...", &digits);
        printf("the digits are 0.%s\n", digits);
    }

    return 0;
}

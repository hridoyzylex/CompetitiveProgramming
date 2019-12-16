#include <iostream>
using namespace std;


int RevAInteger(int x)
{
    int reverse = 0;
    while (x != 0)
    {
        reverse = reverse * 10;
        reverse = reverse + x%10;
        x = x/10;
    }

    return reverse;
}


int main()
{
    int i,N,A,B, revA, revB, total, revTotal;

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>A>>B;

        revA = RevAInteger(A);
        revB = RevAInteger(B);

        total = revA + revB;
        revTotal = RevAInteger(total);

        cout<<revTotal <<endl;
    }

    return 0;
}

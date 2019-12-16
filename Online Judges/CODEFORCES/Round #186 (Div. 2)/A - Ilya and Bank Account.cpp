#include <iostream>
using namespace std;

int main()
{
    int state, OmitLast, Omit2Last, Remainder;
    cin>>state;

    if (state>=0)
        cout<<state <<endl;
    else
    {
        OmitLast = state/10;

        Remainder  = state%10;
        state = state/10;
        Omit2Last = state/10;
        Omit2Last = Omit2Last*10 + Remainder;

        if (OmitLast>Omit2Last)
            cout<<OmitLast <<endl;
        else
            cout<<Omit2Last <<endl;

    }

    return 0;
}

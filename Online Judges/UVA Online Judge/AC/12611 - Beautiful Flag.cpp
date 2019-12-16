#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("D.txt", "r", stdin);

    int T,R;

    cin>>T;
    for(int t=1; t<=T; ++t)
    {
        cin >> R;

        cout << "Case " << t << ":" << endl;

        cout << (-R*45/20) << " " << (R*30/20) << endl;
        cout << (R*55/20) << " " << (R*30/20) << endl;
        cout << (R*55/20) << " " << (-R*30/20) << endl;
        cout << (-R*45/20) << " " << (-R*30/20) << endl;
    }
    return 0;
}

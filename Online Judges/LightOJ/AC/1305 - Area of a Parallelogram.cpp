#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int T, i;
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    int AB, BC,AC,s,Area,part1,part2;

    cin>>T;
    for (i=0; i<T; i++)
    {
        cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;

        AB = sqrt((Bx-Ax)*(Bx-Ax) + (By-Ay)*(By-Ay));
        BC = sqrt((Cx-Bx)*(Cx-Bx) + (Cy-By)*(Cy-By));
        AC = sqrt((Cx-Ax)*(Cx-Ax) + (Cy-Ay)*(Cy-Ay));

        Dx = Cx - (Bx - Ax);
        Dy = Ay + (Cy-By);

        part1 = (Ax*By)+(Bx*Cy)+(Cx*Dy)+(Dx*Ay);
        part2 = (Ay*Bx)+(By*Cx)+(Cy*Dx)+(Dy*Ax);
        Area = fabs((part1-part2)/2);

        cout<<"Case " <<i+1 <<": " <<Dx <<" " <<Dy <<" " <<Area <<endl;
    }
    return 0;
}

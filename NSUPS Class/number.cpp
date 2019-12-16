//Q. Minimum no. of steps needed to reach the converging point. (05/04/2013)
#include <iostream>
using namespace std;

int main()
{
	int a,b,d;
	cin>>a>>b>>d;

	if(a>b)
	{
		if((a-b)%d==0)
			cout<<(a-b)/d <<endl;
		else
			cout<<"Not Possible" <<endl;
	}

	else if(a<b)
	{
		if((b-a)%d==0)
			cout<<(b-a)/d <<endl;
		else
			cout<<"not possible" <<endl;
	}

    return 0;
}

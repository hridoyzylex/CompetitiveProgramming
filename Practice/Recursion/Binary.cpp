#include <iostream>
using namespace std;

int a[4];

void print(int index)
{
	if(index==4)
	{
		for(int i=0; i<index; i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
	else
	{
		for(int i=0; i<2; i++)
		{
			a[index] = i;
			print(index + 1);
		}
	}
}
int main()
{

	print(0);

	return 0;
}

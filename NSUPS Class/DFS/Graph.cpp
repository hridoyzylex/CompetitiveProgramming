#include <stdio.h>
#include <iostream>
using namespace std;

int array[8][8];

int main()
{
	freopen("Input.txt", "r", stdin);

	int a,b,c, i,j;

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			array[i][j] = -1;
			if(i==j)
				array[i][j] = 0;
		}
	}

	for(int i=0; i<8; i++)
	{
		cin>>a >>b >>c;

		array[a][b] = c;
		array[b][a] = c;
	}

	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
			cout<<i <<" " <<j <<" " <<array[i][j] <<endl;
	}


	return 0;
}

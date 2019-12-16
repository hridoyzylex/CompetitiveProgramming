#include <stdio.h>
#include<iostream>
using namespace std;

int line[20001] = {0};

int main()
{
	freopen("J.txt", "r", stdin);
	int Q, i, n, counter = 0;

	cin>>Q;
	for(i=0; i<Q; i++)
    {
		cin>>n;
        line[n] = 1;

		if(line[n-1] == line[n+1])
        {
            if(line[n-1])
                counter--;
            else
                counter++;
        }
		cout<<counter <<endl;
	}
	cout<<"Justice"<<endl;

	return 0;
}

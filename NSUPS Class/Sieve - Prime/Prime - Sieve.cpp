//Q. Find prime nos using sieve? (05/04/2013)
#include <iostream>
using namespace std;
int main()
{
	int i, j, n, counter = 0;

    cout<<"Input n: ";
	cin>>n;
	int a[1000];

	for(i=0; i<n; i++)
	{
		a[i] = 1;
	}

	for(i=2; i<n; i++)
	{
		if(a[i] != 0)
		{
			for(j=i*2; j<n; j=j+i)
			{
				a[j] = 0;
			}
		}
	}

    cout<<"The Primes are: ";
	for(i=2; i<n; i++)
	{
		if(a[i]==1)
        {
			cout<<i <<" ";
			counter++;
        }
	}

    cout<<endl;

    cout<<"No of Primes: " <<counter <<endl;

	return 0;
}

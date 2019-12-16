#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int i,j, n, m, T, value,counter;
    char c[10];

    cin>>T;
    for(i=0; i<T; i++)
    {
        list<int> list1;
        counter = 0;

        cout<<"Case " <<i+1 <<":" <<endl;

        cin>>n>>m;
        for(j=0; j<m; j++)
        {
            cin>>c;

            if(strcmp(c, "pushLeft")==0)
            {
                cin>>value;

                if(counter<n)
                {
                    list1.push_front(value);
                    counter++;
                    cout<<"Pushed in left: " <<value <<endl;
                }
                else
                    cout<<"The queue is full" <<endl;
            }

            else if(strcmp(c, "pushRight")==0)
            {
                cin>>value;

                if(counter<n)
                {
                    list1.push_back(value);
                    counter++;
                    cout<<"Pushed in right: " <<value <<endl;
                }
                else
                    cout<<"The queue is full" <<endl;
            }

            else if(strcmp(c, "popLeft")==0)
            {
                if(counter>0)
                {
                    cout<<"Popped from left: " <<list1.front() <<endl;
                    list1.pop_front();
                    counter--;
                }
                else
                    cout<<"The queue is empty" <<endl;
            }

            else if(strcmp(c, "popRight")==0)
            {
                if(counter>0)
                {
                    cout<<"Popped from right: " <<list1.back() <<endl;
                    list1.pop_back();
                    counter--;
                }
                else
                    cout<<"The queue is empty" <<endl;
            }
        }
    }

    return 0;
}

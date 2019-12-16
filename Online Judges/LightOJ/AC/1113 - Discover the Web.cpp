#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int i,j,T;
    char cmd[10];
    char url[55];
    string current;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cout<<"Case " <<i+1 <<":" <<endl;

        stack<string> fStack;
        stack<string> bStack;

        current =  "http://www.lightoj.com/";
        bStack.push(current);

        cin>>cmd;

        while(strcmp(cmd, "QUIT")!=0)
        {
            if(strcmp(cmd, "VISIT")==0)
            {
                cin>>current;
                cout<<current <<endl;
                bStack.push(current);

                if(!fStack.empty())
                {
                    while(!fStack.empty())
                        fStack.pop();
                }

                cin>>cmd;
            }

            else if(strcmp(cmd, "BACK")==0)
            {
                fStack.push(bStack.top());
                bStack.pop();

                if(!bStack.empty())
                    cout<<bStack.top() <<endl;
                else
                {
                    cout<<"Ignored" <<endl;
                    bStack.push(fStack.top());
                    fStack.pop();
                }

                 cin>>cmd;
            }

            else if(strcmp(cmd, "FORWARD")==0)
            {
                if(fStack.empty())
                    cout<<"Ignored" <<endl;
                else
                {
                    cout<<fStack.top() <<endl;
                    bStack.push(fStack.top());
                    fStack.pop();
                }

                cin>>cmd;
            }
        }
    }
    return 0;
}

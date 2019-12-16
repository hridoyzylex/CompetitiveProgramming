#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

int main()
{
    //freopen("C.txt", "r", stdin);
    int i,j,T,R,k,N,g, total, final;

    cin>>T;
    for(i=0; i<T; i++)
    {
        list <int> list1;
        list <int> list2;
        final = 0;

        cin>>R>>k>>N;
        for(j=0; j<N; j++)
        {
            cin>>g;
            list1.push_back(g);
        }

        for(j=0; j<R; j++)
        {
            total = 0;

                while((total + list1.front()<=k) && (!list1.empty()))
                {
                    total = total + list1.front();
                    list2.push_back(list1.front());
                    list1.pop_front();
                }
                //cout<<total <<endl;

                final = final + total;

                if(!list2.empty())
                {
                    while(!list2.empty())
                    {
                        list1.push_back(list2.front());
                        list2.pop_front();
                    }
                }
        }
        cout<<"Case #" <<i+1 <<": " <<final <<endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

int main()
{
    int T, M, i;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>M;

        if(M>79)
            cout<<"Case " <<i+1 <<": A+"<<endl;
        else if(M>74)
            cout<<"Case " <<i+1 <<": A"<<endl;
        else if(M>69)
            cout<<"Case " <<i+1 <<": A-"<<endl;
        else if(M>64)
            cout<<"Case " <<i+1 <<": B+"<<endl;
        else if(M>59)
            cout<<"Case " <<i+1 <<": B"<<endl;
        else if(M>54)
            cout<<"Case " <<i+1 <<": B-"<<endl;
        else if(M>49)
            cout<<"Case " <<i+1 <<": C"<<endl;
        else if(M>44)
            cout<<"Case " <<i+1 <<": D"<<endl;
        else
            cout<<"Case " <<i+1 <<": F"<<endl;



    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sorted accending  // we want to do it backward
void out(vector <int> a, int num){
    for(int i=a.size()-1;i>=num;i++){
        a[i]--;
    }

}

void isZero(vector <int> a){
    for(int j=0;j<a.size();j++){
        if(a[j]==0){
            a.erase(a.begin()+j,a.begin()+j+1);
        }
    }
}


int main(){
    int n,m;
    while(cin>>n>>m){
        int BR=-1;
        vector <int> compo,eng;

        int j,c;
        for(int i=0;i<n;i++){
            cin>>j>>c;
            for(int p=0;p<j;p++){
                compo.push_back(c);
            }
        }


        int k,d;
        for(int i=0;i<m;i++){
            cin>>k>>d;
            for(int p=0;p<k;p++){
                eng.push_back(d);
            }
        }

        sort(compo.begin(),compo.end());
        sort(eng.begin(),eng.end());

        for(int i=compo.size()-1;i>=0;i++){

            for(int u=0;u<compo[i];u++){
                //eng[]  last one --
                // if eng[XX] <0   remove that elem
                if(eng[eng.size()-1-u]<=0){
                    if(eng.size()!=1){
                        eng.erase(eng.begin()+ eng.size()-1-u , eng.begin()+ eng.size()-u);
                    }
                    else{
                        BR=0;
                        break;
                    }
                }
                eng[eng.size()-1 -u]--;
            }

            if(BR==0)   break;
        }

        if(BR==0)   cout<<0<<endl;
        else cout<<1<<endl;

    }



return 0;
}

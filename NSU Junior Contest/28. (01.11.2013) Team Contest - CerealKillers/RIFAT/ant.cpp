#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    //freopen("in.txt","rt",stdin);
    int l, a , rmin, lmax,x,ryt,lft,p,q;
    char c;
    vector<int> vv;
    while(scanf(" %d %d",&l,&a)!=EOF){
        vv.clear();
        rmin=200000;
        lmax=-1;
        lft=ryt=0;
        for(int i=0;i<a;i++){
            scanf(" %d %c",&x,&c);
            if(c=='L'){
                lmax=max(lmax,x);
                lft++;
            }else{
                rmin=min(rmin,x);
                ryt++;
            }
            vv.push_back(x);
        }
        rmin=l-rmin;
        sort(vv.begin(),vv.end());
        if(lmax>rmin){
            p=vv[lft-1];
            printf("The last ant will fall down in %d seconds - started at %d.\n",lmax,p);
        }else if(rmin>lmax){
            //cerr<<a<<" "<<ryt<<endl;
            p=vv[a-ryt];
            printf("The last ant will fall down in %d seconds - started at %d.\n",rmin,p);
        }else{
            p=vv[lft-1];
            q=vv[a-ryt];
            if(p>q){
                int bff=p;
                p=q;
                q=bff;
            }
            printf("The last ant will fall down in %d seconds - started at %d and %d.\n",lmax,p,q);
        }
    }
    return 0;
}

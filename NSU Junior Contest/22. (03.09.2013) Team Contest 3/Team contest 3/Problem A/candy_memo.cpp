#include <algorithm>
#include <set>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> best1;
vector<int> bestX;
set<int> prices;

int go(int x){
    if (x == 0){
        return 0;
    }

    if (bestX[x] != -1){
        return bestX[x];
    }

    int ans = 0;

    for (set<int>::iterator it = prices.begin(); it != prices.end(); it++){
        if (*it > x) break;
        int val = best1[*it] + go(x - *it);
        ans = max(val, ans);
    }

    return bestX[x] = ans;
}

int main(){
    while (1){
        int n, m;
        int dollars, cents;

        scanf("%d %d.%d", &n, &dollars, &cents);
        m = 100 * dollars + cents;
        if (n == 0 && m == 0) break;

        best1 = vector<int>(m + 1, -1);
        bestX = vector<int>(m + 1, -1);
        prices.clear();

        for (int i = 0; i < n; i++){
            int cal, price;
            scanf("%d %d.%d", &cal, &dollars, &cents);
            price = 100 * dollars + cents;
            best1[price] = max(cal, best1[price]);
            prices.insert(price);
        }

        printf("%d\n", go(m));
    }
    return 0;
}

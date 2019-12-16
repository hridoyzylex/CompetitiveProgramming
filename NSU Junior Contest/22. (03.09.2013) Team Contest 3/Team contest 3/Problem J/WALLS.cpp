#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

int main(){
    while (1){
        int n;
        cin >> n;
        if (n == 0) break;

        vector<pair<int, int> > P;
        for (int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            P.push_back(make_pair(x, y));
        }

        int minx, miny, maxx, maxy;
        minx = maxx = P[0].first;
        miny = maxy = P[0].second;
        for (int i = 1; i < n; i++){
            minx = min(P[i].first, minx);
            miny = min(P[i].second, miny);
            maxx = max(P[i].first, maxx);
            maxy = max(P[i].second, maxy);
        }

        for (int i = 0; i < n; i++){
            P[i].first -= minx;
            P[i].second -= miny;
        }

        maxx -= minx;
        maxy -= miny;

        int maxv = maxx / 2;
        int maxh = maxy / 2;
        int ans = -1;
        int v_, h_;

        for (int vmask = 0; vmask < (1 << maxv); vmask++){
            int h = 0, v = 0;
            vector<int> V;
            V.push_back(-1);

            for (int pos = 0; pos < maxv; pos++){
                if (vmask & (1 << pos)){
                    v++;
                    V.push_back(2 * pos + 1);
                }
            }
            V.push_back(maxx + 1);

            int a = v + 1;
            bool bad = false;
            vector<vector<int> > areas = vector<vector<int> >(a, vector<int>(maxy + 1, 0));
            for (int i = 0; i < n && !bad; i++){
                for (int j = 0; j < a; j++){
                    int start = V[j];
                    int end = V[j + 1];
                    if (start < P[i].first && P[i].first < end){
                        areas[j][P[i].second]++;
                        if (areas[j][P[i].second] == 2) bad = true;
                        break;
                    }
                }
            }

            if (bad) continue;
            int hmask = 0;

            vector<int> cnt = vector<int>(a, 0);
            for (int i = 0; i <= maxy; i+=2){
                bool two = false;
                for (int j = 0; j < a; j++){
                    if (areas[j][i]){
                        cnt[j]++;
                        if (cnt[j] == 2) two = true;
                    }
                }

                if (two){
                    h++;
                    for (int j = 0; j < a; j++){
                        cnt[j] = areas[j][i] ? 1 : 0;
                    }
                    int bit = (i - 1) / 2;
                    hmask |= (1 << bit);
                }
            }

            if (ans == -1 || ans > v + h){
                ans = v + h;
                //cout << vmask << "," << hmask << endl;
                v_ = vmask;
                h_ = hmask;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int x1 = P[i].first, y1 = P[i].second;
                int x2 = P[j].first, y2 = P[j].second;

                bool ver = false;

                for (int bit = 0; bit < maxv; bit++){
                    if (v_ & (1 << bit)){
                        int pos = 2 * bit + 1;
                        if (min(x1, x2) < pos && pos < max(x1, x2)){
                            ver = true;
                            break;
                        }
                    }
                }

                bool hor = false;

                for (int bit = 0; bit < maxh; bit++){
                    if (h_ & (1 << bit)){
                        int pos = 2 * bit + 1;
                        if (min(y1, y2) < pos && pos < max(y1, y2)){
                            hor = true;
                            break;
                        }
                    }
                }

                //cout << x1 << "," << y1 << endl;
                //cout << x2 << "," << y2 << endl;
                //cout << v_ << "+" << h_ << endl;
                assert(ver || hor);
            }
        }
        //cout << ans << "->" << v_ << "+" << h_ << endl;
        cout << ans << endl;
    }
    return 0;
}

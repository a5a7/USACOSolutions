#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int g, n;
    cin >> g >> n;
    vector<pair<int, pair<int, int>>> grazings;
    for (int i = 0; i < g; i++){
        int x, y, t;
        cin >> x >> y >> t;
        grazings.push_back({t, {x, y}});
    }
    sort(grazings.begin(), grazings.end());
    int count = 0;
    for (int cow = 0; cow < n; cow++){
        int x, y, t;
        cin >> x >> y >> t;
        bool works = false;
        int l = 0, r = g;
        while (l < r){
            int m = (l+r)/2;
            if (grazings[m].first > t){
                r = m;
            }else{
                l = m+1;
            }
        }
        if (l != g){
            ll distx = (grazings[l].second.first-x);
            distx *= distx;
            ll disty = (grazings[l].second.second-y);
            disty *= disty;
            ll distt = (grazings[l].first-t);
            distt *= distt;
            if (distt < (distx+disty)){
                works = true;   
            }
        }
        l = -1, r = g-1;
        while (l < r){
            int m = (l+r+1)/2;
            if (grazings[m].first < t){
                l = m;
            }else{
                r = m-1;
            }
        }
        if (l != -1){
            ll distx = (grazings[l].second.first-x);
            distx *= distx;
            ll disty = (grazings[l].second.second-y);
            disty *= disty;
            ll distt = (grazings[l].first-t);
            distt *= distt;
            if (distt < (distx+disty)){
                works = true;   
            }
        }
        count += works;
    }
    cout << count << endl;
}
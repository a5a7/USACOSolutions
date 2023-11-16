#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pair<ll, ll> inter[m];
    for (int i = 0; i < m; i++) cin >> inter[i].first >> inter[i].second;
    sort(inter, inter+m);
    ll left = 0;
    ll right = 1e18;
    while (left < right){
        ll mid = (left+right+1)/2;
        ll pos = -1;
        int cows = 0;
        for (int i = 0; i < m; i++){
            pos = max(inter[i].first, pos);
            while (pos <= inter[i].second) cows++, pos += mid;
            if (cows >= n) break;
        }
        if (cows >= n){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    cout << left << endl;
}
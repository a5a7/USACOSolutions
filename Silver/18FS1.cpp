#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    ll l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    vector<pair<ll, ll>> restStops;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        while (!restStops.empty() && restStops.back().second < b) restStops.pop_back();
        restStops.push_back({a, b});
    }
    ll answer = 0; ll timeUsed = 0;
    for (int i = 0; i < restStops.size(); i++){
        ll time = (rf-rb) * restStops[i].first;
        time -= timeUsed;
        answer += time * restStops[i].second;
        timeUsed += time;
    }
    cout << answer << endl;
}
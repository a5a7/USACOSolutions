#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    vector<int> t(c);
    for (int i = 0; i < c; i++) cin >> t[i];
    pair<int, int> ab[n];
    for (int i = 0; i < n; i++) cin >> ab[i].second >> ab[i].first;
    sort(t.begin(), t.end());
    sort(ab, ab+n);
    int pairs = 0;
    for (int i = 0; i < n; i++){
        int position = lower_bound(t.begin(), t.end(), ab[i].second) - t.begin();
        if (position == t.size() || t[position] > ab[i].first) continue;
        t.erase(t.begin()+position);
        pairs++;
    }
    cout << pairs << endl;
}
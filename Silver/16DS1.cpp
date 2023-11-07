#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> values;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        values.push_back(x);
    }
    sort(values.begin(), values.end());
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (upper_bound(values.begin(), values.end(), b)-lower_bound(values.begin(), values.end(), a)) << endl;
    }
}
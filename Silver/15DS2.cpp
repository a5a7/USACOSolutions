#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin >> n;
    set<int> values;
    for (int i = 1; i <= 2*n; i++) values.insert(i);
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i], values.erase(values.find(a[i]));
    int wins = 0;
    for (int i = 0; i < n; i++){
        auto it = values.upper_bound(a[i]);
        if (it != values.end()){
            values.erase(it);
            wins++;
        }else{
            values.erase(values.begin());
        }
    }
    cout << wins << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    set<int> b;
    int a[n];
    for (int i = 1; i <= 2*n; i++) b.insert(i);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b.erase(a[i]);
    }
    set<int> b2;
    for (int i = 0; i < (n/2); i++){
        b2.insert(*b.begin());
        b.erase(b.begin());
    }
    int ans = 0;
    for (int i = 0; i < (n/2); i++){
        auto it = b.upper_bound(a[i]);
        if (it != b.end()){
            ans++;
            b.erase(it);
        }
    }
    for (int i = n/2; i < n; i++){
        auto it = b2.lower_bound(a[i]);
        if (it != b2.begin()){
            ans++;
            b2.erase(prev(it));
        }
    }
    cout << ans << endl;
}
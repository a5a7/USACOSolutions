#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll answer(ll a, ll b){
    if (2*a <= b) return 1+min(answer(2*a, b), answer(a+1, b));
    if (a <= b) return (b-a);
    if (a%2 == 0) return 1+answer(a/2, b);
    if (a%2 == 1) return 1+answer(a+1, b);
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << answer(a, b) << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}
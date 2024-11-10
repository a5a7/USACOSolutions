#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        ll currMax = a[i];
        dp[i] = 0;
        for (int j = i-1; j >= 0 && j >= (i-k); j--){
            dp[i] = max(dp[j] + currMax * (i-j), dp[i]);
            currMax = max(a[j], currMax);
        }
    }
    cout << dp[n] << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int n, k; cin >> n >> k;
    int dp[n][k+1];
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = 1000000000;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++){
        int currMax = a[i];
        int sum = a[i];
        for (int l = i-1; l >= 0; l--){
            for (int j = 1; j <= k; j++){
                dp[i][j] = min(dp[l][j-1] + currMax * (i-l) - sum, dp[i][j]);
            }
            currMax = max(currMax, a[l]);
            sum += a[l];
        }
        dp[i][0] = currMax * (i+1) - sum;
    }
    cout << dp[n-1][k] << endl;
}
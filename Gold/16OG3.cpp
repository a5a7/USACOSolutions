#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int n;
    cin >> n;
    int dp[n][n];
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> dp[i][i], ans = max(ans, dp[i][i]);
    for (int i = 1; i < n; i++){
        for (int j = 0; (i+j) < n; j++){
            dp[j][i+j] = -1;
            for (int k = j; k < (i+j); k++){
                if (dp[j][k] == dp[k+1][i+j]){
                    dp[j][i+j] = max(dp[j][i+j], dp[j][k]+1);
                }
            }
            ans = max(dp[j][i+j], ans);
        }
    }
    cout << ans << endl;
}
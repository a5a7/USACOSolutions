#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;
    int dp[1+t][2];
    dp[0][0] = 1;
    int best = 0;
    for (int i = 1; i <= t; i++){
        dp[i][0] = 0;
        if (i >= a) dp[i][0] |= dp[i-a][0];
        if (i >= b) dp[i][0] |= dp[i-b][0];
        if (dp[i][0]) best = max(i, best);
    }
    for (int i = 0; i <= t; i++){
        dp[i][1] = 0;
        if ((i*2) <= t) dp[i][1] |= dp[i*2][0];
        if ((2*i)+1 <= t) dp[i][1] |= dp[i*2+1][0];
        if (i >= a) dp[i][1] |= dp[i-a][1];
        if (i >= b) dp[i][1] |= dp[i-b][1];
        if (dp[i][1]) best = max(i, best);
    }
    cout << best << endl;
}
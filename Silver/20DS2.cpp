#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    pii points[n];
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
    sort(points, points+n, [&](auto x, auto y){
        return x.second < y.second;
    });
    for (int i = 0; i < n; i++) points[i].second = i;
    sort(points, points+n);
    for (int i = 0; i < n; i++) points[i].first = i;
    int prefixSum[n+1][n+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0){
                prefixSum[i][j] = 0;
            }else{
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + (points[i-1].second == (j-1));
            }
        }
    }
    ll answer = n+1;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int u = max(points[i].second, points[j].second), d = min(points[i].second, points[j].second);
            ll cows1 = 1 + prefixSum[j+1][d] - prefixSum[j+1][0] - prefixSum[i][d] + prefixSum[i][0];
            ll cows2 = 1 + prefixSum[j+1][n] - prefixSum[j+1][u+1] - prefixSum[i][n] + prefixSum[i][u+1];
            answer += cows1 * cows2;
        }
    }
    cout << answer << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    pair<pair<int, int>, int> cows[n];
    for (int i = 0; i < n; i++) cin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
    int visited[n];
    function<void(int)> dfs = [&](int x){
        visited[x] = 1;
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            int distance = (cows[i].first.first-cows[x].first.first)*(cows[i].first.first-cows[x].first.first)+(cows[i].first.second-cows[x].first.second)*(cows[i].first.second-cows[x].first.second);
            if (distance < cows[x].second*cows[x].second){
                dfs(i);
            }
        }
    };
    int best = 1;
    for (int i = 0; i < n; i++){
        fill(visited, visited+n, 0);
        dfs(i);
        best = max(best, accumulate(visited, visited+n, 0));
    }
    cout << best << endl;
}
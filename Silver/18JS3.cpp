#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int visited[n];
    fill(visited, visited+n, 0);
    function<void(int, int)> dfs = [&](int x, int r){
        visited[x] = 1;
        for (auto next : adj[x]){
            if (visited[next.first] || next.second < r) continue;
            dfs(next.first, r);
        }
    };
    for (int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        v--;
        fill(visited, visited+n, 0);
        dfs(v, k);
        cout << (accumulate(visited, visited+n, 0)-1) << endl;
    }
}
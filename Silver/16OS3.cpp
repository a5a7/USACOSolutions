#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    int order[n];
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < n; i++) cin >> order[i], order[i]--;
    int visited[n];
    int closed[n];
    fill(closed, closed+n, 0);
    int current = 0;
    function<void(int)> dfs = [&](int x){
        visited[x] = 1;
        current++;
        for (int next : edges[x]){
            if (closed[next] || visited[next]) continue;
            dfs(next);
        }
    };
    for (int i = 0; i < n; i++){
        current = 0;
        fill(visited, visited+n, 0);
        dfs(order[n-1]);
        cout << (current == (n-i) ? "YES" : "NO") << endl;
        closed[order[i]] = 1;
    }
}
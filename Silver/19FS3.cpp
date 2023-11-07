#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        char c; int a, b;
        cin >> c >> a >> b; a--; b--;
        int x = (c == 'S') ? 0 : 1;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }
    bool works = true;
    int colors[n];
    fill(colors, colors+n, -1);
    function<void(int, int)> dfs = [&](int x, int col){
        if (!works) return;
        colors[x] = col;
        for (pair<int, int> next : adj[x]){
            if (!works) return;
            if (colors[next.first] == -1){
                dfs(next.first, col^next.second);
            }else if (colors[next.first] != col^next.second){
                works = false;
                return;
            }
        }
    };
    int count = 0;
    for (int i = 0; i < n; i++){
        if (colors[i] == -1) dfs(i, 0), count++;
    }
    if (!works){
        cout << 0 << endl;
        return 0;
    }
    cout << 1;
    for (int i = 0; i < count; i++) cout << 0; 
    cout << endl;
}
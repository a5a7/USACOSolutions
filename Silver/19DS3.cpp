#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    char type[n];
    for (int i = 0; i < n; i++) cin >> type[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < (n-1); i++){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int color[n];
    fill(color, color+n, -1);
    function<void(int, int)> dfs = [&](int x, int cl){
        color[x] = cl;
        for (int next : adj[x]){
            if (color[next] == -1 && type[next] == type[x]) dfs(next, cl);
        }
    };
    int col = 0;
    for (int i = 0; i < n; i++){
        if (color[i] == -1) dfs(i, col++);
    }
    for (int i = 0; i < m; i++){
        int a, b; char c;
        cin >> a >> b >> c; a--; b--;
        if (color[a] == color[b] && c != type[a]){
            cout << "0";
        }else cout << '1';
    }
    cout << endl;
}
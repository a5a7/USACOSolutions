#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int color[n], currentColor = 0;
    function<void(int, int)> dfs = [&](int x, int weight){
        color[x] = currentColor;
        for (pair<int, int> next : adj[x]){
            if (color[next.first] != -1) continue;
            if (next.second >= weight){
                dfs(next.first, weight);
            }
        }
    };
    int left = 0, right = 1e9+1;
    while (left < right){
        int mid = (left+right+1)/2;
        currentColor = 0;
        fill(color, color+n, -1);
        for (int i = 0; i < n; i++){
            if (color[i] == -1) dfs(i, mid), currentColor++;
        }
        bool works = true;
        for (int i = 0; i < n; i++) works &= (color[p[i]] == color[i]);
        if (works){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    if (left == (1e9+1)) left = -1;
    cout << left << endl;
}
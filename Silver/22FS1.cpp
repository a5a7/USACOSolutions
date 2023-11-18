#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adj[i].push_back(grid[i][j]);
            if (grid[i][j] == i) break;
        }
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int start = 0;
    function<void(int)> dfs = [&](int x){
        visited[start][x] = 1;
        for (int next : adj[x]){
            if (!visited[start][next]) dfs(next);
        }
    };
    for (start = 0; start < n; start++){
        dfs(start);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][grid[i][j]] && visited[grid[i][j]][i]){
                cout << grid[i][j]+1 << endl;
                break;
            }
        }
    }
}
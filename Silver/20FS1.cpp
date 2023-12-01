#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        reverse(arr+a-1, arr+b);
    }
    int cycle[n];
    fill(cycle, cycle+n, -1);
    vector<vector<int>> cycles;
    int color = 0;
    for (int i = 0; i < n; i++){
        if (cycle[i] != -1) continue;
        cycle[i] = color;
        cycles.push_back({i});
        int curr = arr[i];
        while (curr != i){
            cycle[curr] = color;
            cycles[color].push_back(curr);
            curr = arr[curr];
        }
        color++;
    }
    int answer[n];
    for (int i = 0; i < color; i++){
        for (int j = 0; j < cycles[i].size(); j++){
            answer[cycles[i][j]] = cycles[i][(j+k)%cycles[i].size()];
        }
    }
    for (int i = 0; i < n; i++) cout << (answer[i]+1) << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    int cycle[n];
    fill(cycle, cycle+n, -1);
    function<void(int)> dfs = [&](int x){
        if (cycle[x] == 1){
            cycle[x] = 2;
            dfs(a[x]);
            return;
        }else if (cycle[x] == 2){
            return;
        }
        cycle[x] = 1;
        dfs(a[x]);
        if (cycle[x] != 2) cycle[x] = 0;
    };
    for (int i = 0; i < n; i++){
        if (cycle[i] == -1) dfs(i);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += cycle[i] == 2 ? 1 : 0;
    cout << sum << endl;
}
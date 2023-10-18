#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    int deg[n]; fill(deg, deg+n, 0);
    for (int i = 1; i < n; i++){
        int a, b; cin >> a >> b; a--; b--; deg[a]++; deg[b]++;
    }
    cout << (1+(*max_element(deg, deg+n))) << endl;
}
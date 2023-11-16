#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int t1, t2;
    t1 = t2 = 0;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if (a == b) continue;
        if (a == 1 && b == 2) t1++;
        if (a == 2 && b == 3) t1++;
        if (a == 3 && b == 1) t1++;
        if (a == 1 && b == 3) t2++;
        if (a == 2 && b == 1) t2++;
        if (a == 3 && b == 2) t2++;
    }
    cout << max(t1, t2) << endl;
}
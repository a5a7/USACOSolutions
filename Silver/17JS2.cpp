#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int p[n+1];
    int h[n+1];
    int s[n+1];
    p[0] = h[0] = s[0] = 0;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        p[i+1] = p[i];
        h[i+1] = h[i];
        s[i+1] = s[i];
        if (c == 'P') p[i+1]++;
        if (c == 'H') h[i+1]++;
        if (c == 'S') s[i+1]++;
    }
    int best = 0;
    for (int i = 0; i <= n; i++) best = max(best, max({p[i], h[i], s[i]})+max({p[n]-p[i], h[n]-h[i], s[n]-s[i]}));
    cout << best << endl;
}
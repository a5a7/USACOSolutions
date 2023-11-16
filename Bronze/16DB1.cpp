#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int a, b, c, d;
    int e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int inter1 = max(c, g) - min(a, e);
    int inter2 = max(d, h) - min(b, f);
    int best = max(inter1, inter2);
    cout << best*best << endl;
}
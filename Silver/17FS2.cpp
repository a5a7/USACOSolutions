#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b; cin >> n >> k >> b;
    int a[n]; fill(a, a+n, 1);
    for (int i = 0; i < b; i++){
        int x; cin >> x; x--;
        a[x]--;
    }
    int prefix[n+1]; prefix[0] = 0;
    int work = 0;
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + a[i];
    for (int i = k; i <= n; i++) work = max(prefix[i]-prefix[i-k], work);
    cout << (k-work) << endl;
}
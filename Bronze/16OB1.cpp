#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int right = 0;
    int best = 0;
    for (int left = 0; left < n; left++){
        while (right < n && (a[right]-a[left]) <= k) right++;
        best = max(best, right-left);
    }
    cout << best << endl;
}
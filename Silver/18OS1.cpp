#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a, a+n);
    int maxi = 0;
    for (int i = 0; i < n; i++) maxi = max(maxi, a[i].second-i);
    cout << maxi+1 << endl;
}
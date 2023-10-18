#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int count = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= i) count++;
    }
    cout << count << endl;
}
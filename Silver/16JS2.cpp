#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    int arr[7] = {-1, -1, -1, -1, -1, -1, -1};
    arr[0] = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x; a[i+1] = (a[i]+x)%7;
        if (arr[a[i+1]] == -1) arr[a[i+1]] = i+1;
    }
    int maxsize = 0;
    for (int i = 0; i <= n; i++) maxsize = max(maxsize, i-arr[a[i]]);
    cout << maxsize << endl;
}
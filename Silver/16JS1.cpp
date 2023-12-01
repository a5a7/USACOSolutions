#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int left = 0;
    int right = a[n-1]-a[0];
    while (left < right){
        int mid = (left+right)/2;
        int done = -1;
        int needed = 0;
        for (int i = 0; i < n; i++){
            if (a[i] > done){
                done = a[i] + 2 * mid;
                needed++;
            }
        }
        if (needed <= k){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    cout << left << endl;
}
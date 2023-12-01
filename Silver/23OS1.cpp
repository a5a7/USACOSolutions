#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    pair<ll, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a, a+n);
    int reverse[n];
    ll original = 0;
    for (int i = 0; i < n; i++) reverse[a[i].second] = i, original += (i+1) * a[i].first;
    ll rsum[n+1];
    rsum[n] = 0;
    for (int i = n-1; i > -1; i--) rsum[i] = rsum[i+1] + a[i].first;
    int q;
    cin >> q;
    while (q--){
        int i; ll j; 
        cin >> i >> j;
        i--;
        int left = 0, right = n;
        while (left < right){
            int mid = (left+right)/2;
            if (a[mid].first > j){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        ll answer = original - rsum[reverse[i]] - reverse[i] * a[reverse[i]].first + rsum[left] - (left <= reverse[i] ? a[reverse[i]].first : 0) + (left+1) * j;
        if (reverse[i] < left) answer -= j;
        cout << answer << endl;
    }
}
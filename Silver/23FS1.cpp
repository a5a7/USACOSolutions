#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, tc, tm;
    cin >> n >> tc >> tm;
    ll a[n], b[n], c[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    ll left = 0;
    ll right = tc + tm;
    while (left < right){
        ll mid = (left+right+1)/2;
        bool works = true;
        ll minA = tc;
        ll minB = tm;
        for (int i = 0; i < n && works; i++){
            if (a[i] == b[i]){
                if (mid * a[i] > c[i]) works = false;
            }else if (a[i] > b[i]){
                ll res = (c[i] - mid * b[i])/(a[i]-b[i]);
                if (res <= 0) works = false;
                minA = min(minA, res);
            }else{
                ll res = (c[i] - mid * a[i])/(b[i]-a[i]);
                if (res <= 0) works = false;
                minB = min(minB, res);
            }
        }
        if ((minA+minB) < mid) works = false;
        if (works){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    cout << (tc+tm-left) << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}
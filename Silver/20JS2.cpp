#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    ll n, k, m;
    cin >> n >> k >> m;
    ll left = 1;
    ll right = n;
    while (left < right){
        ll x = (left+right+1)/2;
        ll days = 0;
        ll g = 0;
        while (g < n){
            ll y = (n-g)/x;
            if (y <= m){
                days += 1 + (n-g-1)/m;
                break;
            }
            ll plus = 1+((n-x*y)-g-1)/y;
            g += plus * y;
            days += plus;
        }
        if (days <= k){
            left = x;
        }else{
            right = x - 1;
        }
    }
    cout << left << endl;
}
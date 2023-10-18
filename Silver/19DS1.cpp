#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    ll n;
    cin >> n;
    ll left = 1;
    ll right = 1e18;
    while (left < right){
        ll mid = (left+right+1)/2;
        ll place = mid - (mid/3) - (mid/5) + (mid/15);
        if (place <= n){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    while (left%3 == 0 || left%5 == 0) left--;
    cout << left << endl;
}
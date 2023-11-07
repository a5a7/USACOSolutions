#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int left = 1, right = n+1;
    while (left < right){
        int mid = (left+right)/2;
        multiset<int> values;
        for (int i = 0; i < mid; i++) values.insert(a[i]);
        for (int i = mid; i < n; i++){
            int s =*values.begin();
            values.erase(values.begin());
            values.insert(s+a[i]);
        }
        int t_m = *--values.end();
        if (t_m <= t){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    cout << left << endl;
}

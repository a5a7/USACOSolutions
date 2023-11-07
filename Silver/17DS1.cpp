#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++ ) cin >> a[i];
    ll sum = accumulate(a, a+n, 0);
    ll mini[n]; mini[n-1] = a[n-1];
    for (int i = n-2; i > -1; i--) mini[i] = min(mini[i+1], a[i]);
    double maxi = 0;
    vector<int> bestIndex;
    for (int i = 0; i < (n - 2); i++){
        sum -= a[i];
        ll newSum = sum - mini[i+1];
        double result = double(newSum)/double(n-i-2);
        if (result > maxi){
            maxi = result;
            bestIndex.clear();
            bestIndex.push_back(i+1);
        }else if (result == maxi){
            bestIndex.push_back(i+1);
        }
    }
    for (int x : bestIndex) cout << x << endl;
}
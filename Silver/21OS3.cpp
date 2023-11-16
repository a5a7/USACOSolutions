#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, k, l;
    cin >> n >> k >> l;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int left = -1, right = n;
    while (left < right){
        int mid = (left+right+1)/2;
        bool works = true;
        ll citations = ll(k) * l;
        for (int i = 0; i < mid; i++){
            if (a[i] >= mid) continue;
            if ((a[i]+k) < mid) works = false;
            citations -= (mid-a[i]);
            if (citations < 0) works = false;
            if (!works) break;
        }
        if (works){
            left = mid;
        }else{
            right = mid-1;
        }
    }
    cout << left << endl;
}
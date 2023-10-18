#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int right = 0;
    int next[n];
    for (int left = 0; left < n; left++){
        while (right < n && (a[right]-a[left]) <= k) right++;
        next[left] = right;
    }
    int maxi[n];
    maxi[n-1] = next[n-1]-n-1;
    for (int i = n-2; i > -1; i--) maxi[i] = max(next[i]-i, maxi[i+1]);
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (next[i] == n) {answer = max(answer, n-i); break;}
        answer = max(answer, next[i]-i+maxi[next[i]]);
    }
    cout << answer << endl;
}
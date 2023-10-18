#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> c[n];
    for (int i = 0; i < n; i++) cin >> c[i].second >> c[i].first;
    sort(c, c+n);
    int left = 0;
    int right = n-1;
    int maxi = 0;
    while (left < right){
        maxi = max(maxi, c[left].first+c[right].first);
        if (c[left].second == c[right].second){
            left++, right--;
        }else if (c[left].second < c[right].second){
            c[right].second -= c[left].second, left++;
        }else{
            c[left].second -= c[right].second, right--;
        }
        if (left == right){
            maxi = max(maxi, c[left].first * 2);
        }
    }
    cout << maxi << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int, int> point[n];
    for (int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;
    sort(point, point+n, [&](auto x, auto y){
        if (x.first == y.first){
            return x.second < y.second;
        }
        return x.first < y.first;
    });
    int answer = 0;
    int minimumBound = int(1e9+1);
    for (int i = 0; i < n; i++){
        cout << point[i].first << " " << point[i].second << endl;
        if (point[i].second >= minimumBound) continue;
        minimumBound = point[i].second;
        answer++;
    }
    cout << answer << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> mountains;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mountains.push_back({x-y, x+y});
    }
    sort(mountains.begin(), mountains.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first == y.first) return x.second > y.second;
        return x.first < y.first;
    });
    int count = 1;
    int start = mountains[0].second;
    for (int i = 1; i < n; i++){
        if (mountains[i].second > start){
            count++;
            start = mountains[i].second;
        }
    }
    cout << count << endl;
}
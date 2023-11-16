#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[k], b[k];
    for (int i = 0; i < k; i++) cin >> a[i] >> b[i], a[i]--, b[i]--;
    vector<set<int>> locations(n);
    int loc[n];
    for (int i = 0; i < n; i++) loc[i] = i, locations[i].insert(i);
    for (int i = 0; i < k; i++){
        locations[loc[a[i]]].insert(b[i]);
        locations[loc[b[i]]].insert(a[i]);
        int x = loc[a[i]];
        loc[a[i]] = loc[b[i]];
        loc[b[i]] = x;
    }
    int answer[n];
    fill(answer, answer+n, -1);
    for (int i = 0; i < n; i++){
        if (answer[i] != -1) continue;
        set<int> results;
        for (int x : locations[i]) results.insert(x);
        int curr = loc[i];
        vector<int> places = {i};
        while (curr != i){
            for (int x : locations[curr]) results.insert(x);
            places.push_back(curr);
            curr = loc[curr];
        }
        for (int x : places) answer[x] = results.size();
    }
    for (int i = 0; i < n; i++) cout << answer[i] << endl;
}
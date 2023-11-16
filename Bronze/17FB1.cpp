#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    int n;
    cin >> n;
    int ids[10];
    fill(ids, ids+10, -1);
    int crossings = 0;
    for (int i = 0; i < n; i++){
        int id, side; cin >> id >> side; id--;
        if (ids[id] != -1 && ids[id] != side) crossings++;
        ids[id] = side;
    }
    cout << crossings << endl;
}
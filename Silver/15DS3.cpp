#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    int prefix[n][3];
    prefix[0][0] = prefix[0][1] = prefix[0][2] = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a; a--;
        prefix[i+1][0] = prefix[i][0] + (a == 0);
        prefix[i+1][1] = prefix[i][1] + (a == 1);
        prefix[i+1][2] = prefix[i][2] + (a == 2);
    }
    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << (prefix[b][0]-prefix[a-1][0]) << " ";
        cout << (prefix[b][1]-prefix[a-1][1]) << " ";
        cout << (prefix[b][2]-prefix[a-1][2]) << endl;
    }
}
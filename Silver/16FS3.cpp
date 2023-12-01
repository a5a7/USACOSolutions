#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    vector<vector<int>> arr(x+1, vector<int>(y+1, 0));
    vector<vector<int>> arr2(x+1, vector<int>(y+1, 0));
    arr[0][0] = 1;
    for (int i = 0; i < k; i++){
        for (int j = 0; j <= x; j++){
            for (int k = 0; k <= y; k++){
                if (!arr[j][k]) continue;
                arr2[x][k] = 1;
                arr2[j][y] = 1;
                arr2[0][k] = 1;
                arr2[j][0] = 1;
                arr2[min(j+k, x)][max(0, j+k-x)] = 1;
                arr2[max(0, j+k-y)][min(j+k, y)] = 1;
            }
        }
        for (int j = 0; j <= x; j++){
            for (int k = 0; k <= y; k++){
                arr[j][k] |= arr2[j][k];
            }
        }
    }
    int diff = x + y;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            if (!arr[i][j]) continue;
            int ab = max(i+j-m, m-i-j);
            diff = min(diff, ab);
        }
    }
    cout << diff << endl;
}
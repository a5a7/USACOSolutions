#include <bits/stdc++.h>
using namespace std;

struct Data{
    int x1=1001, x2=-1, y1=1001, y2=-1;
    bool works = true;
    void point(int x, int y){
        x1 = min(x, x1);
        x2 = max(x, x2);
        y1 = min(y, y1);
        y2 = max(y, y2);
    }
};

int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    Data works[n*n];
    int prefix[n+1][n+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            prefix[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 0) continue;
            works[grid[i][j]-1].point(i, j);
        }
    }
    int possible = 0;
    for (int i = 0; i < n*n; i++){
        if (works[i].x1 == 1001) continue;
        prefix[works[i].x1][works[i].y1]++;
        prefix[works[i].x1][works[i].y2+1]--;
        prefix[works[i].x2+1][works[i].y1]--;
        prefix[works[i].x2+1][works[i].y2+1]++;
        possible++;
    }
    if (possible == 1){
        cout << (n*n-1) << endl;
        return 0;
    }
    int density[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 && j == 0){
                density[i][j] = prefix[0][0];
            }else if (i == 0){
                density[i][j] = prefix[i][j] + density[i][j-1];
            }else if (j == 0){
                density[i][j] = prefix[i][j] + density[i-1][j];
            }else{
                density[i][j] = prefix[i][j] + density[i][j-1] + density[i-1][j] - density[i-1][j-1];
            }
        }
    }
    int answer = n*n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 0) continue;
            if (density[i][j] == 1) continue;
            answer -= works[grid[i][j]-1].works;
            works[grid[i][j]-1].works = false;
        }
    }
    cout << answer << endl;
}
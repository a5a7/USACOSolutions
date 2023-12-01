#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int area = 0;
    int perimeter = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    function<void(int, int)> floodFill = [&](int x, int y){
        area++;
        visited[x][y] = 1;
        if (x > 0 && grid[x-1][y] == '#' && visited[x-1][y] == 0){
            floodFill(x-1, y);
        }
        if (y > 0 && grid[x][y-1] == '#' && visited[x][y-1] == 0){
            floodFill(x, y-1);
        }
        if (x < (n-1)&& grid[x+1][y] == '#' && visited[x+1][y] == 0){
            floodFill(x+1, y);
        }
        if (y < (n-1) && grid[x][y+1] == '#' && visited[x][y+1] == 0){
            floodFill(x, y+1);
        }
        perimeter += 4;
        if (x > 0 && grid[x-1][y] == '#') perimeter--;
        if (y > 0 && grid[x][y-1] == '#') perimeter--;
        if (x < (n-1) && grid[x+1][y] == '#') perimeter--;
        if (y < (n-1) && grid[x][y+1] == '#') perimeter--;
    };
    int largestArea = 0;
    int bestPerimeter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '.') continue;
            if (visited[i][j]) continue;
            area = perimeter = 0;
            floodFill(i, j);
            if (area > largestArea){
                largestArea = area;
                bestPerimeter = perimeter;
            }else if (area == largestArea){
                bestPerimeter = min(perimeter, bestPerimeter);
            }
        }
    }
    cout << largestArea << " " << bestPerimeter << endl;
}
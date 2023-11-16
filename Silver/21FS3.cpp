#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    function<ll(int)> calculate = [&](int depth){
        int sum[n];
        ll total = 0;
        for (int i = 0; i < n; i++){
            fill(sum, sum+n, 0);
            for (int j = i; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (grid[j][k] < depth) sum[k]--;
                }
                ll count = 0;
                for (int k = 0; k < n; k++){
                    if (sum[k] == 0){
                        total += ++count;
                    }else{
                        count = 0;
                    }
                }
            }
        }
        return total;
    };
    cout << calculate(100)-calculate(101) << endl;
}
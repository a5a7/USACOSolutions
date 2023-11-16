#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int r[n][n];
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            cin >> r[i][j];
        }
    }
    int a[n];
    a[0] = 0;
    a[1] = r[0][1];
    for (int i = 2; i < n; i++){
        a[i] = a[i-1] + r[i-1][i];
        bool works = true; int maxi = a[i], mini = a[i];
        for (int j = i; j >= 0; j--){
            maxi = max(maxi, a[j]), mini = min(mini, a[j]);
            if ((maxi-mini) != r[j][i]){
                works = false;
                break;
            }
        }
        if (!works) a[i] = a[i-1] - r[i-1][i];
    }
    for (int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
}
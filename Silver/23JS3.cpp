#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int current = 0;
    string route = "";
    while (!(current == 0 && a[0] == 0)){
        while (current < n && a[current] > 0){
            a[current]--;
            current++;
            route += 'R';
        }
        while (current > 0 && (current == n || a[current] < a[current-1])){
            current--;
            a[current]--;
            route += 'L';
        }
    }
    cout << route << endl;
}
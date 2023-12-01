#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int blasted[n];
    function<void(int, int)> simulate = [&](int x, int radius){
        blasted[x] = 1;
        vector<int> toblast;
        for (int i = 0; i < n; i++){
            if (blasted[i]) continue;
            if (abs(a[i]-a[x]) <= radius){
                blasted[i] = 1;
                toblast.push_back(i);
            }
        }
        for (int x : toblast) simulate(x, radius+1);
    };
    int answer = 0;
    for (int i = 0; i < n; i++){
        fill(blasted, blasted+n, 0);
        simulate(i, 1);
        int total = accumulate(blasted, blasted+n, 0);
        answer = max(answer, accumulate(blasted, blasted+n, 0));
    }
    cout << answer << endl;
}
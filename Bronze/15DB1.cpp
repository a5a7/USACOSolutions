#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (d-c+b-a - max(0, min(b, d)-max(a, c))) << endl;
}
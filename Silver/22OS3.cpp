#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    int prefix[3][n+1];
    prefix[0][0] = prefix[1][0] = prefix[2][0] = 0;
    for (int i = 1; i <= n; i++){
        prefix[0][i] = prefix[0][i-1];
        prefix[1][i] = prefix[1][i-1];
        prefix[2][i] = prefix[2][i-1];
        if (s[i-1] == 'C') prefix[0][i] = prefix[0][i-1]+1;
        if (s[i-1] == 'O') prefix[1][i] = prefix[1][i-1]+1;
        if (s[i-1] == 'W') prefix[2][i] = prefix[2][i-1]+1;
    }
    while (q--){
        int l, r; cin >> l >> r;
        int cs = prefix[0][r] - prefix[0][l-1];
        int os = prefix[1][r] - prefix[1][l-1];
        int ws = prefix[2][r] - prefix[2][l-1];
        if (os%2 == ws%2 && os%2 != cs%2){
            cout << "Y";
        }else{
            cout << "N";
        }
    }
    cout << endl;
}

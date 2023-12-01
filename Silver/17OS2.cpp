#include <bits/stdc++.h>
using namespace std;

int func(char c){
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
}

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int spotty[n][m];
    int plain[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            spotty[i][j] = func(c);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            plain[i][j] = func(c);
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++){
        for (int j = i+1; j < m; j++){
            for (int k = j+1; k < m; k++){
                int bases[64];
                fill(bases, bases+64, 0);
                for (int l = 0; l < n; l++){
                    int base = spotty[l][i] * 16 + spotty[l][j] * 4 + spotty[l][k];
                    bases[base] = 1;
                }
                bool works = true;
                for (int l = 0; l < n; l++){
                    int base = plain[l][i] * 16 + plain[l][j] * 4 + plain[l][k];
                    works &= !bases[base]; 
                }
                answer += works;
            }
        }
    }
    cout << answer << endl;
}
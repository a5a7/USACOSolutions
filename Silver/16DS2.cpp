#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    cin >> n;
    map<string, ll> m;
    ll answer = 0;
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        string s3 = s1.substr(0, 2);
        if (s3 == s2) continue;
        answer += m[s2+s3];
        m[s3+s2]++;
    }
    cout << answer << endl;
}
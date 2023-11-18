#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    string s; ll position;
    cin >> s >> position;
    ll len = s.size();
    while (len < position) len *= 2;
    while (len > s.size()){
        ll bre = len/2ll;
        if (position > bre){
            position -= bre;
            position += (bre-1ll);
            position %= bre;
            if (position == 0ll) position = bre;
        }
        len -= bre;
    }
   cout << s[position-1] << endl;
}
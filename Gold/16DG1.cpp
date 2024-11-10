#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    int n;
    vector<int> s;
    DSU(int x){
        n = x;
        s = vector<int>(x, -1);
    }
    int get(int a){
        return s[a] < 0 ? a : s[a] = get(s[a]);
    }
    bool same(int a, int b){
        return get(a) == get(b);
    }
    void join(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;
        if (s[b] < s[a]) swap(a, b);
        s[a] += s[b];
        s[b] = a;
    }
};

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    pair<ll,ll> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<pair<ll,pair<int,int>>> v;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            v.push_back({(a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second), {i,j}});
        }
    }
    sort(v.begin(), v.end());
    ll curr = 0;
    DSU d(n);
    for (int i = 0; i < (int) v.size(); i++){
        if (!d.same(v[i].second.first, v[i].second.second)){
            curr = v[i].first;
            d.join(v[i].second.first, v[i].second.second);
        }
    }
    cout << curr << endl;
}
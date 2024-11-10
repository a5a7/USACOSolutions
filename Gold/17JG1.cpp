#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using indexedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int n;
    cin >> n;
    int a[n], l, r;
    indexedset<pair<int,int>> st;
    indexedset<pair<int,int>> en;
    for (int i = 0; i < n; i++) cin >> a[i], en.insert({a[i], i});
    int cnt = 0;
    for (int i = 0; i < n; i++){
        en.erase({a[i], i});
        r = en.size() - en.order_of_key({a[i], i});
        l = st.size() - st.order_of_key({a[i], i});
        if (l > r) swap(l, r);
        if (2*l < r) cnt++;
        st.insert({a[i], i});
    }
    cout << cnt << endl;
}
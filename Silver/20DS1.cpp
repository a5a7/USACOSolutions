#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int children[n];
    fill(children, children+n, 0);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        children[a-1]++, children[b-1]++;
    }
    int answer = n-1;
    for (int i = 0; i < n; i++){
        if (i == 0 || children[i] > 1){
            int a = 1;
            if (i != 0) children[i]--;
            while (a < (children[i]+1)) a *= 2, answer++;
        }
    }
    cout << answer << endl;
}
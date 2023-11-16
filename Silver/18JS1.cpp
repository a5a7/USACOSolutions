#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> points[n];
    for (int i = 0; i < n; i++) cin >> points[i].second >> points[i].first;
    map<int, int> inter;
    int totalTime = 0;
    int covered[n]; fill(covered, covered+n, 0);
    int pointer = 0;
    for (int i = 0; i < n; i++) inter[points[i].second]++, inter[points[i].first]--;
    int current = 0; int prev = 0;
    sort(points, points+n);
    for (pair<int, int> intervals : inter){
        if (current != 0){
            totalTime += intervals.first - prev;
        }
        if (current == 1){
            while (pointer < n && points[pointer].first < intervals.first) pointer++;
            if (pointer != n){
                covered[pointer] += intervals.first - prev;
            }
        }
        current += inter[intervals.first];
        prev = intervals.first;
    }
    cout << (totalTime-*min_element(covered, covered+n)) << endl;
}
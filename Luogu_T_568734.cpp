#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    vector<pair<int,int>> d(a);
    for (int e = 0; e < a; e++) cin >> d[e].first;
    for (int e = 0; e < a; e++) cin >> d[e].second;
    sort(d.begin(), d.end());
    d.push_back({c, 0});
    int f = 0, g = 0;
    long long h = b;
    priority_queue<int> i;
    for (int e = 0; e < d.size(); e++){
        int j = d[e].first - g;
        h -= j;
        while(h < 0 && !i.empty()){
            h += i.top();
            i.pop();
            f++;
        }
        if(h < 0){
            cout << -1 << "\n";
            return 0;
        }
        g = d[e].first;
        i.push(d[e].second);
    }
    cout << f << "\n";
    return 0;
}

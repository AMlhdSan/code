#include <bits/stdc++.h>
using namespace std;

enum class node {
    ex, 
    al, 
    lo,      
    hi,   
    np  
};

node wk(int sc) {
    if (sc == 0) {
        return node::ex;
    } else if (sc <= 24) {
        return node::al;
    } else if (sc <= 44) {
        return node::lo;
    } else if (sc <= 84) {
        return node::hi;
    } else {
        return node::np;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> cnt(5, 0);
    vector<int> scores = {a, b, c};
    for (int s : scores) {
        node st = wk(s);
        cnt[(int)st]++;
    }

    int excnt   = cnt[(int)node::ex];
    int alcnt = cnt[(int)node::al];
    int locnt         = cnt[(int)node::lo];
    int hicnt        = cnt[(int)node::hi];
    int npcnt    = cnt[(int)node::np];


    bool cond1 = (hicnt == 1 && locnt == 1 && alcnt == 1);


    bool cond2 = (npcnt == 1 && hicnt == 1 && locnt == 1);


    bool cond3 = (npcnt == 2 && (locnt == 1 || hicnt == 1));

    bool cond4 = (npcnt == 3);

    if (cond1 || cond2 || cond3 || cond4) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}

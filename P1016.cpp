#include <iostream>
using namespace std;

int n;
double s, c, l;
double d[10], p[10];
int noww = 1;
double cost = 0;
double leave = 0;

void funktion(int po) {
    // 找出最小油价位置
    if(po == n + 2) {
        return ;
    }
    int lo = po + 1;
    double minnn = 999999.99999;
    for(int i = po + 1; i <= n + 2; ++i) {
        if(p[i] < minnn) {
            lo = i;
            minnn = p[i];
        }
    }
    if(l * c >= d[lo] - d[po]) {
        cost += ((d[lo] - d[po]) / l - leave) * p[po];
        noww = lo;
        leave = 0;
        funktion(lo);
    }
}

int main() {
    
    cin >> s >> c >> l >> p[1] >> n;

    d[1] = 0;
    d[n + 2] = s;

    for(int i = 2; i <= n + 1; ++i) {
        cin >> d[i] >> p[i];
    }
    
    // 判断是否能到达目的地

    for(int i = 1; i <= n + 1; ++i) {
        if(c * l < d[i + 1] - d[i]) {
            cout << "No Solution" << endl;
            return 0;
        }
    }

    // 计算最小费用
    funktion(noww);
    /*
    for(int i = 1; i <= n + 2; ++i) {
        for(int j = i + 1; j <= n + 2; ++i) {
            if(p[j] < p[i]) {
                if(l * c >= d[j] - d[i]) {
                    cost += ((d[j] - d[i]) / l - leave) * p[i];
                    noww = d[j];
                    leave = 0;
                }
                else {
                    while()
                }
            }
        }
    }
    */
    
    return 0;
}
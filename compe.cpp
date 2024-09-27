#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][9];
double avg[9];
int sum[1001];
double location[1001][9];
double tt[1001][9];
double summ[1001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5] >> a[i][6] >> a[i][7] >> a[i][8];
        for(int j = 1; j <= 8; ++j) {
            avg[j] += a[i][j];
        }
        sum[i] = a[i][1] + a[i][2] + a[i][3] + a[i][4] + a[i][5] + a[i][6] + a[i][7] + a[i][8];
    }

    for(int j = 1; j <= 8; ++j) {
        avg[j] /= n * 1.0;
        for(int i = 1; i <= n; ++i) {
            tt[i][j] += abs(a[i][j] - avg[j]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 8; ++j) {
            if(tt[i][j] == 0) {
                location[i][j] = 0;
            } 
            else {
                tt[i][j] /= n * 1.0;
                location[i][j] = ((double)a[i][j] - avg[j]) / tt[i][j];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 3; ++j) {
            summ[i] += location[i][j];
        }
        for(int j = 4; j <= 8; ++j) {
            summ[i] += location[i][j] * 0.8;
        }
    }
    sort()
    return 0;
}
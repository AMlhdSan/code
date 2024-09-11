#include<iostream>
using namespace std;

int n;
int a[6];
int t[10][10][10][10][10];
int cnt = 0;

int main() {

    cin >> n;
    memset(t, 0, sizeof(t));

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= 5; ++i) {
            cin >> a[i];
        }
        for(int i = 1; i <= 9; ++i) {
            ++t[(a[1] + i) % 10][a[2]][a[3]][a[4]][a[5]];
            ++t[a[1]][(a[2] + i) % 10][a[3]][a[4]][a[5]];
            ++t[a[1]][a[2]][(a[3] + i) % 10][a[4]][a[5]];
            ++t[a[1]][a[2]][a[3]][(a[4] + i) % 10][a[5]];
            ++t[a[1]][a[2]][a[3]][a[4]][(a[5] + i) % 10];
            ++t[(a[1] + i) % 10][(a[2] + i) % 10][a[3]][a[4]][a[5]];
            ++t[a[1]][(a[2] + i) % 10][(a[3] + i) % 10][a[4]][a[5]];
            ++t[a[1]][a[2]][(a[3] + i) % 10][(a[4] + i) % 10][a[5]];
            ++t[a[1]][a[2]][a[3]][(a[4] + i) % 10][(a[5] + i) % 10];
        }
    }
    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int k = 0; k <= 9; ++k) {
                for(int l = 0; l <= 9; ++l) {
                    for(int m = 0; m <= 9; ++m) {
                        if(t[i][j][k][l][m] == n)
                            ++cnt;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
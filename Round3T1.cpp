#include <bits/stdc++.h>

#define MAXX 10000000000
#define MAX 2155

using namespace std;

int T;
long long a[MAX + 200][MAX + 200];
long long top[MAX + 200];
long long tl, tr;
long long minc, maxc;
long long sum = 0;
long long tmp1, tmp2;
long long minl, maxl;

inline int intread() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') 
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline long long llread() {
    long long x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void init() {
    for(long long i = 1; i <= MAX; ++i) {
        for(long long j = 1; j <= MAX; ++j) {
            if((i * i * i % 10 + j * j * j % 10) % 10 == 3) {
                a[i][++top[i]] = j;
            }
        }
    }
    return ;
}

long long mlower_bound(long long p, long long tar) {
    long long l = 1, r = min(top[tar], tr);
    long long mid = (l + r) >> 1;
    while(l < r) {
        if(a[tar][mid] * a[tar][mid] * a[tar][mid] < p || a[tar][mid] < tl) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
        mid = (l + r) >> 1;
    }
    return l;
}

long long mupper_bound(long long p, long long tar) {
    long long l = 1, r = min(top[tar], tr);
    long long mid = (l + r) >> 1;
    while(l < r) {
        if(a[tar][mid] * a[tar][mid] * a[tar][mid] <= p || a[tar][mid] < tl) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
        mid = (l + r) >> 1;
    }
    return l;
}

long long solve(long long sl, long long sr, long long p) {
    if(sl <= 0) {
        sl = 1;
    }
    tmp1 = mlower_bound(sl, p);
    tmp2 = mupper_bound(sr, p) - 1;
    return (tmp2 - tmp1 + 1);
}

int main() {

    init();

    T = intread();

    while(T--) {
        sum = 0;
        tl = llread();
        tr = llread();
        minc = tl * 10 + 3;
        maxc = tr * 10 + 3;

        for(long long i = tl; i <= tr; ++i) {
            if(i * i * i > maxc || i > MAX + 10)
                break;
            sum += solve(minc - i * i * i, maxc - i * i * i, i);
        }
        printf("%lld\n", sum);
    }

    return 0;
}
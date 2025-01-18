#include <bits/stdc++.h>
using namespace std;

#define N 1000100

#define int long long

int n, maxn, minn, top1, top2, ans;
int a[N], Lb[N], Rb[N], Ls[N], Rs[N];
int st1[N], st2[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        a[i] = read();
    top1 = 0, top2 = 0;
    for(int i = 1; i <= n; i++) {
        while(top1 && a[st1[top1]] > a[i]) 
            top1--;
        while(top2 && a[st2[top2]] < a[i]) 
            top2--;
        if(!top1) 
            Ls[i] = 0;
        else 
            Ls[i] = st1[top1];
        if(!top2) 
            Lb[i] = 0;
        else 
            Lb[i] = st2[top2];
        st1[++top1] = i;
        st2[++top2] = i;
    }
    memset(st1, 0, sizeof(st1));
    memset(st2, 0, sizeof(st2));
    top1 = 0, top2 = 0;
    for(int i = n; i >= 1; i--) {
        while(top1 && a[st1[top1]] >= a[i]) 
            top1--;
        while(top2 && a[st2[top2]] <= a[i]) 
            top2--;
        if(!top1) 
            Rs[i] = n+1;
        else 
            Rs[i] = st1[top1];
        if(!top2) 
            Rb[i] = n+1;
        else 
            Rb[i] = st2[top2];
        st1[++top1] = i;
        st2[++top2] = i;
    }
    for (int i = 1; i <= n; i++) {
        ans += (i - Lb[i]) * (Rb[i] - i) * a[i];
        ans -= (i - Ls[i]) * (Rs[i] - i) * a[i];
    }

    cout << ans;

    return 0;
}
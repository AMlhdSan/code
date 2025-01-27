#include <bits/stdc++.h>

#define N 5010

using namespace std;

int L,W;
int n;
int ans;

struct node {
	int x, y;
}a[N];

bool cmp1(node a, node b) {
    return ((a.x == b.x) ? (a.y < b.y) : (a.x < b.x));
}
bool cmp2(node a, node b) {
    return ((a.y == b.y) ? (a.x < b.x) : (a.y < b.y));
}

inline int read() {
    int x = 0, f = 1; 
    char ch = getchar();
    while(ch < '0' || ch > '9') { 
        if(ch == '-')
            f = -1;
        ch = getchar(); 
    }
    while(ch >= '0' && ch <= '9') { 
        x = (x << 3) + (x << 1) + (ch ^ 48); 
        ch = getchar(); 
    }
    return x * f;
}

int main() {
	L = read();
    W = read();
    n = read();
	
    for(int i = 1; i <= n; ++i) {
        a[i].x = read();
        a[i].y = read();
    }

    a[n + 1].x = 0;
    a[n + 1].y = 0;
    a[n + 2].x = 0;
    a[n + 2].y = W;
    a[n + 3].x = L;
    a[n + 3].y = 0;
    a[n + 4].x = L;
    a[n + 4].y = W;

    sort(a + 1, a + n + 4 + 1, cmp1);
	
    for(int i = 1; i <= n + 4; ++i) {
        int l = 0, r = W, cnt = i + 1;
        
        while(a[cnt].x == a[i].x)
            ++cnt;

        int j = cnt;

        while(j <= n + 4) {
            ans = max(ans, (a[j].x - a[i].x) * (r - l));

            if(a[j].y <= a[i].y) 
                l = max(l, a[j].y);
            else if(a[j].y > a[i].y) 
                r = min(r, a[j].y);

            ++j;
        }

        j = cnt;
        l = 0, r = W;

        while(j <= n + 4) {
            ans = max(ans, (a[j].x - a[i].x) * (r - l));

            if(a[j].y < a[i].y) 
                l = max(l, a[j].y);
            else if(a[j].y >= a[i].y) 
                r = min(r, a[j].y);
        
            ++j;
        }
    }

    sort(a + 1, a + n + 4 + 1, cmp2);

    for(int i = 1; i <= n + 4; ++i) {
        int l = 0, r = L, cnt = i + 1;
        while(a[cnt].y == a[i].y) 
            ++cnt;
        int j = cnt;
        while(j <= n + 4) {
            ans = max(ans, (a[j].y - a[i].y) * (r - l));
            if(a[j].x <= a[i].x) 
                l = max(l, a[j].x);
            else if(a[j].x > a[i].x) 
                r = min(r, a[j].x);
            ++j;
        }
        j = cnt;
        l = 0, r = L;
        while(j <= n + 4) {
            ans = max(ans, (a[j].y - a[i].y) * (r - l));
            if(a[j].x < a[i].x) 
                l = max(l, a[j].x);
            else if(a[j].x >= a[i].x) 
                r = min(r, a[j].x);
            ++j;
        }
    }

	cout << ans << endl;
	return 0;
}
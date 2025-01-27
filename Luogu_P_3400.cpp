#include <bits/stdc++.h>

#define N 3010

using namespace std;

int n, m;
int s[N];
int f[N];
int sum[N];
int a[N][N];
int ans;

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

signed main() {

    n = read();
    m = read();

	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
		    a[i][j] = read();

	for(int i = 1; i <= n; i++) {

        int top = 0;

	    for(int j = 1; j <= m; j++) {
		    if(!a[i][j]) 
                f[j] = i;

		    while(top && f[s[top]]<f[j]) 
                top--; 

            s[++top] = j;

		    ans += (sum[top] = sum[top - 1] + (i - f[s[top]]) * (s[top] - s[top - 1]));
	    } 
    }
    
    cout << ans << endl;

    return 0;	
}
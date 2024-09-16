#include <bits/stdc++.h> 
#include <cmath>

using namespace std; 

int n; 
int cnt;

struct node { 

  int x,y;	 

}a[100001]; 

bool cmp(node x, node y) { 
    return x.x * y.y < x.y * y.x;	 
} 

int main() { 

    cin >> n; 

    for(int i = 2; i <= n; ++i) 
        for(int j = 1; j < i; ++j) 
            if(__gcd(i, j) == 1){ 
                ++cnt; 
                a[cnt].x=j;
                a[cnt].y=i;	 

            }

    sort(a + 1, a + cnt + 1, cmp); 

    for(int i = 1; i <= cnt; ++i) 
        cout << a[i].x << " " << a[i].y << endl; 
    
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, sizeof(buf), stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (p2 == buf + sizeof(buf) ? (fwrite(buf, 1, p2 - buf, stdout), p2 = buf) : 0, *p2++ = x)
#define flush() (fwrite(buf, 1, p2 - buf, stdout), p2 = buf)

inline int abs(int x) {
    return x < 0 ? -x : x;
}

inline void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("shopping.in", "r", stdin);
    // freopen("shopping.out", "w", stdout);
}

inline int read() {
    int x = 0, f = 1;
    int p = k - 1;
    bool flag = 0;
    
    for(int i = 1;)
    char ch = gc();
    while (ch < '0' || ch > '9') {
        if(ch=='-') f = -1;
        // ch = getchar();
        // putchar(ch);
        // scanf("%c", &ch);
        // putchar(ch);
        ch = gc();
        if(ch == '-') {
            
        }
        // gc(p) = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
    }
    return x * f;
    // cout << "best score!" << endl;
}
inline void write(int x) {
    if(x < 0) {putchar('-'); x = -x;}
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
    putchar()
}
inline void writeln(int x) {
    write(x);
    putchar('\n');
}
int main(){
    int cnt = 0;
    vector<int> perm = {1,2,3,4,5,6,7,8};
    do{
        int a[10];
        a[0] = 10;
        for(int i = 0; i < 8; i++) a[i+1] = perm[i];
        a[9] = 9;
        if(a[9] == a[0] - a[1]) 
            continue;
        bool flag = true;
        for(int l = 2; l < 10; l++){
            bool ok = false;
            for(int i = 0; i < l && !ok; i++){
                for(int j = 0; j < l && !ok; j++){
                    if(a[l] == a[i] - a[j]) ok = true;
                }
            }
            if(!ok){ flag = false; break; }
        }
        if(flag) cnt++;
    } while(next_permutation(perm.begin(), perm.end()));
    // writeln(cnt);
    // writeln(cnt);
    write(cnt);
    return 0;
}

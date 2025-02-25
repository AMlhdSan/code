#include <bits/stdc++.h>
using namespace std;

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
inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(long long x) {
    write(x); putchar('\n');
}

inline long long countRect(long long lx, long long rx, long long ly, long long ry) {
    if(lx>rx || ly>ry) return 0LL;
    return (rx-lx+1)*(ry-ly+1);
}

inline int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main() {
    // freopen("pancake.in", "r", stdin);
    // freopen("pancake.out", "w", stdout);
    long long n=read(), m=read(), k=read();
    if(k<=1){ // 题意 k>1
        puts("0");
        return 0;
    }

    // 答案可能很大，用 long long
    long long ans=0;

    // (dx_f, dy_f) 最大枚举范围
    // 因为要 (k-1)*dx_f <= n-1, (k-1)*dy_f <= m-1
    // => dx_f <= (n-1)/(k-1), dy_f <= (m-1)/(k-1)
    long long maxX = (n-1)/(k-1), maxY = (m-1)/(k-1);
    if(maxX<1 || maxY<1){
        // 说明任何方向都不可能再走 (k-1) 步，故无解
        puts("0");
        return 0;
    }

    for(int dx_f=1; dx_f<=maxX; dx_f++){
        for(int dy_f=1; dy_f<=maxY; dy_f++){
            if(gcd(dx_f, dy_f)!=1) continue; // 必须互质

            long long dx = (k-1)*(long long)dx_f;
            long long dy = (k-1)*(long long)dy_f;

            // 定义可选起点 (x0,y0) 的主范围 D
            long long Xmax = n - dx; // x0 <= Xmax
            long long Ymax = m - dy; // y0 <= Ymax
            if(Xmax<1 || Ymax<1) continue; // 没有可行点

            // D 的大小
            long long Dsize = Xmax * Ymax;

            // 集合 S3: x0 <= dx_f 或 y0 <= dy_f
            // 可以拆成 R1 ∪ R2:
            // R1 = [1..dx_f] × [1..Ymax]
            // R2 = [1..Xmax] × [1..dy_f]
            // 注意要和 Xmax, Ymax 比较防止越界
            long long R1 = countRect(1, min((long long)dx_f, Xmax), 1, Ymax);
            long long R2 = countRect(1, Xmax, 1, min((long long)dy_f, Ymax));
            // R1 ∩ R2 = [1..dx_f]×[1..dy_f] (在范围内)
            long long R1iR2 = countRect(1, min((long long)dx_f, Xmax),
                                        1, min((long long)dy_f, Ymax));
            long long S3 = R1 + R2 - R1iR2;

            // 集合 S4: x0 + k*dx_f > n 或 y0 + k*dy_f > m
            // 即 x0 > n - k*dx_f 或 y0 > m - k*dy_f
            // 令 A = [n - k*dx_f +1 .. Xmax] × [1..Ymax]
            // 令 B = [1..Xmax] × [m - k*dy_f +1 .. Ymax]
            long long Ax1 = max(1LL, n - k*dx_f +1), Ax2 = Xmax;
            long long Ay1 = 1,               Ay2 = Ymax;
            long long Acount = countRect(Ax1, Ax2, Ay1, Ay2);

            long long Bx1 = 1,               Bx2 = Xmax;
            long long By1 = max(1LL, m - k*dy_f +1), By2 = Ymax;
            long long Bcount = countRect(Bx1, Bx2, By1, By2);

            // A ∩ B = [max(Ax1,Bx1)..min(Ax2,Bx2)] × [max(Ay1,By1)..min(Ay2,By2)]
            long long Ix1 = max(Ax1,Bx1), Ix2 = min(Ax2,Bx2);
            long long Iy1 = max(Ay1,By1), Iy2 = min(Ay2,By2);
            long long AiB = countRect(Ix1, Ix2, Iy1, Iy2);

            long long S4 = Acount + Bcount - AiB;

            // S3 ∩ S4 = S3 + S4 - (S3 ∪ S4)
            // 而 S3 ∪ S4 = D \ (S3^c ∩ S4^c)
            // => |S3 ∩ S4| = S3 + S4 - |D| + |S3^c ∩ S4^c|
            // S3^c: x0>dx_f 且 y0>dy_f
            // S4^c: x0 <= n-k*dx_f 且 y0 <= m-k*dy_f
            // => S3^c ∩ S4^c: [dx_f+1..min(Xmax,n-k*dx_f)] × [dy_f+1..min(Ymax,m-k*dy_f)]
            long long Scx1 = dx_f+1, Scx2 = min((long long)Xmax, (long long)(n - k*dx_f));
            long long Scy1 = dy_f+1, Scy2 = min((long long)Ymax, (long long)(m - k*dy_f));
            long long S3cS4c = countRect(Scx1, Scx2, Scy1, Scy2);

            long long inter = S3 + S4 - Dsize + S3cS4c;
            if(inter<0) inter=0; // 理论上不会<0，但防御

            ans += inter;
        }
    }

    writeln(ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(int x) {
    write(x);
    putchar('\n');
}
const int NMAX = 200000 + 5;
int n,m;
int a[NMAX];
double sgt[4*NMAX], cgt[4*NMAX], lazyA[4*NMAX];
const double PI = acos(-1.0);
double norm(double x){ x = fmod(x, 2*PI); if(x<0) x+=2*PI; return x; }
void apply_rot(int p, double ang){
    double cv = cos(ang), sv = sin(ang);
    double ns = sgt[p]*cv + cgt[p]*sv;
    double nc = cgt[p]*cv - sgt[p]*sv;
    sgt[p]=ns; cgt[p]=nc;
    lazyA[p] = norm(lazyA[p] + ang);
}
void build(int p,int l,int r){
    lazyA[p]=0;
    if(l==r){ sgt[p]=sin(a[l]); cgt[p]=cos(a[l]); return; }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    sgt[p]=sgt[p<<1]+sgt[p<<1|1];
    cgt[p]=cgt[p<<1]+cgt[p<<1|1];
}
void push(int p){
    if(lazyA[p]!=0){
        apply_rot(p<<1, lazyA[p]);
        apply_rot(p<<1|1, lazyA[p]);
        lazyA[p]=0;
    }
}
void upd(int p,int l,int r,int ql,int qr,double ang){
    if(ql<=l && r<=qr){ apply_rot(p, ang); return; }
    push(p);
    int mid=(l+r)>>1;
    if(ql<=mid) upd(p<<1,l,mid,ql,qr,ang);
    if(qr>mid) upd(p<<1|1,mid+1,r,ql,qr,ang);
    sgt[p]=sgt[p<<1]+sgt[p<<1|1];
    cgt[p]=cgt[p<<1]+cgt[p<<1|1];
}
double qry(int p,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr) return sgt[p];
    push(p);
    int mid=(l+r)>>1;
    double res=0;
    if(ql<=mid) res+=qry(p<<1,l,mid,ql,qr);
    if(qr>mid) res+=qry(p<<1|1,mid+1,r,ql,qr);
    return res;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    m=read();
    for(int i=0;i<m;i++){
        int t=read();
        if(t==1){
            int l=read(), r=read(), v=read();
            double ang = (double)v;
            ang = norm(ang);
            upd(1,1,n,l,r,ang);
        }else{
            int l=read(), r=read();
            double ans = qry(1,1,n,l,r);
            if(fabs(ans) < 0.0000005) ans = 0; 
            printf("%.1f\n", ans);
        }
    }
    return 0;
}

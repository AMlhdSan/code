#include <cstdio>
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){putchar('-'); x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){
    write(x);
    putchar('\n');
}
int main(){
    int n=read(), m=read(), k=read();
    int top1 = (m < k ? m : k);
    int top2 = (n <= k ? m : 1);
    int left1 = (m <= k ? (n-1) : 1);
    int left2 = (n <= k ? (n-1) : k);
    int ans = top1 + top2 + left1 + left2;
    writeln(ans);
    return 0;
}

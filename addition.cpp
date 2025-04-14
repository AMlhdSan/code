#include <bits/stdc++.h>
using namespace std;
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
    return x * f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){
    write(x);
    putchar('\n');
}

int main(){
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    int n = read(), q = read();
    vector<int> arr(n), A(n);
    for (int i = 0; i < n; i++){
        arr[i] = read();
    }
    int B = sqrt(n);
    int nb = (n + B - 1) / B;
    vector<int> blk_lazy(nb, 0), blk_sum(nb, 0);
    auto recalc = [&](int bid){
        int L = bid * B, R = min(n, (bid+1)*B);
        int sum = 0;
        for (int i = L; i < R; i++){
            sum += (A[i] + blk_lazy[bid]) / arr[i];
        }
        blk_sum[bid] = sum;
    };
    for (int bid = 0; bid < nb; bid++){
        recalc(bid);
    }
    auto update = [&](int l, int r){
        int lb = l / B, rb = r / B;
        if(lb == rb){
            int L = lb * B, R = min(n, (lb+1)*B);
            for (int i = L; i < R; i++){
                if(i>=l && i<=r){
                    int old = A[i] + blk_lazy[lb];
                    int ne = old + 1;
                    blk_sum[lb] -= old / arr[i];
                    blk_sum[lb] += ne / arr[i];
                    A[i]++;
                }
            }
        } else {
            int L = lb * B, R = min(n, (lb+1)*B);
            for (int i = L; i < R; i++){
                if(i>=l){
                    int old = A[i] + blk_lazy[lb];
                    int ne = old + 1;
                    blk_sum[lb] -= old / arr[i];
                    blk_sum[lb] += ne / arr[i];
                    A[i]++;
                }
            }
            for (int bid = lb+1; bid < rb; bid++){
                int L = bid * B, R = min(n, (bid+1)*B);
                int cnt = 0;
                for (int i = L; i < R; i++){
                    int old = A[i] + blk_lazy[bid];
                    int ne = old + 1;
                    if(ne / arr[i] != old / arr[i]) cnt++;
                }
                blk_lazy[bid]++;
                blk_sum[bid] += cnt;
            }
            L = rb * B; R = min(n, (rb+1)*B);
            for (int i = L; i < R; i++){
                if(i<=r){
                    int old = A[i] + blk_lazy[rb];
                    int ne = old + 1;
                    blk_sum[rb] -= old / arr[i];
                    blk_sum[rb] += ne / arr[i];
                    A[i]++;
                }
            }
        }
    };
    auto query = [&](int l, int r)->int{
        int lb = l / B, rb = r / B;
        int res = 0;
        if(lb == rb){
            int L = lb * B, R = min(n, (lb+1)*B);
            for (int i = L; i < R; i++){
                if(i>=l && i<=r){
                    res += (A[i] + blk_lazy[lb]) / arr[i];
                }
            }
        } else {
            int L = lb * B, R = min(n, (lb+1)*B);
            for (int i = L; i < R; i++){
                if(i>=l){
                    res += (A[i] + blk_lazy[lb]) / arr[i];
                }
            }
            for (int bid = lb+1; bid < rb; bid++){
                res += blk_sum[bid];
            }
            L = rb * B; R = min(n, (rb+1)*B);
            for (int i = L; i < R; i++){
                if(i<=r){
                    res += (A[i] + blk_lazy[rb]) / arr[i];
                }
            }
        }
        return res;
    };
    for (int i = 0; i < q; i++){
        int op = read(), l = read()-1, r = read()-1;
        if(op == 1){
            update(l, r);
        } else {
            int ans = query(l, r);
            writeln(ans);
        }
    }
    return 0;
}

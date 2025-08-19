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

int main(){
    int T=read();
    while(T--){
        int n=read();
        static char a[100005],b[100005],c[100005];
        scanf("%s",a+1);
        scanf("%s",b+1);
        scanf("%s",c+1);
        int na=n, nb=n, nc=n;
        int N = na + 1 + nb + 1 + nc;
        vector<int> s;
        s.reserve(N);
        for(int i=1;i<=na;i++) s.push_back((int)(a[i]-'a')+3);
        s.push_back(2);
        for(int i=1;i<=nb;i++) s.push_back((int)(b[i]-'a')+3);
        s.push_back(1);
        for(int i=1;i<=nc;i++) s.push_back((int)(c[i]-'a')+3);
        int M = s.size();
        vector<int> sa(M), r(M), tmp(M);
        for(int i=0;i<M;i++){ sa[i]=i; r[i]=s[i]; }
        for(int k=1;;k<<=1){
            auto cmp = [&](int i,int j)->bool{
                if(r[i]!=r[j]) return r[i]<r[j];
                int ri = i+k<M ? r[i+k] : -1;
                int rj = j+k<M ? r[j+k] : -1;
                return ri<rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for(int i=1;i<M;i++) tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i])?1:0);
            for(int i=0;i<M;i++) r[i]=tmp[i];
            if(r[sa[M-1]]==M-1) break;
        }
        vector<int> rankv(M);
        for(int i=0;i<M;i++) rankv[sa[i]]=i;
        vector<int> h(M);
        int k0=0;
        for(int i=0;i<M;i++){
            if(rankv[i]==0){ k0=0; continue;}
            int j=sa[rankv[i]-1];
            while(i+k0<M && j+k0<M && s[i+k0]==s[j+k0]) k0++;
            h[rankv[i]] = k0;
            if(k0) k0--;
        }
        int LOG = 1;
        while((1<<LOG) <= M) LOG++;
        vector<vector<int>> st(LOG, vector<int>(M));
        for(int i=0;i<M;i++) st[0][i]=h[i];
        for(int z=1;z<LOG;z++){
            for(int i=0;i+(1<<z)<=M;i++){
                st[z][i] = min(st[z-1][i], st[z-1][i+(1<<(z-1))]);
            }
        }
        vector<int> lg2(M+1);
        for(int i=2;i<=M;i++) lg2[i]=lg2[i>>1]+1;
        auto getlcp = [&](int x,int y)->int{
            if(x==y) return M-x;
            int rx = rankv[x], ry = rankv[y];
            if(rx>ry) swap(rx,ry);
            int l = rx+1, r = ry;
            int k = lg2[r-l+1];
            return min(st[k][l], st[k][r-(1<<k)+1]);
        };
        int pa = 0;
        int pb = na+1;
        int pc = na+1+nb+1;
        int INF = 1e9;
        int ans = INF;
        int B = max(300, (int)sqrt(n)+1);
        if(B>n) B=n;
        for(int d=1;d<=B;d++){
            for(int p=2;p<=n-d;p++){
                int i = p-1;
                int j = i + d;
                int posA = pa;
                int posB = pb + (p-1);
                int posC = pc + (p+d-1);
                int n_j = n - j;
                int l1 = getlcp(posA, posB);
                if(l1>i) l1=i;
                if(l1> d) l1=d;
                int l2 = getlcp(posB, posC);
                if(l2> d) l2=d;
                if(l2> n_j) l2=n_j;
                int l3 = getlcp(posA, posC);
                if(l3> i) l3=i;
                if(l3> n_j) l3=n_j;
                int cur = l1 + l2 + l3;
                if(cur < ans) ans = cur;
            }
        }
        for(int t=1;t<=B;t++){
            int j = n - t;
            if(j<=1) continue;
            int up = j - B;
            if(up < 2) continue;
            for(int p=2;p<=up;p++){
                int i = p-1;
                int d = j - i;
                if(d<=B) continue;
                int posA = pa;
                int posB = pb + (p-1);
                int posC = pc + (p+d-1);
                int n_j = n - j;
                int l1 = getlcp(posA, posB);
                if(l1>i) l1=i;
                if(l1> d) l1=d;
                int l2 = getlcp(posB, posC);
                if(l2> d) l2=d;
                if(l2> n_j) l2=n_j;
                int l3 = getlcp(posA, posC);
                if(l3> i) l3=i;
                if(l3> n_j) l3=n_j;
                int cur = l1 + l2 + l3;
                if(cur < ans) ans = cur;
            }
        }
        if(ans==INF) ans=0;
        writeln(ans);
    }
    return 0;
}

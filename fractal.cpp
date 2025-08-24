// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using uint=unsigned int;
using ull=unsigned long long;
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define ne nth_element
#define mie min_element
#define mae max_element
#define eb emplace_back
#define ump unordered_map
#define pq priority_queue
#define clz __builtin_clz
#define ctz __builtin_ctz
#define sz(x) (int)x.size()
#define np next_permutation
#define clzl __builtin_clzll
#define ctzl __builtin_ctzll
#define ppc __builtin_popcount
#define all(x) x.begin(),x.end()
#define ppcl __builtin_popcountll
#define fpi(x) freopen(x,"r",stdin)
#define fpo(x) freopen(x,"w",stdout)
#define Time cerr<<"\nTime: "<<clock()
#define uid uniform_int_distribution
#define me(x,y) memset(x,y,sizeof(x))
#define seed chrono::system_clock::now().time_since_epoch().count()
#ifdef Nuj
template<class T> void _dbg(T h){
    string s=typeid(T).name();
    cerr<<" = ";
    bool f=s=="PKc"||s=="Pc"||s=="Ss";
    if(f) cerr<<'"';if(s=="c") cerr<<(char)39;
    cerr<<h;
    if(f) cerr<<'"';if(s=="c") cerr<<(char)39;
}
template<class T> void _dbg(int l,const char *c,T h){
    if(l) cerr<<fixed<<setprecision(10)<<"In Line "<<l<<' ';
    cerr<<c,_dbg(h),cerr<<endl;
}
template<class T,class...H> void _dbg(int l,const char *c,T h,H... a){
    if(l) cerr<<fixed<<setprecision(10)<<"In Line "<<l<<' ';
    int t=0;bool f=0,g=0;
    while(*c^44||f|g|t){
        if(*c==39) f=!f;if(*c==34) g=!g;
        if(!f&!g) t+=(*c==40)-(*c==41)+(*c==91)-(*c==93)+(*c=='{')-(*c=='}');
        cerr<<*c++;
    }
    _dbg(h),cerr<<", ",_dbg(0,++c,a...);
}
#define dbg(...) _dbg(__LINE__,#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...) 0
#define assert(...) 0
#endif
#define mod 998244353
#define inf 0x3f3f3f3f
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)

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

// inline void 

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

// ========== 高精度模板 ========== //
const int base = 1000000000;
const int base_digits = 9;
struct Bint {
    vector<int> a;
    int sign;
    Bint() : sign(1) {}
    Bint(long long v) { *this = v; }
    Bint(const string &s) { read(s); }
    void operator=(long long v) {
        sign = 1; a.clear();
        if (v < 0) sign = -1, v = -v;
        for (; v > 0; v /= base) a.push_back(v % base);
    }
    Bint operator+(const Bint &v) const {
        if (sign == v.sign) {
            Bint res = v; int carry = 0;
            for (size_t i = 0; i < max(a.size(), v.a.size()) || carry; i++) {
                if (i == res.a.size()) res.a.push_back(0);
                res.a[i] += carry + (i < a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry) res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
    Bint operator-(const Bint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                Bint res = *this; int carry = 0;
                for (size_t i = 0; i < v.a.size() || carry; i++) {
                    res.a[i] -= carry + (i < v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    Bint operator*(const Bint &v) const {
        vector<ll> num(a.size() + v.a.size());
        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < v.a.size(); j++) {
                num[i+j] += 1ll * a[i] * v.a[j];
                if (num[i+j] >= base) {
                    num[i+j+1] += num[i+j] / base;
                    num[i+j] %= base;
                }
            }
        Bint res; res.sign = sign * v.sign;
        for (ll x : num) res.a.push_back(x);
        res.trim();
        return res;
    }
    Bint operator/(int v) const {
        Bint res; res.sign = sign; res.a.resize(a.size());
        ll rem = 0;
        for (int i = (int)a.size()-1; i >= 0; i--) {
            ll cur = a[i] + rem * base;
            res.a[i] = cur / v;
            rem = cur % v;
        }
        res.trim();
        return res;
    }
    int operator%(int v) const {
        ll m = 0;
        for (int i = (int)a.size()-1; i >= 0; i--)
            m = (a[i] + m * base) % v;
        return m * sign;
    }
    Bint operator-() const { Bint res = *this; if (!res.isZero()) res.sign = -sign; return res; }
    bool operator<(const Bint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size()) return a.size()*sign < v.a.size()*sign;
        for (int i = (int)a.size()-1; i >= 0; i--)
            if (a[i] != v.a[i]) return a[i]*sign < v.a[i]*sign;
        return 0;
    }
    bool operator==(const Bint &v) const { return sign==v.sign && a==v.a; }
    bool operator!=(const Bint &v) const { return !(*this==v); }
    bool operator>(const Bint &v) const { return v<*this; }
    bool operator<=(const Bint &v) const { return !(v<*this); }
    bool operator>=(const Bint &v) const { return !(*this<v); }
    string toString() const {
        if (a.empty()) return "0";
        string s = sign==-1 ? "-" : "";
        s += to_string(a.back());
        for (int i = (int)a.size()-2; i >= 0; i--) {
            string t = to_string(a[i]);
            s += string(base_digits - t.size(), '0') + t;
        }
        return s;
    }
    void read(const string &s) {
        sign = 1; a.clear(); int pos = 0;
        while (pos < (int)s.size() && (s[pos]=='-' || s[pos]=='+')) {
            if (s[pos]=='-') sign=-sign; pos++;
        }
        for (int i=(int)s.size()-1; i>=pos; i-=base_digits) {
            int x=0;
            for (int j=max(pos,i-base_digits+1); j<=i; j++) x=x*10+s[j]-'0';
            a.push_back(x);
        }
        trim();
    }
    void trim() {
        while (!a.empty() && a.back()==0) a.pop_back();
        if (a.empty()) sign=1;
    }
    bool isZero() const { return a.empty(); }
    Bint abs() const { Bint res=*this; res.sign=1; return res; }
};

// ========== 主函数部分 ========== //
int main(){
    #ifndef Nuj
    cin.tie(0)->sync_with_stdio(0);
    #endif
    
    // ===== 这里写题目代码 ===== //
    Bint a("123456789123456789"), b("987654321");
    Bint c = a * b;
    cout << c.toString() << endl;
    
    return 0;
}

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

const int base = 1000000000;
const int base_digits = 9;
struct Bint {
    vector<int> a;
    int sign;
    Bint() :
        sign(1) {
    }
    Bint(long long v) {
        *this = v;
    }
    Bint(const string &s) {
        read(s);
    }
    void operator=(const Bint &v) {
        sign = v.sign;
        a = v.a;
    }
    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }
    Bint operator+(const Bint &v) const
    {
        if (sign == v.sign)
        {
            Bint res = v;
            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i)
            {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
    Bint operator-(const Bint &v) const
    {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                Bint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i)
                {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    void operator*=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i)
        {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        trim();
    }
    Bint operator*(int v) const
    {
        Bint res = *this;
        res *= v;
        return res;
    }
    friend pair<Bint, Bint> divmod(const Bint &a1, const Bint &b1)
    {
        int norm = base / (b1.a.back() + 1);
        Bint a = a1.abs() * norm;
        Bint b = b1.abs() * norm;
        Bint q, r;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--)
        {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    Bint operator/(const Bint &v) const
    {
        return divmod(*this, v).first;
    }
    Bint operator%(const Bint &v) const
    {
        return divmod(*this, v).second;
    }
    void operator/=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i)
        {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
    Bint operator/(int v) const
    {
        Bint res = *this;
        res /= v;
        return res;
    }
    int operator%(int v) const
    {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }
    void operator+=(const Bint &v)
    {
        *this = *this + v;
    }
    void operator-=(const Bint &v)
    {
        *this = *this - v;
    }
    void operator*=(const Bint &v)
    {
        *this = *this * v;
    }
    void operator/=(const Bint &v)
    {
        *this = *this / v;
    }
    bool operator<(const Bint &v) const
    {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const Bint &v) const
    {
        return v < *this;
    }
    bool operator<=(const Bint &v) const
    {
        return !(v < *this);
    }
    bool operator>=(const Bint &v) const
    {
        return !(*this < v);
    }
    bool operator==(const Bint &v) const
    {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const Bint &v) const
    {
        return *this < v || v < *this;
    }
    void trim()
    {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
    bool isZero() const
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    Bint operator-() const
    {
        Bint res = *this;
        res.sign = -sign;
        return res;
    }
    Bint abs() const
    {
        Bint res = *this;
        res.sign *= res.sign;
        return res;
    }
    long long longValue() const
    {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
    friend Bint gcd(const Bint &a, const Bint &b)
    {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend Bint lcm(const Bint &a, const Bint &b)
    {
        return a / gcd(a, b) * b;
    }
    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits)
        {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream& operator>>(istream &stream, Bint &v)
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend ostream& operator<<(ostream &stream, const Bint &v)
    {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits)
    {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++)
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits)
            {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
    typedef vector<long long> vll;
    static vll karatsubaMultiply(const vll &a, const vll &b)
    {
        int n = a.size();
        vll res(n + n);
        if (n <= 32)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];
        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
    Bint operator*(const Bint &v) const
    {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        Bint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++)
        {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
}dp[5005][2][2],x,y;
bool X[5005],Y[5005];
int main(){
	#ifndef Nuj
	cin.tie(0)->sync_with_stdio(0);
	#endif
	int K;cin>>K>>x>>y;
	for(int i=0;i<K;i++) X[i]=x%2,Y[i]=y%2,x/=2,y/=2;
	if(x!=0||y!=0) return cout<<0,0;
	***dp=1;
	for(int i=0;i<K;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) for(int l=0;l<2;l++) for(int p=0;p<2;p++) if((l||!p)&&(j^l^X[i]||!(k^p^Y[i]))){
		dp[i+1][(j+l+X[i])>>1][(k+p+Y[i])>>1]+=dp[i][j][k];
	}
	cout<<**dp[K];
	return 0;
}

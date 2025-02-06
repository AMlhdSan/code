#include <bits/stdc++.h>
using namespace std;

string f5(const string &s) {
    int i = 0;
    while(i < s.size() && s[i]=='0') i++;
    return (i==s.size() ? "0" : s.substr(i));
}

int f4(const string &a, const string &b) {
    string aa = f5(a);
    string bb = f5(b);
    if(aa.size() < bb.size()) return -1;
    if(aa.size() > bb.size()) return 1;
    if(aa == bb) return 0;
    return (aa < bb) ? -1 : 1;
}

string addBig(const string &a, const string &b) {
    int i = a.size()-1, j = b.size()-1, carry = 0;
    string res;
    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0) { sum += a[i]-'0'; i--; }
        if(j >= 0) { sum += b[j]-'0'; j--; }
        carry = sum / 10;
        res.push_back(char('0' + sum % 10));
    }
    reverse(res.begin(), res.end());
    return res;
}

string f3(const string &a, const string &b) {
    int i = a.size()-1, j = b.size()-1, carry = 0;
    string res;
    while(i >= 0) {
        int diff = (a[i]-'0') - carry;
        if(j >= 0) {
            diff -= (b[j]-'0');
            j--;
        }
        if(diff < 0) { diff += 10; carry = 1; }
        else carry = 0;
        res.push_back(char('0' + diff));
        i--;
    }
    reverse(res.begin(), res.end());
    return f5(res);
}

string absDiffBig(const string &a, const string &b) {
    return (f4(a,b) >= 0 ? f3(a,b) : f3(b,a));
}

string f1(const string &A, const string &S) {
    int n = A.size();
    string X = A;
    bool fixed = false;
    for (int i = 0; i < n; i++) {
        int a_digit = A[i]-'0', s_digit = S[i]-'0';
        if(!fixed) {
            if(a_digit > s_digit) {
                X[i] = char('0' + s_digit);
                fixed = true;
                for (int j = i+1; j < n; j++){
                    X[j] = S[j];
                }
                break;
            } 
        } else {
            X[i] = S[i];
        }
    }
    return X;
}
 
string f2(string A, const string &S) {
    int n = A.size();
    bool valid = true;
    for (int i = 0; i < n; i++) {
        if(A[i]-'0' > S[i]-'0') { valid = false; break; }
    }
    if(valid) return A;
    int idx = 0;
    while(idx < n && (A[idx]-'0' <= S[idx]-'0'))
        idx++;
    int j = idx - 1;
    while(j >= 0 && (A[j]-'0' == S[j]-'0'))
        j--;
    if(j < 0) {
        return S;
    }
    int d = A[j]-'0';
    d++;
    A[j] = char('0' + d);
    for (int k = j+1; k < n; k++){
        A[k] = '0';
    }
    return A;
}

int main(){

    freopen("Add.in", "r", stdin);
    freopen("Add.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string A, B;
    cin >> A >> B;
    string S = addBig(A, B);
 
    int L = S.size();
    if(A.size() < L)
        A = string(L - A.size(), '0') + A;
 
    string candLow = f1(A, S);
    string candHigh = f2(A, S);
 
    string diffLow = f3(A, candLow);
    string diffHigh = f3(candHigh, A);
 
    int cmp = f4(diffLow, diffHigh);
    string ans = (cmp <= 0 ? diffLow : diffHigh);
    ans = f5(ans);
    cout << ans << "\n";
    return 0;
}

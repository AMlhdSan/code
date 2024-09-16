#include <bits/stdc++.h> 
#define MAXN 1000001

using namespace std; 

int a, b, n;
int mod;
int l[MAXN], modd[MAXN]; 

int main(){ 

    cin >> a >> b >> n; 
    a = a % b; 
    l[0] = a;

    for(int i = 1; i <= n; i++){ 
        mod = a * 10 / b;
        a *= 10;
        a %= b;

        l[i] = a;
        modd[i] = mod;

        for(int j = 0; j < i; j++) { 
            if(a == l[j]) {
                for(int k = j + 1; k <= i; k++)
                    cout << modd[k]; 
                cout << endl; 
                return 0; 
            } 
        } 
        if(a == 0){
            cout << -1 << endl; 
            return 0; 
        } 
    } 
    cout << 0 << endl; 
    return 0; 
} 
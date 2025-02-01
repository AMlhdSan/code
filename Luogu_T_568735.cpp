#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ans ^= (a[i] + a[j]);
        }
    }
    
    cout << ans << "\n";
    return 0;
}

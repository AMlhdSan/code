#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, R;
    cin >> n >> L >> R;
    
    vector<int> T(n), M(n);
    for (int i = 0; i < n; i++){
        cin >> T[i] >> M[i];
    }
    
    vector<int> t(n), m(n);
    for (int i = 0; i < n; i++){
        cin >> t[i] >> m[i];
    }
    
    for (int i = 0; i < n; i++) {
        if(i + 1 >= L && i + 1 <= R){
            cout << "System Error" << "\n";
        }
        else if(M[i] > m[i]){
            cout << "Memory Limit Exceeded" << "\n";
        }
        else if((T[i] / 2) > t[i]){
            cout << "Time Limit Exceeded" << "\n";
        }
        else{
            cout << "Accepted" << "\n";
        }
    }
    
    return 0;
}

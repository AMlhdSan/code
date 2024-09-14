// STL 栈
#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[100001];
int b[100001];
stack<int> st;
int cnt;

int main() {

    cin >> T;

    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        cnt = 1;
        for(int i = 1; i <= n; ++i) {
            st.push(a[i]);
            while(!st.empty()) {
                if(st.top() == b[cnt]) {
                    st.pop();
                    ++cnt;
                }
                else {
                    break;
                }
            }
        }
        if(st.empty()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
            while(!st.empty()) {
                st.pop();
            }
        }
    }
    return 0;
}
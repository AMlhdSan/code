#include <bits/stdc++.h>

using namespace std;

priority_queue<int> q;
int n, x;
long long ans;

int main() {
	cin >> n;
	while(n--) {
		cin >> x;
        q.push(x);
		if(x < q.top()) {
			ans += q.top() - x;
			q.pop();
            q.push(x);
		}
	}
	cout << ans << endl;
	return 0;
}
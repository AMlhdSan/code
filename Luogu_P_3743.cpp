#include <bits/stdc++.h>

#define E 0.00001

using namespace std;

int n;
double p;
double a[200010], b[200010];

double sum = 0;

inline bool check(double ans) {
	double q = p * ans;
	sum = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] * ans <= b[i]){
			continue;
		}
		sum += (a[i] * ans - b[i]);
	}
	return sum <= q;
}

int main() {

	cin >> n >> p;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	if(sum <= p) {
		cout << -1.00001 << endl;
		return 0;
	}
	double l = 0, r = 1e10;
	double mid;
	while(r - l > E) {
		mid = (l + r) / 2.0;
		if(check(mid)) {
			l = mid;
		}
        else {
			r = mid;
		}
	}

	printf("%.10f\n", (l + r) / 2.0);

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,a[500001];
int t[500001];
long long ans=0; 

void merge(int a[],int l,int r) {
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l, j = mid + 1, cnt = l;
	while(i <= mid && j <= r)
		if(a[i] > a[j])
		{
			t[cnt++] = a[j++];
			ans += mid - i + 1;
		}
		else
			t[cnt++] = a[i++];
	while(i <= mid)
		t[cnt++] = a[i++];
	while(j <= r)
		t[cnt++] = a[j++];
	for(i = l; i <= r; i++)
		a[i] = t[i];
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	merge(a, 1, n);
	cout << ans << endl;
	return 0;
}
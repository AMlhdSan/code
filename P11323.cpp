#include <bits/stdc++.h>

#define ll long long

#define N 300010

using namespace std;

int T;
int n;
ll a[N];
ll t[N] = {2};
ll cnt1, cnt2, cnt3;
ll sum = 0;

signed main(){

	cin >> T;
    
	t[0] = 0;
    t[1] = 2;

	for(int i = 2; i <= 20; ++i) {
		t[i] = t[i - 1];
		if((i - 1) % 4 == 0) 
            t[i] += 2;
		else if((i - 1) % 2 == 0) 
            t[i] += 1;
	} 

	while(T--) {
		cin >> n;
		cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i <= n;i++) 
            cin >> a[i];
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) continue;
			cnt3 += (a[i] / 3);
			if(a[i] % 3 == 1) cnt1++;
			else if(a[i] % 3 == 2) cnt2++;	
		}
		if(cnt1 >= cnt3){
			cout << cnt1 + cnt2 << '\n';
		}else{
			cnt3 -= cnt1;
			sum += cnt1;
			if(cnt3 % 2 == 0){
				if(cnt2 * 2 >= cnt3){
					sum += cnt3;
					sum += cnt2 - (cnt3 / 2);
				}else{
					cnt3 -= cnt2 * 2;
					sum += cnt2 * 2 + t[cnt3 % 4]  + t[4] * (cnt3 / 4);
				}
			}else{
				if(cnt2 * 2 >= cnt3){
					sum += cnt3 - 1;
					sum += 2;
					sum += (cnt2 - 1 - cnt3 / 2); 
				}else{
					sum += (cnt2 * 2);
					cnt3 -= cnt2 * 2;
					sum += t[cnt3 % 4] + t[4]  * (cnt3 / 4);
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
} 
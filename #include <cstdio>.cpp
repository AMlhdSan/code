#include <bits/stdc++.h>

using namespace std;
bool t[1000005];

int main(){

	memset(t, false, sizeof(t));

	int n, tmpx, tmpy, maxz = -1, maxa = -1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d%d", &tmpx, &tmpy);
		for(int i = tmpx; i < tmpy; i ++){
			t[i] = true;
		}
		maxz = max(maxz, tmpy);
		maxa = min(maxa, tmpx);
	}
	int maxx = -1, maxy = -1;
	int tmpa = 0, tmpb = 0;
	for(int i = maxa; i <= maxz; i ++){
		if(t[i]){
			++tmpa;
			tmpb = 0;
		} else{
			tmpa = 0;
			if(i < maxz){
				tmpb ++;
			}
		}
		maxx = max(maxx, tmpa);
		maxy = max(maxy, tmpb);
	}
	printf("%d %d", maxx, maxy);
	return 0;
}
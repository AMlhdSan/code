#include <bits/stdc++.h>

#define N 1000010

using namespace std;

char s[N];
int len;
int f[N];
int sum, id;

inline void 

int main() {

	cin >> s + 1;

	len = strlen(s + 1);

	for(int i = 2; i <= len; ++i)
		if(s[i] == '(' || s[i] == '[') 
            continue;
		else
			if((s[i] == ')' && s[i - f[i - 1] - 1] == '(') || (s[i] == ']' && s[i - f[i - 1] - 1] == '[')) {
				f[i] = f[i - 1] + 2 + f[i - f[i - 1] - 2];
				if(f[i] > sum) {
                    sum = f[i];
                    id = i;
                }
			}
	for(int i = id - sum + 1; i <= id; ++i) 
        cout << s[i];
	puts("");
	return 0;
}
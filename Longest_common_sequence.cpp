// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

string a, b, ans;
int dp[505][505];

int main() {
	cin >> b >> a;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int x = a.size(), y = b.size();
	while (x*y) {
		if (a[x - 1] == b[y - 1]) ans = a[x - 1]+ans, x--, y--;
		else {
			if (dp[x - 1][y] >= dp[x][y - 1]) x--;
			else y--;
		}
	}

	cout << ans;

	return 0;
}
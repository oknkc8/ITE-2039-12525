// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int n, e1, e2, x1, x2;
int a1[101], a2[101], t1[101], t2[101];
int dp[101][2], ans[101], path[101][2];

int main() {
	scanf("%d%d%d%d%d", &n, &e1, &e2, &x1, &x2);
	for (int i = 0; i < n; i++) scanf("%d", &a1[i]);
	for (int i = 0; i < n; i++) scanf("%d", &a2[i]);
	for (int i = 0; i < n - 1; i++) scanf("%d", &t1[i]);
	for (int i = 0; i < n - 1; i++) scanf("%d", &t2[i]);

	dp[0][0] = e1 + a1[0], dp[0][1] = e2 + a2[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = a1[i];
		if (dp[i - 1][0] <= dp[i - 1][1] + t2[i - 1]) {
			dp[i][0] += dp[i - 1][0];
			path[i][0] = 0;
		}
		else {
			dp[i][0] += dp[i - 1][1] + t2[i - 1];
			path[i][0] = 1;
		}

		dp[i][1] = a2[i];
		if (dp[i - 1][1] <= dp[i - 1][0] + t1[i - 1]) {
			dp[i][1] += dp[i - 1][1];
			path[i][1] = 1;
		}
		else {
			dp[i][1] += dp[i - 1][0] + t1[i - 1];
			path[i][1] = 0;
		}
	}

	if (dp[n - 1][0] + x1 < dp[n - 1][1] + x2) dp[n][0] = dp[n - 1][0] + x1, path[n][0] = 0;
	else dp[n][0] = dp[n - 1][1] + x2, path[n][0] = 1;

	printf("%d\n", dp[n][0]);
	int x = 0, t = n;
	while (n) {
		ans[n - 1] = path[n][x] + 1;
		x = path[n][x];
		n--;
	}
	for (int i = 0; i < t; i++) printf("%d %d\n", ans[i], i + 1);

	return 0;
}
// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

#define INF 1e15

typedef long long ll;

int n, v[101];
ll dp[101][101], t[101][101];

ll f(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	if (x == y) return dp[x][y] = 0;

	ll &ret = dp[x][y];
	int idx;
	ret = INF;
	for (int k = x; k < y; k++) {
		ll e = f(x, k) + f(k + 1, y) + v[x - 1] * v[k] * v[y];
		if (ret > e) {
			ret = e;
			idx = k;
		}
	}
	t[x][y] = idx;
	return ret;
}

void print_tracking(int x, int y) {
	if (x == y) {
		printf("%d ", x);
		return;
	}
	printf("( ");
	print_tracking(x, t[x][y]);
	print_tracking(t[x][y] + 1, y);
	printf(") ");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) scanf("%d", &v[i]);

	printf("%lld\n", f(1, n));
	print_tracking(1, n);

	return 0;
}
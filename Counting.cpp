// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int  q[100005][2], c[100005];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) scanf("%d%d", &q[i][0], &q[i][1]);
	for (int i = 0; i < n; i++) {
		int a;	scanf("%d", &a);
		c[a]++;
	}

	for (int i = 1; i <= m; i++) c[i] += c[i - 1];

	for (int i = 0; i < k; i++) {
		int x = q[i][0], y = q[i][1];
		printf("%d\n", c[y] - c[x - 1]);
	}


	return 0;
}
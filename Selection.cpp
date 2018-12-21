// 2017029807_¼ºÃ¢È£_12525

#include<stdio.h>

int v[30005];

int main() {
	int n, m;	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	for (int i = 0; i < m; i++) {
		int s = v[i], idx=i;
		for (int j = i + 1; j < n; j++) {
			if (s > v[j]) s = v[j], idx = j;
		}
		int t = v[i];
		v[i] = v[idx], v[idx] = t;
	}

	for (int i = 0; i < n; i++) printf("%d\n", v[i]);

	return 0;
}
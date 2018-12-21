// 2017029807_¼ºÃ¢È£_12525

#include<stdio.h>

bool um[20000000];

int main() {
	int a, n, m, ans = 0;	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%d", &a);
		um[a] = 1;
	}
	while (m--) {
		scanf("%d", &a);
		ans+=um[a];
	}

	printf("%d", ans);

	return 0;
}
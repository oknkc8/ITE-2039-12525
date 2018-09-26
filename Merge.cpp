// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int v[100005], t[100005];

void msort(int a, int b) {
	if (a == b) return;
	if (b - a == 1) {
		if (v[a] < v[b]) swap(v[a], v[b]);
		return;
	}

	msort(a, (a + b) / 2);
	msort((a + b) / 2 + 1, b);
	int x = a, y = (a + b) / 2 + 1, c = a;
	while (x <= (a + b) / 2 || y <= b) {
		if (y==b+1 ||(v[x] >= v[y] && x<=(a+b)/2)) t[c++] = v[x++];
		else t[c++] = v[y++];
	}
	for (int i = a; i <= b; i++) v[i] = t[i];
}

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	msort(0, n - 1);

	for (int i = 0; i < n; i++) printf("%d\n", v[i]);

	return 0;
}
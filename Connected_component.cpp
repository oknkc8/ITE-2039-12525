// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int n, cnt, c[1005], visit[1005];
vector<vector<int> > adj;

void dfs(int x) {
	visit[x] = 1;
	c[x] = cnt;

	for (int i = 0; i < adj[x].size(); i++) {
		if (!visit[adj[x][i]]) dfs(adj[x][i]);
	}
}

int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) printf("%d\n", c[i]);

	return 0;
}
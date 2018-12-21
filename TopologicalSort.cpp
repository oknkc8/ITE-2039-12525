// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int visit[1005], cycle[1005], flag;
vector<int> ans;
vector<vector<int> > adj;

void dfs(int x) {
	visit[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!visit[adj[x][i]]) dfs(adj[x][i]);
		else if (!cycle[adj[x][i]]) flag = 1;
	}
	cycle[x] = 1;
	ans.push_back(x);
}

int main() {
	int n, a, b;	scanf("%d", &n);
	adj.resize(n + 1);
	
	while (scanf("%d%d", &a, &b) != EOF) {
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	for (int i = 1; i <= n; i++) {
		if(!visit[i]) dfs(i);
	}

	if (flag) printf("0");
	else {
		printf("1\n");
		for (int i = ans.size() - 1;i>=0; i--) printf("%d ", ans[i]);
	}

	return 0;
}
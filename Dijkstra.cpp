// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

bool visit[5005];
int dist[5005];

int main() {
	int n;
	vector<vector<pair<int, int> > > adj;
	priority_queue<pair<int, int> > pq;
	
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0; i < n; i++) {
		dist[i + 1] = INF;
		int a, m;	scanf("%d%d", &a, &m);
		for (int j = 0; j < m; j++) {
			int d, w;	scanf("%d%d", &d, &w);
			adj[a].push_back({ -w,d });
		}
	}

	visit[1] = 1, dist[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int now = pq.top().second, now_dist = -pq.top().first;
		visit[now] = 1;
		pq.pop();
		
		for (int i = 0; i < adj[now].size(); i++) {
			int togo = adj[now][i].second, togo_dist = now_dist + (-adj[now][i].first);
			if (!visit[togo] && dist[togo] > togo_dist) {
				dist[togo] = togo_dist;
				pq.push({ -togo_dist,togo });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);

	printf("%d", ans);

	return 0;
}
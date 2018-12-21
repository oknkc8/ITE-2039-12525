// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int n, p[1001], ans_cnt;
priority_queue < pair<int, pair<int, int> > > pq;// , ans;
vector<pair<int, pair<int, int> > > ans;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = i;
	int x, y, w;
	while (scanf("%d%d%d", &x, &y, &w) != EOF) {
		pq.push({ -w,{-min(x,y),-max(x,y)} });
	}

	while (!pq.empty()) {
		w = -pq.top().first;
		x = -pq.top().second.first;
		y = -pq.top().second.second;
		pq.pop();

		int a = find(x), b = find(y);
		if (a != b) {
			p[a] = b;
			ans_cnt++;
			ans.push_back({ w,{x,y} });
			//ans.push({ -w,{-x,-y} });
		}
	}

	printf("%d\n", ans_cnt);
	//sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) printf("%d %d %d\n", ans[i].second.first, ans[i].second.second, ans[i].first);
	/*while (!ans.empty()) {
		printf("%d %d %d\n", -ans.top().second.first, -ans.top().second.second, -ans.top().first);
		ans.pop();
	}*/

	return 0;
}
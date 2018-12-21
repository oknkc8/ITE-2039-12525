// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

struct info {
	int x, y;
};

int n, v[30000], sum, ans, c;
vector<int> s;
priority_queue<pair<int, pair<int,int> > > pq;
pair<info, int> mp[60000];

void f(int x, int l) {
	pair<info, int> now = mp[x];
	if (now.first.x == -1 && now.first.y == -1) {
		ans += (l*now.second);
		return;
	}
	f(now.first.x, l + 1);
	f(now.first.y, l + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;	cin >> str >> v[i];
		pq.push({ -v[i],{v[i],c++} });
	}
	scanf("%d", &sum);

	int k = n, tk = 0;
	while (k) {
		tk++;
		k /= 2;
	}
	printf("%d\n", sum*tk);

	while (pq.size()>1) {
		pair<int, pair<int,int> > t1 = pq.top(), t2;
		pq.pop();
		t2 = pq.top();
		pq.pop();

		if (t1.second.first != 0) mp[t1.second.second] = { {-1,-1}, t1.second.first };
		if (t2.second.first != 0) mp[t2.second.second] = { { -1,-1 }, t2.second.first };

		mp[c] = { {t1.second.second,t2.second.second},0 };
		pq.push({ t1.first + t2.first, {0, c++} });
	}

	f(c - 1, 0);

	printf("%d\n", ans);

	return 0;
}
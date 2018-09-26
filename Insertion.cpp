// 2017029807_¼ºÃ¢È£_12525

#include<bits/stdc++.h>
using namespace std;

int v[30005];

int main() {
	int n;	scanf("%d", &n);

	int i = 0, j;
	while(i<n){
		scanf("%d", &v[i]);
		j = i - 1;
		while(j>=0){
			if (v[j] < v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
			else break;
			j--;
		}
		i++;
	}

	i = 0;
	while(i<n) printf("%d\n", v[i++]);

	return 0;
}
// 2017029807_¼ºÃ¢È£_12525

#include<stdio.h>
int n, k, heap[100005], cnt;

void swap(int *p1, int *p2) {
	int tmp = *p1;
	*p1 = *p2, *p2 = tmp;
}

void insert(int x) {
	heap[++cnt] = x;
	int t = cnt;
	while (t != 1) {
		if (heap[t] > heap[t / 2]) swap(&heap[t], &heap[t / 2]), t /= 2;
		else break;
	}
}

int pop() {
	int ret = heap[1], idx = 1;
	heap[1] = heap[cnt];
	heap[cnt--] = 0;

	while (1) {
		if (idx * 2 > cnt) break;
		if (heap[idx] >= heap[idx * 2] && heap[idx] >= heap[idx * 2 + 1]) break;
		if (heap[idx * 2] > heap[idx * 2 + 1]) swap(&heap[idx], &heap[idx * 2]), idx *= 2;
		else swap(&heap[idx], &heap[idx * 2 + 1]), idx = idx * 2 + 1;
	}

	return ret;
}

void restore(int idx) {
	if (idx != 1 && heap[idx / 2] < heap[idx]) {
		while (idx != 1) {
			if (heap[idx] > heap[idx / 2]) swap(&heap[idx], &heap[idx / 2]), idx /= 2;
			else break;
		}
	}
	else {
		while (1) {
			if (idx * 2 > cnt) break;
			if (heap[idx] >= heap[idx * 2] && heap[idx] >= heap[idx * 2 + 1]) break;
			if (heap[idx * 2] > heap[idx * 2 + 1]) swap(&heap[idx], &heap[idx * 2]), idx *= 2;
			else swap(&heap[idx], &heap[idx * 2 + 1]), idx = idx * 2 + 1;
		}
	}
}

int main() {
	while (1) {
		int a;	scanf("%d", &a);
		if (!a) break;
		if (a == 1) {
			int x;	scanf("%d", &x);
			insert(x);
		}
		else if (a == 2) printf("%d ", pop());
		else if (a == 3) {
			int x, y;	scanf("%d%d", &x, &y);
			heap[x] = y, restore(x);
		}
	}
	printf("\n");
	for (int i = 1; i <= cnt; i++) printf("%d ", heap[i]);

	return 0;
}
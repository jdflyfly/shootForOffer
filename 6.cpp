#include<stdio.h>

int pre[1005];
int in[1005];
int post[1005];
int idx;
int notTree;

void build(int n, int *pre, int *in) {
	if (n <= 0)
		return;
	int rootVal = pre[0];
	int* rootAdd = NULL;
	int i;
	for (i = 0; i < n; i++)
		if (in[i] == rootVal)
			rootAdd = &in[i];
	if (rootAdd == NULL) {
		notTree = 1;
		return;
	}

	int p = rootAdd - in;
	build(p, pre + 1, in);
	build(n - p - 1, pre + 1 + p, in + 1 + p);
	post[idx++] = rootVal;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;

	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &pre[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &in[i]);
		notTree = 0;
		idx = 0;
		build(n, pre, in);
		if (notTree)
			printf("No\n");
		else {
			for (i = 0; i < n; i++) {
				printf("%d ", post[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

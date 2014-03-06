#include<stdio.h>

int post[10005];

int findFirstLarger(int target, int *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] > target)
			return i;
	}
	return n - 1;
}

int buildTree(int n, int* post) {
	if (n <= 0)
		return 1;
	int root = post[n - 1];
	int idx = findFirstLarger(root, post, n);

	int i;
	for (i = idx; i < n; i++)
		if (post[i] < root)
			return 0;
	int left = buildTree(idx, post);
	int right = buildTree(n - 1 - idx, post + idx);

	return left && right;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &post[i]);
		if (buildTree(n, post))
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}

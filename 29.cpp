#include<stdio.h>

int a[100005];

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void qSelect(int a[], int k, int left, int right) {
	if (left >= right)
		return;

	int pivot = a[right];
	int i = left - 1;
	int j = right;
	while (1) {
		while (a[++i] < pivot)
			if (i >= right)
				break;
		while (a[--j] > pivot)
			if (j < i)
				break;

		if (i < j)
			swap(&a[i], &a[j]);
		else
			break;

	}
	swap(&a[i], &a[right]);
	if (k < i)
		qSelect(a, k, left, i - 1);
	else if (k > i)
		qSelect(a, k, i + 1, right);
	else
		return;

}

int quickSelect(int a[], int n, int k) {

	qSelect(a, k, 0, n - 1);
	int res = a[k];
	int i;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == res)
			count++;
	}
	if (count > n / 2)
		return res;
	else
		return -1;

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int k = n / 2;
		printf("%d\n", quickSelect(a, n, k));

	}

	return 0;
}

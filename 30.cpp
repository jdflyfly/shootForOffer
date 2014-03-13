#include<stdio.h>
#include<stdlib.h>

int a[200005];

int cmp(const void*a, const void*b) {
	return *(int*) a - *(int*) b;
}

void swap(int*a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void qSelect(int a[], int k, int left, int right) {
	if (left >= right)
		return;

	int pivot = a[left];
	int i = left;
	int j = right + 1;
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
	swap(&a[left], &a[j]);

	if (k < j)
		qSelect(a, k, left, j - 1);
	else if (k > j)
		qSelect(a, k, j + 1, right);
	else
		return;

}

void quickSelect(int a[], int n, int k) {
	qSelect(a, k, 0, n - 1);
	qsort(a, k, sizeof(int), cmp);
	int i;
	for (i = 0; i < k; i++) {
		if (i)
			printf(" ");
		printf("%d", a[i]);

	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;

	while (scanf("%d%d", &n, &k) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		quickSelect(a, n, k);

	}
	return 0;
}

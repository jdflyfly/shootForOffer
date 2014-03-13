#include<stdio.h>
#include<stdlib.h>

int a[100005];

//the maximum number exceeds int
long long count;

void merge(int a[], int aux[], int left, int mid, int right) {
	int i, j, idx;
	i = left;
	j = mid + 1;
	idx = left;
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			aux[idx++] = a[i++];
		} else {
			aux[idx++] = a[j++];
			count += mid + 1 - i;
		}

	}
	while (i <= mid) {
		aux[idx++] = a[i++];
	}
	while (j <= right)
		aux[idx++] = a[j++];

	for (i = left; i <= right; i++)
		a[i] = aux[i];

}

void mergeSort(int a[], int aux[], int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	mergeSort(a, aux, left, mid);
	mergeSort(a, aux, mid + 1, right);
	merge(a, aux, left, mid, right);

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		count = 0;
		int* aux = (int*) malloc(sizeof(int) * n);
		mergeSort(a, aux, 0, n - 1);
		free(aux);

		printf("%lld\n", count);

	}

	return 0;
}

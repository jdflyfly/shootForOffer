#include<stdio.h>
int a[1000005];

int getMin(int l, int r) {
	int min = 0x7fffffff;
	int i;
	for (i = l; i <= r; i++)
		if (a[i] < min) {
			min = a[i];
		}

	return min;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		if (a[0] < a[n - 1]) { //no pivot
			printf("%d\n", a[0]);

		} else {
			int l = 0;
			int r = n - 1;
			int mid;
			int breakOut = 0;
			while (r - l > 1) {
				mid = (l + r) / 2;
				if (a[mid] == a[l] && a[mid] == a[r]) {
					printf("%d\n", getMin(l, r));
					breakOut = 1;
					break;
				}

				if (a[mid] > a[l]) {
					l = mid;
				} else {
					r = mid;
				}

			}
			if (!breakOut)
				printf("%d\n", a[r]);

		}

	}

	return 0;
}

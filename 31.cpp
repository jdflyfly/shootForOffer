#include<stdio.h>

int a[100000 + 5];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n)) {
		if (n == 0)
			break;

		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		int maxSum =0x80000000;
		int leftIdx = 0;
		int rightIdx = 0;
		int thisSum = 0;

		int start = 0;
		for (i = 0; i < n; i++) {

			thisSum += a[i];
			if (thisSum > maxSum) {
				maxSum = thisSum;
				leftIdx = start;
				rightIdx = i;
			}
			if (thisSum < 0) {
				thisSum = 0;
				start = i + 1;
			}
		}

		printf("%d %d %d\n", maxSum, leftIdx, rightIdx);

	}

	return 0;
}

#include<stdio.h>

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n <= 1) {
			printf("1\n");
			continue;
		}
		long long first = 0;
		long long second = 1;
		int i;
		long long sum = 0;
		for (i = 0; i < n-1 ; i++) {
			sum = first + second;
			first = second;
			second = sum;
		}
		printf("%lld\n", sum);
	}

	return 0;
}

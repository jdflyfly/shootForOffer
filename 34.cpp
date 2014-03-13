#include<stdio.h>

int u[1505];

int getMin(int a, int b, int c) {
	int min = a < b ? a : b;
	return min < c ? min : c;

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		u[1] = 1;
		int i;
		int t2 = 1, t3 = 1, t5 = 1;
		for (i = 2; i <= n;) {
			int p2 = 2 * u[t2];
			int p3 = 3 * u[t3];
			int p5 = 5 * u[t5];
			int min = getMin(p2, p3, p5);

			if (min == p2)
				t2++;
			else if (min == p3)
				t3++;
			else
				t5++;
			if (min == u[i - 1])
				continue;

			u[i] = min;
			i++;
		}

		printf("%d\n", u[n]);
	}

	return 0;
}

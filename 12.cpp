#include<stdio.h>

int a[100];

void print(int n, int cur) {
	if (cur == n) {
		int i;
		int started = 0;
		for (i = 0; i < n; i++) {
			if (a[i] == 0 && started)
				printf("%d", a[i]);
			if (a[i]) {
				printf("%d", a[i]);
				started = 1;
			}
		}
		if (started)
			printf("\n");
		return;
	}
	int j;
	for (j = 0; j < 10; j++) {
		a[cur] = j;
		print(n, cur + 1);
	}

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	print(n, 0);

	return 0;
}

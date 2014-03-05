#include<stdio.h>
#include<stdlib.h>

int a[100000];
int b[100000];
int idxA;
int idxB;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	int i;
	int tmp;
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);

		if (tmp % 2 == 1)
			a[idxA++] = tmp;
		else
			b[idxB++] = tmp;
	}

	for (i = 0; i < idxA; i++) {
		printf("%d ", a[i]);
	}
	for (i = 0; i <idxB ; i++) {
		if (i)
			printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");

	return 0;
}

#include<stdio.h>

int mat[1005][1005];

void printCircle(int m, int n, int start) {
	int endX = n - 1 - start;
	int endY = m - 1 - start;
	if (endX >= start) {
		int i;
		for (i = start; i <= endX; i++)
			printf("%d ", mat[start][i]);
	}
	if (endY > start) {
		int i;
		for (i = start + 1; i <= endY; i++)
			printf("%d ", mat[i][endX]);
	}

	if (endY > start && start < endX) {
		int i;
		for (i = endX - 1; i >= start; i--)
			printf("%d ", mat[endY][i]);
	}

	if (start < endY - 1 && start < endX) {
		int i;
		for (i = endY - 1; i >= start + 1; i--) {
			printf("%d ", mat[i][start]);
		}
	}

}

int main() {
//	freopen("in.txt", "r", stdin);
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		int i, j;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &mat[i][j]);

		int start = 0;
		while (start * 2 < m && start * 2 < n) {
			printCircle(m, n, start);
			start++;
		}
		printf("\n");

	}
	return 0;
}

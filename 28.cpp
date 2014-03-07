#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char per[10];

int cmp(const void*a, const void*b) {
	return *(char*) a - *(char*) b;
}

void print(char* str, int n, int cur) {
	if (cur == n) {
		per[n] = 0;
		printf("%s\n", per);
	} else {
		int i;
		for (i = 0; i < n; i++)
			//if prevent the repeated permutation of the same char
			if (!i || str[i] != str[i - 1]) {
				int j;
				//c1 and c2 count the number of repeated char
				int c1 = 0, c2 = 0;
				for (j = 0; j < cur; j++) {
					if (str[i] == per[j]) {
						c1++;
					}
				}
				for (j = 0; j < n; j++) {
					if (str[i] == str[j]) {
						c2++;
					}
				}
				if (c1 < c2) {
					per[cur] = str[i];
					print(str, n, cur + 1);
				}
			}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	char str[10];
	while (scanf("%s", str) != EOF) {
		qsort(str, strlen(str), sizeof(char), cmp);
		print(str, strlen(str), 0);

	}

	return 0;
}

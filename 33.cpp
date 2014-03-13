#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[105];

int cmp(const void*a, const void*b) {
	int aInt = *(int*) a;
	int bInt = *(int*) b;
	char aStr[15];
	char bStr[15];
	sprintf(aStr, "%d", aInt);
	sprintf(bStr, "%d", bInt);
	char sum1[30];
	char sum2[30];
	strcpy(sum1, aStr);
	strcat(sum1, bStr);
	strcpy(sum2, bStr);
	strcat(sum2, aStr);
	return strcmp(sum1, sum2);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		for(i=0;i<n;i++){
			printf("%d",a[i]);
		}
		printf("\n");

	}

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int myPow(int n) {
	int prod = 1;
	int i = 0;
	for (i = 0; i < n; i++)
		prod *= 10;

	return prod;

}

int countOneStr(char* str) {
	int n = strlen(str);
	if (n == 0)
		return 0;

	int ones = 0;
	int first = str[0] - '0';

	if (n == 1 && first == 0)
		return 0;
	else if (n == 1 && first > 0)
		return 1;

	if (first > 1)
		ones += myPow(n - 1);
	//don't miss first==1
	else if (first == 1)
		ones += atoi(str + 1) + 1;
	if (n >= 2) {
		ones += first * (n - 1) * myPow(n - 2);

		ones += countOneStr(str + 1);
	}
	return ones;
}

int countOne(int n) {
	if (n <= 0)
		return 0;
	char numStr[50];
	sprintf(numStr, "%d", n);
	return countOneStr(numStr);

}


//be careful about some cases, such as 10000
int main() {
//	freopen("in.txt", "r", stdin);
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}

		int countA = countOne(a - 1);
		int countB = countOne(b);
		printf("%d\n", countB - countA);

	}

	return 0;
}

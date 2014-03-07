#include<stdio.h>

#define NO_MEANING 1

int equal(double a, double b) {
	if (a - b > -0.0000001 && a - b < 0.0000001)
		return 1;
	else
		return 0;
}

double recursivePow(double base, unsigned int exp) {
	if (exp == 0)
		return 1.0;
	else if (exp == 1)
		return base;

	if (exp % 2 == 0) {
		double half = recursivePow(base, exp / 2);
		return half * half;
	} else {
		double half = recursivePow(base, (exp - 1) / 2);
		return half * half * base;
	}

}

double myPow(double base, int exp, int* flag) {

	if (equal(base, 0.0)) {
		if (exp <= 0) {
			*flag = NO_MEANING;
			return 0.0;
		} else
			return 0.0;
	}

	if (exp == 0)
		return 1.0;
	else if (exp == 1)
		return base;

	double res = 1;
	int neg = 0;

	if (exp < 0) {
		exp = -exp;
		neg = 1;
	}
	res = recursivePow(base, (unsigned int) exp);

	if (neg)
		res = 1 / res;

	return res;

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	double base;
	int exp;
	while (n--) {
		scanf("%lf%d", &base, &exp);
		int flag = 0;
		double res = myPow(base, exp, &flag);
		if (!flag)
			printf("%.2ef\n", res);
		else
			printf("INF\n");

	}

	return 0;
}

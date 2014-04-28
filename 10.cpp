#include<stdio.h>

int count(int num) {
	int cnt = 0;
	while (num) {
		cnt++;
		num = num & (num - 1);
	}
	return cnt;
}



int main() {
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d", &n);
	int num;
	while (n--) {
		scanf("%d", &num);
		printf("%d\n", count(num));
	}

	return 0;
}

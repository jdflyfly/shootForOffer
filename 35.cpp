#include<stdio.h>
#include<string.h>

char str[10005];

char flag[26];

int main() {
//	freopen("in.txt", "r", stdin);
	while (scanf("%s", str) != EOF) {
		memset(flag,0,sizeof(flag));
		int i;
		for (i = 0; str[i]; i++) {
			flag[str[i] - 'A']++;
		}
		int found = 0;
		for (i = 0; i < 26; i++) {
			if (flag[i] == 1) {
				found = 1;
				break;
			}
		}
		if (found)
			printf("%d\n", i);
		else
			printf("-1\n");

	}

	return 0;
}

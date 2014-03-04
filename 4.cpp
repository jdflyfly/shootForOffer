#include <stdio.h>
#include <string.h>

int main(void) {
//	freopen("in.txt","r",stdin);
	char str[1000001];
	int len;
	int new_len;
	int i;
	int cnt;

	gets(str);
	len = strlen(str);
	cnt = 0;
	for (i = 0; i < len; ++i) {
		if (str[i] == ' ')
			++cnt;
	}
	new_len = len + 2 * cnt;
	str[new_len] = '\0';
	--len;
	--new_len;
	while (len >= 0) {
		if (str[len] != ' ') {
			str[new_len] = str[len];
			--new_len;
			--len;
		} else {
			str[new_len] = '0';
			str[new_len - 1] = '2';
			str[new_len - 2] = '%';
			new_len -= 3;
			--len;
		}
	}
	puts(str);

	return 0;
}

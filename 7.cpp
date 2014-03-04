#include<stdio.h>
#include<stack>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	stack<int> a;
	stack<int> b;
	scanf("%d", &n);
	char cmd[10];
	int num;
	while (n--) {
		scanf("%s", cmd);
		if (cmd[1] == 'U') {
			scanf("%d", &num);
			a.push(num);

		} else {
			if (b.empty()) {
				if (a.empty()) {
					printf("-1\n");
				} else {
					while (!a.empty()) {
						b.push(a.top());
						a.pop();
					}
					printf("%d\n", b.top());
					b.pop();

				}

			} else {
				printf("%d\n", b.top());
				b.pop();
			}

		}

	}

	return 0;
}

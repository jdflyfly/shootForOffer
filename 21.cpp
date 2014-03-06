#include<stdio.h>
#include<stack>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;

	while (scanf("%d", &n) != EOF) {
		stack<int> s;
		stack<int> min;
		char cmd[2];
		int val;
		while (n--) {
			scanf("%s", cmd);
			if (cmd[0] == 's') {
				scanf("%d", &val);
				s.push(val);
				if (min.size() == 0)
					min.push(val);
				else
					min.push(min.top() < val ? min.top() : val);

				printf("%d\n", min.top());
			} else {
				if (!s.empty() && !min.empty()) {
					s.pop();
					min.pop();
					if (min.size() != 0)
						printf("%d\n", min.top());
					else
						printf("NULL\n");

				} else
					printf("NULL\n");
			}
		}

	}

	return 0;
}

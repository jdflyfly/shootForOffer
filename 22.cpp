#include<stdio.h>
#include<stack>

using namespace std;

int in[100005];
int out[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &in[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &out[i]);

		stack<int> s;
		int a = 0, b = 0;
		int ok = 1;
		while (b < n) {
			if (!s.empty() && s.top() == out[b]) {
				s.pop();
				b++;
			} else {
				if (a < n)
					s.push(in[a++]);
				else {
					ok = 0;
					break;
				}
			}

		}

		if (ok)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}

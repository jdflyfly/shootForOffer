#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct Child {
	char ch;
	int l;
	int r;
} Child;

Node* createNode(int v) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->val = v;
	node->left = node->right = NULL;
	return node;
}

int value[1005];
Child children[1005];

Node* build(Node* root, int idx) {
	root = createNode(value[idx]);
	if (children[idx].ch == 'd') {
		root->left = build(root->left, children[idx].l);
		root->right = build(root->right, children[idx].r);
	} else if (children[idx].ch == 'l')
		root->left = build(root->left, children[idx].l);
	else if (children[idx].ch == 'r')
		root->right = build(root->right, children[idx].r);
	else
		;
	return root;

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			printf("NULL\n");
			continue;
		}

		int i;
		for (i = 1; i <= n; i++) {
			scanf("%d", &value[i]);
		}
		char type[2];
		for (i = 1; i <= n; i++) {
			scanf("%s", type);
			if (type[0] == 'd') {
				scanf("%d%d", &children[i].l, &children[i].r);
				children[i].ch = 'd';
			} else if (type[0] == 'l') {
				scanf("%d", &children[i].l);
				children[i].ch = 'l';
			} else if (type[0] == 'r') {
				scanf("%d", &children[i].r);
				children[i].ch = 'r';

			} else {
				children[i].ch = 'z';
			}
		}
		Node* root = NULL;
		root = build(root, 1);
		int printCount = 0;

		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			Node* cur = que.front();
			que.pop();
			if (printCount)
				printf(" ");
			printCount++;
			printf("%d", cur->val);
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}

	}

	return 0;
}

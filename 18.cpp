
//有case未果，待找bug

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int val;
	struct Node*left;
	struct Node*right;
} Node;

Node* createNode(int v) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->val = v;
	node->left = node->right = NULL;
	return node;
}

int a[1005];
int b[1005];

int matA[1005][1005];
int matB[1005][1005];
int n, m;

Node* buildA(Node* root, int num) {
	root = createNode(a[num]);
	int i;
	int left = true;
	for (i = 1; i <= n; i++) {
		if (matA[num][i]) {
			if (left) {
				root->left = buildA(root->left, i);
				left = 0;
			} else
				root->right = buildA(root->right, i);
		}
	}
	return root;
}

Node* buildB(Node* root, int num) {
	root = createNode(b[num]);
	int i;
	int left = true;
	for (i = 1; i <= m; i++) {
		if (matB[num][i]) {
			if (left) {
				root->left = buildB(root->left, i);
				left = 0;
			} else
				root->right = buildB(root->right, i);
		}
	}
	return root;
}

int isEqual(Node* treeA, Node*treeB) {
	if (treeB == NULL)
		return true;
	if (treeA == NULL)
		return false;

	if (treeA->val != treeB->val)
		return 0;

	return isEqual(treeA->left, treeB->left)
			&& isEqual(treeA->right, treeB->right);

}

int isSubTree(Node* treeA, Node* treeB) {
	if (treeA == NULL || treeB == NULL)
		return 0;
	int res = 0;
	if (treeA->val == treeB->val) {
		res = isEqual(treeA, treeB);
	}
	if (!res)
		res = isSubTree(treeA->left, treeB);
	if (!res)
		res = isSubTree(treeA->right, treeB);

	return res;

}

int main() {
//	freopen("in.txt", "r", stdin);

	while (scanf("%d%d", &n, &m) != EOF) {
		memset(matA, 0, sizeof(matA));
		memset(matB, 0, sizeof(matB));

		int i;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			int j, val;
			for (j = 1; j <= num; j++) {
				scanf("%d", &val);
				matA[i][val] = 1;
			}

		}

		for (i = 1; i <= m; i++) {
			scanf("%d", &b[i]);
		}
		for (i = 1; i <= m; i++) {
			int num;
			scanf("%d", &num);
			int j, val;
			for (j = 1; j <= num; j++) {
				scanf("%d", &val);
				matB[i][val] = 1;
			}

		}

		Node* rootA = buildA(rootA, 1);
		Node* rootB = buildB(rootB, 1);

		int res = isSubTree(rootA, rootB);
		if (res)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;

} Node;

Node * createNode(int v) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->val = v;
	node->next = NULL;
	return node;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		Node head;
		head.val = -1;
		head.next = NULL;
		int tmp;
		Node* p = &head;
		int i;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			Node* newNode = createNode(tmp);
			p->next = newNode;
			p = p->next;
		}


		if (k <= 0 || k > n) {
			printf("NULL\n");
			continue;
		}

		p = head.next;
		Node*q = head.next;
		for (i = 0; i < k - 1; i++)
			q = q->next;
		while (q->next != NULL) {
			p = p->next;
			q = q->next;
		}
		printf("%d\n", p->val);

	}

	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;

} Node;

Node* createNode(int v) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->val = v;
	node->next = NULL;
	return node;
}

Node* reverse(Node* first) {
	Node* newHead = createNode(-1);
	Node* cur = first;
	Node* pre = NULL;

	while (cur != NULL) {
		Node* post = cur->next;
		if (post == NULL)
			newHead->next = cur;
		cur->next = pre;

		pre = cur;
		cur = post;

	}
	return newHead;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			printf("NULL\n");
			continue;
		}

		Node head;
		head.val = -1;
		head.next = NULL;
		int i;
		int tmp;
		Node* p = &head;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			p->next = createNode(tmp);
			p = p->next;
		}

		Node* newHead = reverse(head.next);

		p = newHead->next;
		while (p != NULL) {
			printf("%d", p->val);
			if (p->next != NULL)
				printf(" ");
			p = p->next;
		}
		printf("\n");

	}

	return 0;
}

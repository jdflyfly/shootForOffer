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

Node* merge(Node*head1, Node*head2) {
	Node* newHead;
	if (head1->val < head2->val)
		newHead = head1;
	else
		newHead = head2;
	Node* cur1 = head1;
	Node* cur2 = head2;

	Node* tmpEnd = createNode(-1);
	while (cur1 != NULL || cur2 != NULL) {
		if (cur1 == NULL) {
			tmpEnd->next = cur2;
			break;
		} else if (cur2 == NULL) {
			tmpEnd->next = cur1;
			break;

		} else {
			if (cur1->val < cur2->val) {
				tmpEnd->next = cur1;
				tmpEnd = cur1;
				cur1 = cur1->next;
			} else {
				tmpEnd->next = cur2;
				tmpEnd = cur2;
				cur2 = cur2->next;
			}

		}

	}

	return newHead;
}

void print(Node*p) {
	if (p == NULL) {
		printf("NULL\n");
		return;
	}
	while (p != NULL) {
		printf("%d", p->val);
		if (p->next)
			printf(" ");
		p = p->next;
	}
	printf("\n");

}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		Node* head1 = createNode(-1);
		Node* head2 = createNode(-1);

		if (n > 0) {
			int countN = n;
			Node* p = head1;
			int tmp;
			while (countN--) {
				scanf("%d", &tmp);
				p->next = createNode(tmp);
				p = p->next;
			}

		}

		if (m > 0) {
			int countM = m;
			Node* p = head2;
			int tmp;
			while (countM--) {
				scanf("%d", &tmp);
				p->next = createNode(tmp);
				p = p->next;
			}
		}

		if (n == 0 && m != 0) {
			print(head2->next);
		} else if (n != 0 && m == 0)
			print(head1->next);
		else if (m == 0 && n == 0)
			print(NULL);
		else {
			print(merge(head1->next, head2->next));

		}

	}

	return 0;
}

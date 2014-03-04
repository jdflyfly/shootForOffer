#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node* newNode(int val) {
	Node* node = (Node*) malloc(sizeof(Node));
	if (node != NULL) {
		node->val = val;
		node->next = NULL;
	} else {
		exit(0);
	}
	return node;
}

void print(Node* cur) {
	if (cur->next != NULL) {
		print(cur->next);
	}
	printf("%d\n", cur->val);

}

int main() {
//	freopen("in.txt", "r", stdin);
	int num;
	Node head;
	head.val = -1;
	head.next = NULL;

	Node* cur = &head;
	while (scanf("%d", &num)) {
		if (num == -1)
			break;
		cur->next = newNode(num);
		cur = cur->next;

	}

	print(head.next);

	return 0;
}

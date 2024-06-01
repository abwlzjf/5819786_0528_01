#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
}ListNode;

void menu() {
	printf("메뉴:\n");
	printf("1: 숫자 입력 받아서 리스트 처음에 추가\n");
	printf("2: 숫자 입력 받아서 리스트 마지막에 추가\n");
	printf("3: 리스트 처음 노드 삭제\n");
	printf("4: 리스트 마지막 노드 삭제\n");
	printf("5: 리스트 프린트\n");
	printf("6: 종료\n");
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = NULL;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		printf("리스트가 비어있음.\n");
		return head;
	}
	ListNode* removed = head->link;
	if (removed == head) {
		free(removed);
		head = NULL;
	}
	else {
		head->link = removed->link;
		free(removed);
	}
	return head;
}

ListNode* delete_last(ListNode* head) {

	if (head == NULL) {
		printf("리스트가 비어있음.\n");
		return head;
	}
	ListNode* pre = head;
	ListNode* removed = head->link;
	if (pre == removed) {
		free(removed);
		head = NULL;
		return head;
	}
	else {
		while (removed != head) {
			pre = removed;
			removed = removed->link;
		}
		pre->link = head->link;
		free(removed);
		return pre;
	}
}

void print_list(ListNode* head) {
	ListNode* p = head;
	if (head == NULL) return NULL;
	p = p->link;
	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head->link);
	printf("%d (head) \n", p->data);
}

int main() {
	ListNode* head = NULL;
	int choice;

	while (1) {
		int n;
		menu();
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 숫자를 입력하세요: ");
			scanf_s("%d", &n);
			head = insert_first(head, n);
			printf("입력완료\n");
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf_s("%d", &n);
			head = insert_last(head, n);
			printf("입력완료\n");
			break;
		case 3:
			head = delete_first(head);
			printf("삭제완료\n");
			break;
		case 4:
			head = delete_last(head);
			printf("삭제완료\n");
			break;
		case 5:
			print_list(head);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
			break;
		}
	}
}
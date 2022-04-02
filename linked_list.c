#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node* next;
};

struct linkedList {
	struct node* head;
	struct node* tail;
	int length;
};

struct linkedList* createLinkedList(){
	struct linkedList* list = malloc(sizeof(struct linkedList));

	list->head = NULL;
	list->tail = list->head;
	list->length = 0;

	return list;
}

int insertItem(int item, struct linkedList* list) {
	
	struct node* pNode = malloc(sizeof(struct node));
	pNode->item = item;
	pNode->next = NULL;
	
	if (list->length == 0) {
		list->head = pNode;
	}
	else {
		pNode->next = list->head;
		list->head = pNode;
	}

	list->length++;
}

int deleteItem(int item, struct linkedList* list) {
	if (list->length == 0) {
		return 0;
	}

	struct node* current = list->head;

	if (current->item == item) {
		list->head = current->next;
		free(current);
		list->length--;
		return 1;
	}

	while (current->next->next != NULL) {
		if (current->next->item == item) {
			struct node* dropNode = current->next;
			current->next = dropNode->next;
			free(dropNode);
			list->length--;
			return 1;
		}

		current = current->next;
	}

	if (current->next->item == item) {
		free(current->next);
		current->next = NULL;
		list->length--;
		return 1;
	}

	return 0;
}

int getLength(struct linkedList* list) {
	return list->length;
}

int searchItem(int item, struct linkedList* list) {
	struct node* current = list->head;
	int position = 1;

	while (current != NULL) {
		if (current->item == item) {
			return position;
		}
		current = current->next;
		position++;
	}

	return -1;
}

int sort(struct linkedList* list);

void printList(struct linkedList* list) {
	printf_s("length : %d\n", getLength(list));

	struct node* pCurrent = list->head;

	while (pCurrent != NULL){
		printf_s("%d, ", pCurrent->item);
		pCurrent = pCurrent->next;
	}

	printf_s("\n");
}

int main() {
	struct linkedList* list = createLinkedList();

	insertItem(1, list);
	insertItem(2, list);
	insertItem(3, list);
	insertItem(4, list);
	insertItem(5, list);
	insertItem(6, list);
	insertItem(7, list);
	insertItem(8, list);

	printList(list);

	deleteItem(1, list);
	deleteItem(5, list);
	deleteItem(8, list);

	printList(list);

	searchItem(6, list);

	return 0;
}
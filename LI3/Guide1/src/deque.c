//#include "deque.h"
//#include "node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	Node* start;
	Node* end;
	int size;
} Deque;

typedef struct node {
	void* data;
	struct node* next;
	struct node* prev;
} Node;

Node* nodeCreate(void* data) {
	Node* new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	return new;
}

Deque* create() {
	Deque* d = malloc(sizeof(Deque));
	d->start = NULL;
	d->end = NULL;
	d->size = 0;
	return d;
}

void push(Deque* deque, void* data) {
	Node* n = nodeCreate(data);
	n->prev = deque->end;
	deque->end = n;
	deque->size++;
}

void pushFront(Deque* deque, void* data) {
	Node* n = nodeCreate(data);
	n->next = deque->start;
	deque->start = n;
	deque->size++;
}

void* pop(Deque* deque) {
	if (deque->size == 0) return NULL;
	Node* n = deque->end;
	if (deque->size == 1) {
		deque->start = NULL;
		deque->end = NULL;
	}
	else {
		deque->end = deque->end->prev;
		deque->end->next = NULL;
	}
	void* data = n;
	free(n);
	deque->size--;
	return data;
}

void* popFront(Deque* deque) {
	if (deque->size == 0) return NULL;
	Node* n = deque->start;
	if (deque->size == 1) {
		deque->start = NULL;
		deque->end = NULL;
	}
	else {
		deque->start = deque->start->next;
		deque->start->prev = NULL;
	}
	void* data = n;
	free(n);
	deque->size--;
	return data;
}

int size(Deque* deque) {
	return deque->size;
}

bool isEmpty(Deque* deque) {
	return deque->size==0;
}

void reverse(Deque* deque) {

}

void printDeque(Deque* deque, void(*printFunc)(void*)) {

}

void destroy(Deque* deque) {

}
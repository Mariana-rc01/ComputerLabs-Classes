#ifndef NODE
#define NODE

typedef struct node {
	void* data;
	struct node* next;
	struct node* prev;
} Node;

// Cria um novo nodo
Node* nodeCreate(void* data);

#endif
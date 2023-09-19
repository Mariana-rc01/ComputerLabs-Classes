#ifndef DEQUE
#define DEQUE

#include "node.h"

#include <stdbool.h>

typedef struct {
	Node* start;
	Node* end;
	int size;
} Deque;

/* Inicialize uma Deque sem elementos*/
Deque* create();

/* Adiciona data no fim da fila*/
void push(Deque* deque, void* data);

/* Adiciona data no início da fila*/
void pushFront(Deque* deque, void* data);

/* Remove o elemento do fim da fila e retorna-o; retorna NULL se a fila não tiver elementos*/
void* pop(Deque* deque);

/* Remove o elemento do início da fila e retorna-o; retorna NULL se a fila não tiver elementos*/
void* popFront(Deque* deque);

/* Retorna o número de elementos da fila*/
int size(Deque* deque);

/* Indica se a fila está vazia*/
bool isEmpty(Deque* deque);

/* Inverte a ordem dos elementos da fila*/
void reverse(Deque* deque);

/* Imprime os elementos da fila com o auxílio da função printFunc */
void printDeque(Deque* deque, void(*printFunc)(void*));

/* Liberta a memória associada à Deque*/
void destroy(Deque* deque);

#endif

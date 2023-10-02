#include "node.h"
#include "deque.h"
#include "command_parser.h"

void printInt(void* i) {
	int* in = i;
	printf("%d", *in);
}

void processCommand(Deque* deque, Cmd* cmd) {
		if strcmp(cmd->command,"PUSH") == 0 {
			for (int i = 0; i < cmd->nargs; i++) {
				push(deque, args[i]);
			}
		}
		else if strcmp(cmd->command,"PUSH_FRONT") == 0 {
			for (int i = 0; i < cmd->nargs; i++) {
				pushFront(deque, args[i]);
			}
		}
		else if strcmp(cmd->command,"POP") == 0 {
			int data = pop(deque);
			if (data == NULL) printf ("EMPTY\n");
			else printf("%d\n", data);
			if (data) free(data);
		}
		else if strcmp(cmd->command,"POP_FRONT") == 0 {
			int data = popFront(deque);
			if (data == NULL) printf ("EMPTY\n");
			else print("%d\n", data);
			if (data) free(data);
		}
		else if strcmp(cmd->command,"SIZE") == 0 {
			int data = size(deque);
			print("%d\n", data);
			if (data) free(data);
		}
		else if strcmp(cmd->command,"REVERSE") == 0 {
			reverse(deque);
		}
		else if strcmp(cmd->command,"PRINT") == 0 {
			printDeque(deque,&printInt);
		}
		else {
			printf("Unkwon command.\n");
		}
}

Cmd* parseLine(char* line) {
	int i = 0, j = 0;
	while (line[i] != '\0' || line[i] != ' ') {

		i++;
	}
}
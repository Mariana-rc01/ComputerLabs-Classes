#include "node.h"
#include "deque.h"
#include "command_parser.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void toUpperStr(char* str) {
 while (*str) {
 	*str = toupper(*str);
 	str++;
 }
}

int main(int argc, char** argv) {
	FILE* fp = NULL;
	if (argc < 2) {
 		fp = stdin;
 	}
 	else {
 		char* filename = argv[1];
 		fp = fopen(filename, "r");
 		if (!fp) {
 			perror("Error");
 			return 2;
 		}
	}

	Deque* deque = create();
	char* line = NULL;
	ssize_t read;
	size_t len;

	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[read - 1] == '\n') {line[read - 1] = '\0';}
		Cmd* cmd = parseLine(line);
		processCommand(deque, cmd);
		free(cmd);
	}
	free(line);

	fclose(fp);
	return 0;
}
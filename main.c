#include "stdio.h"

#define FILENAME_MAX 4096

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: hexx <filename>\n");
		return 0;
	}

	FILE *file = fopen(argv[1], "rb");
	if (file == NULL) {
		printf("Unable to open file %s", argv[1]);
		return 0;
	}

	int ch;
	while ((ch = fgetc(file)) != EOF) {
		printf("%02X ", ch);
	}

	printf("\n");

	fclose(file);
	return 0;
}
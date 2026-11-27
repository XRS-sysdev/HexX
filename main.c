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
	int bytes = 0;
	int total_bytes = 0;
	int counter = 0;
	printf("%d | ", counter);
	while ((ch = fgetc(file)) != EOF) {
		if (bytes == 16) {
			counter++;
			printf("\n%02X | ", (counter * 16));
			bytes = 0;
		}
		printf("%02X ", ch);
		bytes++;
		total_bytes++;
	}

	printf("\n");

	fclose(file);
	return 0;
}
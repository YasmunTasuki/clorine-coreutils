#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (access(argv[i], F_OK) != 0) {
			printf("cat: %s: No such file or directory\n", argv[i]);
			continue;
		}
		struct stat path_stat;
		stat(argv[i], &path_stat);
		if (!S_ISREG(path_stat.st_mode)) {
			printf("cat: %s: Is a directory or a non standard file\n", argv[i]);
			continue;
		}
		FILE* file;
		file = fopen(argv[i], "r");
		if (file==NULL) {
			printf("cat: %s: Could not open file\n", argv[i]);
			continue;
		}
		char ch;
		bool isEOF;
		do {
			ch = fgetc(file);
			isEOF = ch==EOF;
			if (!isEOF) printf("%c", ch);
		} while (!isEOF);
		fclose(file);
	}
	return 0;
}

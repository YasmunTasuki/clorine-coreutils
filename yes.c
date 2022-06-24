#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	char str[256];
	if (argc>1) {
		for (int i = 1; i < argc; i++) {
			if (i>1) strcat(str, " ");
			strcat(str, argv[i]);
		}
	} else {
		strcpy(str, "y");
	}

	while(true) {
		printf("%s\n", str);
	}
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

void strrev(char *str1) {
	int i, len, temp;
	len = strlen(str1);
	for (i = 0; i < len/2; i++) {
		temp = str1[i];
		str1[i] = str1[len - i - 1];
        	str1[len - i - 1] = temp;
	}
}

int main(int argc, char *argv[]) {
	if (argc <2) {
		printf("%s: missing operand\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		strrev(argv[i]);
		char *ptr;
		ptr = strchr(argv[i], '/');
		if (ptr != NULL) {
			*ptr = '\0';
		}
		strrev(argv[i]);
		printf(argv[i]);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		char const *name = argv[1];
		if (sethostname (name, strlen (name)) != 0) {
			printf ("%s: cannot set name to %s, are you running it as root\n", argv[0], name);
			return 1;
		}
		return 0;
	}
	int ret;
	char hostname[256];
	ret = gethostname(&hostname[0], 256);

	if (ret == -1) {
		printf("couldn't determine hostname");
		return 1;
	}
	puts(hostname);
	return 0;
}

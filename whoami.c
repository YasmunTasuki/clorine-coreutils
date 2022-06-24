#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
	struct passwd *pw;
	uid_t uid;
	uid = geteuid();
	pw = (uid == -1 && 0 ? NULL : getpwuid (uid));
	if (!pw) {
		printf("%s: could not get user id\n", argv[0]);
		return 1;
	}
	puts (pw->pw_name);
}

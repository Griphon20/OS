#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char Buffer[1 << 25] = { 1 };
int odds[] = { 1, 3, 5, 7 };
int f(int x) {
	static char buffer[1 << 25] = { 1 };
	return x * x * x;
}


int main(int argc, char* argv[]) {
	int n = 3;
	static char mbuf[1 << 23] = { 1 };
	char* p;
	p = malloc(1 << 21);
	printf("f(%d)=%d\n", n, f(n));
	pause();
	free(p);
	return 0;
}

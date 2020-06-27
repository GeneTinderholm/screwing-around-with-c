#include <stdio.h>
int main(void) {
	char c = 'a';
	printf("%u", (long) &c);
	return 0;
}

#include <stdint.h>
#include <stdio.h>

extern int32_t increment(int32_t);

int main(int argc, char *argv[]) {
	int32_t v;
	v = 0; printf("increment(%d) == %d\n", v, increment(v));
	v = 1; printf("increment(%d) == %d\n", v, increment(v));
	v = 10; printf("increment(%d) == %d\n", v, increment(v));
	v = 15; printf("increment(%d) == %d\n", v, increment(v));
	return 0;
}


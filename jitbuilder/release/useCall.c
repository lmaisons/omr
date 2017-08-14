#include <stdint.h>
#include <stdio.h>

extern int32_t test_calls(int32_t);

int32_t
doublesum(int32_t first, int32_t second) {
	int32_t result = (second << 1) + (first << 1);
	fprintf(stderr, "doublesum(%d, %d) == %d\n", first, second, result);
	return result;
}

int main(int argc, char *argv[]) {
	for (int32_t n=0; n < 10; n++) {
		printf("call(%2d) = %d\n", n, test_calls(n));
	}
	return 0;
}


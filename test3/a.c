#include <stdio.h>
#include <stdlib.h>
/*
#include <srp_vector.h>
*/
int main() {
	long long a[64];
	long long b[64];
	memset(a, 0, 64 * sizeof(long long));
	memset(b, 0, 64 * sizeof(long long));
	b[31] = 1;

	printf("%d\n", musl_memcmp(a, b, 64 * sizeof(long long)));
/*
	long long a = 0;
	long long b = 1;

	printf("%d\n", musl_memcmp(&a, &b, sizeof(long long)));
*/

return 0;

}

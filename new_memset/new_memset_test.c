#include <string.h>
#include <stdint.h>
#include <srp_vector.h>
#include <stdio.h>
#define WS sizeof(uint16)

int main (){

	char *ptr = (char*) malloc(641);
	ptr[640] = '\0';
	
	for(int i = 0; i <500; i++)
		musl_memset(ptr, 'a', 640);
	puts(ptr);
	
	free(ptr);
	return 0;
}


#include <string.h>
#include <stdio.h>
#define WS sizeof(float16)

int main (){

	char * ptr_sour = "samsung reconfigurable processor c standard libray project\nsamsung reconfigurable processor c standard libray project\nsamsung reconfigurable processor c standard libray project\nsamsung reconfigurable processor c standard libray project";
	char   *ptr_dest;


	ptr_dest = (char *)malloc( strlen(ptr_sour) + 1);

	for(int i = 0; i < 1000; i++)
		musl_memcpy( ptr_dest, ptr_sour, strlen( ptr_sour)+1); 

	printf( "%s\n", ptr_dest);

	free( ptr_dest);

	return 0;
}


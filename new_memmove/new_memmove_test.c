#include <stdio.h>
#include <srp_vector.h>
#define WT size_t
#define WS (sizeof(char8))

void *n_memmove(void *dest, const void *src, size_t n)
{
        char *d = dest;
        const char *s = src;

        if (d==s) return d;
        if (s+n <= d || d+n <= s) return memcpy(d, s, n);

       
	if( d > s ) { 
        	char8* dv;
        	char8* sv;

		s += n - WS;
		d += n - WS;
        	#pragma rpcccga
        	for(; n>=WS; s-=WS, d-=WS, n-=WS){
                	sv = s;
                	dv = d;
                	*dv = *sv;
		}

	        if(n & 4) {
			char4* sv4 = s + WS - 4;
			char4* dv4 = d + WS - 4; 
			*dv4 = *sv4;
                	s-=4; d-=4; n-=4;
        	}
		
	 	if(n & 2) {
			char2* sv2 = s + WS - 2;
			char2* dv2 = d + WS - 2;
			*dv2 = *sv2;
                	s-=2; d-=2; n-=2;
       	 	}

 		if(n & 1) {
			*(d + WS - 1) = *(s + WS - 1);
        	}

	} else { 
        	char8* dv;
        	char8* sv;

        	#pragma rpcccga
        	for(; n>=WS; s+=WS, d+=WS, n-=WS){
                	sv = s;
                	dv = d;
                	*dv = *sv;
        	}

	
	        if(n & 4) {
			char4* sv4 = s;
			char4* dv4 = d;
			*dv4 = *sv4;
                	s+=4; d+=4; n-=4;
        	}

	 	if(n & 2) {
			char2* sv2 = s;
			char2* dv2 = d;
			*dv2 = *sv2;
                	s+=2; d+=2; n-=2;
       	 	}

 		if(n & 1) {
			*d = *s; 
        	}
	}
    
	return dest;
}

int main(){

	char * str = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

	for(int i = 0; i < 100; i++)
 		n_memmove(str + 5, str + 7, 80);

 	/* 
 	n_memmove(str + 7, str + 5, 250);
 	puts(str);
 	n_memmove(str + 5, str + 7, 250);
 	puts(str);
	*/

  	return 0;
}

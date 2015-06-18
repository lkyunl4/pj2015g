#include <string.h>
#include <stdint.h>

#define WS sizeof(float16)
void *musl_memcpy(void * dest, const void * src, size_t n)
{
        char *d = dest;
        const char *s = src;

        float16* dv;
        float16* sv;

        #pragma rpcc cga
        for(; n>=WS; s+=WS, d+=WS, n-=WS){
                sv = s;
                dv = d;
                *dv = *sv;
        }

        if(n & 32) {
                float8* sv32 = s;
                float8* dv32= d;
                *dv32 = *sv32;
                s+=32; d+=32; n-=32;
        }
        if(n & 16) {
                float4* sv16 = s;
                float4* dv16 = d;
                *dv16 = *sv16;
                s+=16; d+=16; n-=16;
        }
        if(n & 8) {
                float2* sv8 = s;
                float2* dv8 = d;
                *dv8 = *sv8;
                s+=8; d+=8; n-=8;
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

        return dest;
}



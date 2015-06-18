#include <string.h>
#include <stdint.h>
#include <srp_vector.h>
#define WS sizeof(uint16)
void *musl_memset(void *dest, int c, size_t n)
{
        uint32_t *d = dest;
        typedef uint32_t __attribute__((__may_alias__)) u32;
        u32 c32 = ((u32)-1)/255 * (unsigned char)c;

        for(; n>= WS; d+= 16, n-=WS){
                uint16* dv = d;
                *dv = (uint16)(c32);
        }

        if(n & 32) {
                uint8 * dv8 = d;
                *dv8 = (uint8)(c32);
                n+=32; d+= 8;
        }

        if(n & 16) {
                uint4 * dv4 = d;
                *dv4 = (uint4)(c32);
                n+=16; d+= 4;
        }

        if(n & 8) {
                uint2 * dv2 = d;
                *dv2 = (uint2)(c32);
                n+=8; d+=2;
        }

        if(n & 4) {
                char4* cv4 = d;
                *cv4 = (char4)(c);
                n+=4; d+=1;
        }


        d = (char*)d;

        if(n & 2) {
                char2* cv2 =d;
                *cv2 = (char2)(c);
                d+=2; d+=2;
        }


        if(n & 1)
                *d = c;

        return dest;

}

#include <stdio.h>

//#include "sha3.h"
#include "sph_keccak.h"

int main()
{

char t[]="AAAA";

unsigned char out[32];

//crypto_hash(out, t, 4);


    sph_keccak256_context ctx_keccak;
    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, t, 4);
    sph_keccak256_close(&ctx_keccak, (void*)out);


int i=0;
for(;i<32;i++)
 printf("%02x",out[i]);
printf("\n");

return 0;

}

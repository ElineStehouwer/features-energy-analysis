#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *bin(uint32_t x);

void main_function(){
    for (size_t i = 0; i < 256; i++) {
        char *binstr = bin(i);
        // printf("%s\n", binstr);
        free(binstr);
    }
}

int main(void)
{
    for (int i = 0; i < 1; i++){//3000000
        main_function();
    }
}

char *bin(uint32_t x)
{
    size_t bits = (x == 0) ? 1 : log10((double) x)/log10((double)2) + 1;
    char *ret = malloc((bits + 1) * sizeof (char));
    for (size_t i = 0; i < bits ; i++) {
       ret[bits - i - 1] = (x & 1) ? '1' : '0';
       x >>= 1;
    }
    ret[bits] = '\0';
    return ret;
}

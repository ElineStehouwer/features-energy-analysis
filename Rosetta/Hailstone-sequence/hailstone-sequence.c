#include <stdio.h>
#include <stdlib.h>

int hailstone(int n, int *arry)
{
    int hs = 1;

    while (n!=1) {
        hs++;
        if (arry) {printf("n=%d\n", n); *arry++ = n;}
        n = (n&1) ? (3*n+1) : (n/2);
    }
    if (arry) {printf("n=%d\n", n); *arry++ = n;}
    return hs;
}

void main_function() {
    int j, hmax = 0;
    int jatmax =0, n = 0;
    // int *arry;

    for (j=1; j<100000; j++) {
       n = hailstone(j, NULL);
       if (hmax < n) {
           hmax = n;
           jatmax = j;
       }
    }
    n = hailstone(27, NULL);
    // int arry[227];
    // // arry = malloc(n*sizeof(int));
    // n = hailstone(27, arry);

    // printf("[ %d, %d, %d, %d, ...., %d, %d, %d, %d] len=%d\n",
    //     arry[0],arry[1],arry[2],arry[3],
    //     arry[n-4], arry[n-3], arry[n-2], arry[n-1], n);
    // printf("Max %d at j= %d\n", hmax, jatmax);
    // free(arry);
}

int main()
{
    for (int i = 0; i < 1; i++){ //1500
        main_function();
    }

    return 0;
}

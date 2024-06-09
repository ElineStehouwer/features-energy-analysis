#include <stdio.h>
#include <malloc.h>
void sieve(int *, int);

void main_function(){
    // int *array, n=10000;
    int n=10001;
    // array =(int *)malloc(n*sizeof(int));
    int array [10001];
    sieve(array,n);
}

int main(int argc, char **argv)
{
    for (int i =0; i < 1; i++) {//3000
        main_function();
    }
    return 0;
}

void sieve(int *a, int n)
{
    int i=0, j=0;

    for(i=2; i<n; i++) {
        a[i] = 1;
    }

    for(i=2; i<n; i++) {
        if(a[i] == 1) {
            for(j=i; (i*j)<n; j++) {
                a[(i*j)] = 0;
            }
        }
    }

    // for(i=2; i<n; i++) {
    //     if(a[i] == 1)
    //         printf("%d ", i);
    // }
    // printf("\n");
}

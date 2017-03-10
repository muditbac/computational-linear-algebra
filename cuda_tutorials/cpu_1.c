#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

struct timeval tp1;
struct timeval tp2;

#define TIMEDIF(tp1, tp2)  ((tp2.tv_sec-tp1.tv_sec)+(tp2.tv_usec-tp1.tv_usec)/1000000.0)
#define TIME(statement) gettimeofday(&tp1, NULL); statement gettimeofday(&tp2,NULL);printf("Time %s: %.6fsec\n", #statement, TIMEDIF(tp1, tp2));
#define N 52000000

void add( int *a, int *b, int *c ){
    int tid = 0; // this is CPU zero, so we start at zero
    while (tid < N){
        c[tid] = a[tid] + b[tid];
        tid += 1; // we have one CPU, so we increment by one
    }
}

int main( void ){
    int *a, *b, *c;
    a = (int *)malloc(N*sizeof(int));
    b = (int *)malloc(N*sizeof(int));
    c = (int *)malloc(N*sizeof(int));
    
    TIME(
    for (int i = 0; i < N; i++){
        a[i] = -i;
        b[i] = i * i;
    }
    )
    
    TIME(add( a, b, c );)

    // display the results
    TIME(
    for (int i = 0; i < N; i++){
        // printf( "%d + %d = %d\n", a[i], b[i], c[i] );
    }
    )

    free( a );
    free( b );
    free( c );

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

timeval tp1;
timeval tp2;

static void HandleError( cudaError_t err,
                         const char *file,
                         int line ) {
    if (err != cudaSuccess) {
        printf( "%s in %s at line %d\n", cudaGetErrorString( err ),
                file, line );
        exit( EXIT_FAILURE );
    }
}

#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))
#define TIMEDIF(tp1, tp2)  ((tp2.tv_sec-tp1.tv_sec)+(tp2.tv_usec-tp1.tv_usec)/1000000.0)
#define TIME(statement) gettimeofday(&tp1, NULL); statement gettimeofday(&tp2,NULL);printf("Time %s: %.6fsec\n", #statement, TIMEDIF(tp1, tp2));
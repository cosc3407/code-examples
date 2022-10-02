#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define M 3
#define K 2
#define N 3

int A [M][K] = { {1,4} , {2,5} , {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];

typedef struct v{// vector structure
    int i; /* row */
    int j; /* col */
}vector;

pthread_t workers[NUM_THREADS];// init thread array

void *dotProduct(void* pointer);// multiplication thread

int main(){
    
    int count = 0;
    /* creating M * N worker threads */
    for(int i = 0; i < M; i++){
        for( int j = 0; j < N; j++){
            //allocate memory and store each vector with data for individual matrix cell
            vector *data = (struct v * ) malloc(sizeof(struct v));
            data->i = i;
            data->j = j;
            /* Now create the thread passing it data as a parameter */

            // creates thread
            pthread_create (&workers[count], NULL, dotProduct,(void *) data );
            count++;
        }
    }
    
    // join threads
    for (int i = 0; i < NUM_THREADS; i++) pthread_join(workers[i], NULL);

    // print matrix
    for(int i = 0; i < M; i++){
        for( int j = 0; j < N; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}

void* dotProduct(void * pointer){// multiplication thread

    vector *data = pointer;// get data and update i and j values
    int i = data->i;
    int j = data->j;
    int num = 0;

    for(int k = 0; k < K; k++){

        num = A[i][k] * B[k][j];// multiply
        C[i][j] += num;// add
    }
    pthread_exit(0);// exit thread
}

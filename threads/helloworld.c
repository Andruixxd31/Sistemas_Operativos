#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUMTHREADS 20

void *printHelloWorld(void *datos){
    printf("Hello world desde el hilo %d\n", *(int *)datos);
    sleep(3);
    printf("otra cosa\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t myThread[NUMTHREADS];
    for(int i = 0; i < NUMTHREADS; ++i){
        int tID;
        pthread_create(&myThread[i],NULL, printHelloWorld,tID);
    }
    pthread_exit(NULL);
    return 0;
}

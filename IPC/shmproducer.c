#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

// typedef int entero;
// entero c;

typedef struct m
{
    char status;
    int data[4];
} MyData;

int main()
{
    MyData * datos;
    // struct m midato;
    int key = 27;
    int shmId = shmget(key, sizeof(MyData), IPC_CREAT | 0666);
    datos = (MyData *)shmat(shmId, NULL, 0);
    datos->status = 'n'; /* Not Ready */
    datos->data[0] = 40;
    datos->data[1] = 30;
    datos->data[2] = 20;
    datos->data[3] = 10;
    datos->status = 'r'; /* Ready */
    
    while (datos->status != 't')
    {
        sleep(1);
    }
    printf("Los datos se consumieron \n");

    return 0;
}

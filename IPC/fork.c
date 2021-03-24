#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int sigVar = 0;

void signalHandler(int sig){
	printf("Recibi señal %d\n", sig);
    int pidH = wait(NULL);
	sigVar = 1;
}

int main(){
    int pid = fork();
    // int pidH;
    if(pid == 0){
        printf("Soy el proceso hijo\n");
    }else{
        signal(17, signalHandler);
        printf("Soy el proceso padre y mi hijo es el proceso %d\n", pid);
        while(1){
            printf("Trabajando\n");
            sleep(1);
        }
        printf("Mi hijo fue asesinado\n");
    }
    printf("Terminando\n");
    return 0;
}
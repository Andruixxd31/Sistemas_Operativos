#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int sigVar = 0;

void signalHandler(int sig){
	printf("Recibi señal %d\n", sig);
	sigVar = 1;
}

int main(){
    int pid = fork();
    int pidH;
    if(pid == 0){
        printf("Soy el proceso hijo\n");
    }else{
        signal(17, signalHandler);
        printf("Soy el proceso padre y mi hijo es el proceso %d\n", pid);
        while(1){
            printf("Trabajando\n");
            if(sigVar == 1){
			    break;
            }
            sleep(1);
        }
        pidH = wait(NULL);
        printf("Mi hijo %d fue asesinado\n", pidH);
    }
    printf("Terminando\n");
    return 0;
}
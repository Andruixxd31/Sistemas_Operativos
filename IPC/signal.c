#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int sigVar = 0;

void signalHandler(int sig){
	printf("Recibi señal %d\n", sig);
	sigVar = 1;
}

int main(){
	signal(2, signalHandler);
	while(1){
		printf("tabajando\n");
		if(sigVar == 1){
			break;
		}
		sleep(1);
	}
	printf("ya voy a terminar\n");
	return 0;
}
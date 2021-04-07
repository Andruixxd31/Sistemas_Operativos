#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();
    if(pid == 0){ 
        //Son
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execl("/usr/bin/tr", "tr", "' '", "-", NULL);
    }else if(pid > 0){ 
        //Father
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execl("/usr/bin/cat", "cat", NULL);
    }
    return 0;
}
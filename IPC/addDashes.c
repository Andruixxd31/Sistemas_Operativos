#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2]; //array of fd to use 0 (output) and 1 (input)
    int pid;
    pipe(fd); //creating the pipe with the io
    pid = fork();
    if(pid == 0){ 
        //Son
        close(fd[1]); // closing input not used of the pipe 
        //dup2 connects the pipe between programs. 
        dup2(fd[0], STDIN_FILENO); //the output of pipe connected with output of tr
        execl("/usr/bin/tr", "tr", "' '", "-", NULL);
    }else if(pid > 0){ 
        //Father
        close(fd[0]); // closing output not used of the pipe 
        dup2(fd[1], STDOUT_FILENO); //the input of pipe connected with output of cat
        execl("/usr/bin/cat", "cat", NULL);
    }
    return 0;
}
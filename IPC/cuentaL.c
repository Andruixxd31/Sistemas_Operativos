#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

//0 stdin
//1 stdout
int main(){
    char minC;
    int entro = 0;
    int total = 0;
    read(0,&minC,1);
    while(read(0,&minC,1)){
        if(minC == '\n')
            ++total;
        entro = 1;
    }
    if(minC != '\n' && entro == 1)
        ++total;
    printf("%d\n", total);
    return 0;
}
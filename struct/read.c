#include <stdio.h>
#include <stdlib.h>
#include "./student.h"


int main(int argc, char **argv){
    char *filename = argv[1];
    int cuantos = atoi(argv[2]);
    FILE *forigen;
    forigen = fopen(filename, "rb");
    
    for(int i = 0; i < cuantos; i++){
        STUDENT newStudent;
        fread(&newStudent, sizeof(STUDENT), 1, forigen);
        printf("%s, %s, %d, %d \n", newStudent.name, newStudent.lastname,
            newStudent.id, newStudent.semestre);
    }
    fclose(forigen);
}      
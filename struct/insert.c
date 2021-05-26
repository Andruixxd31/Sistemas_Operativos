#include <stdio.h>
#include "./student.h"


int main(int argc, char **argv){
    char *filename = argv[1];
    int cuantos;
    printf("Cuantos almunos a insertar: ");
    scanf("%d", &cuantos);
    FILE *fdestino;
    fdestino = fopen(filename, "wb");
    for (int i = 0; i < cuantos; i++)
    {
        STUDENT newStudent;
        printf("nombre: ");
        scanf("%s", newStudent.name);
        printf("apellido: ");
        scanf("%s", newStudent.lastname);
        printf("id: ");
        scanf("%d", &newStudent.id);
        printf("semestre: ");
        scanf("%d", &newStudent.semestre);
        // printf("%s, %s, %d, %d \n", newStudent.name, newStudent.lastname, newStudent.id, newStudent.semestre);
        fwrite(&newStudent, sizeof(newStudent),1, fdestino);
    }
    fclose(fdestino);
}      
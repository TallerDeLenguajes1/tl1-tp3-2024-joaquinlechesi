#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cantidad 5

void cargarNombres(char **lista);
void mostrarNombres(char **lista);

int main()
{
    char **lista; //*buff, lista es parte de la funcion main
    //buff = (char *)malloc(50 * sizeof(char)); //bien
    lista = (char **)malloc(sizeof(char *) * cantidad); //tener en cuenta como se castea un puntero doble //bien
    //char nombres[cantidad], *p_nombres;
    cargarNombres(lista);
    mostrarNombres(lista);
    free(lista);

    return 0;
}

void cargarNombres(char **lista){
    char *buff;
    buff = (char *)malloc(50 * sizeof(char));
    int tamanio;
    for (int i = 0; i < cantidad; i++)
    {
        //puts("Ingrese un nombre:");
        printf("Ingrese el nombre numero %d:\n", i+1);
        fflush(stdin);
        //scanf("%s", buff);
        gets(buff);
        tamanio = strlen(buff); //longitud de la cadena sin "/0"
        //char *cadena;
        //cadena = (char *)malloc(tamanio * sizeof(char)+1);
        //strcpy(cadena, buff);
        //lista = &cadena;
        //printf("\n%p", lista);
        //lista++;
        lista[i] = (char *)malloc(sizeof(char) * tamanio+1);
        strcpy(lista[i], buff);
    }
    free(buff);
}

void mostrarNombres(char ** lista){
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nEl nombre numero %d es %s", i+1, lista[i]);
    }
}
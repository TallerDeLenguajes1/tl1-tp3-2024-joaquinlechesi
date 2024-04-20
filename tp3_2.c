#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fila 5
#define columna 12

void cargarAleatoriamente(int *puntero); //recordar que cuando envio un puntero como argumento no pierdo el puntero original
void mostrarArregloConPuntero(int *puntero);
void mostrarPromedioConArreglo(int *puntero, float *p_promedio_anio);
void maximoMinimoConPuntero(int *puntero);

int main()
{
    int produccion[fila][columna], *p_produccion; //produccion[fila][columna] ¿es un puntero doble?
    p_produccion = produccion[0];
    float promedio_anio[fila], *p_promedio_anio;
    p_promedio_anio = promedio_anio;
    //srand(time(NULL));
    //printf("%p", produccion);
    //Funcion para generar aleatoriamente los numeros
        // for (size_t i = 0; i < fila; i++)
        // {
        //     for (size_t j = 0; j < columna; j++)
        //     {
        //         produccion[i][j] = rand() % 60000 + 10000;
        //         //printf("%d  ", produccion[i][j]);

        //     }
        //     //printf("\n");
        // }
    cargarAleatoriamente(p_produccion);

    //Funcion para mostrar los valores cargados aleatoriamente
        // for (size_t i = 0; i < fila; i++)
        // {
        //     for (size_t j = 0; j < columna; j++)
        //     {
        //         //produccion[i][j] = rand() % 60000 + 10000;
        //         printf("%d  ", produccion[i][j]);

        //     }
        //     printf("\n");
        // }
    mostrarArregloConPuntero(p_produccion);

    //int k = 0;
    //Funcion para mostrar el promedio por cada año
        // for (size_t i = 0; i < fila; i++)
        // {
        //     promedio_anio[i] = 0;
        //     for (size_t j = 0; j < columna; j++)
        //     {
        //         promedio_anio[i] = promedio_anio[i] + produccion[i][j];
        //         if (j == columna-1)
        //         {
        //             promedio_anio[i] = promedio_anio[i]/12;
        //             printf("\nEl promedio del año %.d es: %.2f", i+1, promedio_anio[i]);
        //         }
        //     }
        // }
    mostrarPromedioConArreglo(p_produccion, p_promedio_anio);

    //Funcion para obtener el maximo y el minimo con mes y año
        // float valorMaximo = 0, valorMinimo = 0;
        // int mesMaximo, mesMinimo, anioMaximo, anioMinimo;
        // for (size_t i = 0; i < fila; i++)
        // {
        //     for (size_t j = 0; j < columna; j++)
        //     {
        //         if (valorMaximo == 0)
        //         {
        //             valorMaximo = produccion[i][j];
        //             valorMinimo = produccion[i][j];
        //             mesMaximo = j;
        //             mesMinimo = j;
        //             anioMaximo = i;
        //             anioMinimo = i;
        //         }
        //         else
        //         {
        //             if (produccion[i][j] > valorMaximo)
        //             {
        //                 valorMaximo = produccion[i][j];
        //                 mesMaximo = j;
        //                 anioMaximo = i;
        //             }
        //             if (produccion[i][j] < valorMinimo)
        //             {
        //                 valorMinimo = produccion[i][j];
        //                 mesMinimo = j;
        //                 anioMinimo = i;
        //             }
        //         }
        //     }
        // }
        // printf("\nEl valor máximo se fue %.2f en el año n° %d en el mes n° %d", valorMaximo, anioMaximo+1, mesMaximo+1);
        // printf("\nEl valor minimo se fue %.2f en el año n° %d en el mes n° %d", valorMinimo, anioMinimo+1, mesMinimo+1);
        maximoMinimoConPuntero(p_produccion);

    return 0;
}

void cargarAleatoriamente(int *puntero){
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            *(puntero) = (rand() % 60000) + 10000;
            puntero++; //con esto nos movemos en todas las direcciones consecutivas independientemente de las dimensiones del arreglo
        }
    }
}

void mostrarArregloConPuntero(int *puntero){
    for (size_t i = 0; i < fila; i++)
    {
        for (size_t j = 0; j < columna; j++)
        {
            //produccion[i][j] = rand() % 60000 + 10000;
            printf("%d  ", *(puntero));
            puntero++;
        }
        printf("\n");
    }    
}

void mostrarPromedioConArreglo(int *puntero, float *p_promedio_anio){
    for (size_t i = 0; i < fila; i++)
    {
        *(p_promedio_anio) = 0;
        for (size_t j = 0; j < columna; j++)
        {
            *(p_promedio_anio) = *(p_promedio_anio) + *(puntero);
            if (j == columna-1)
            {
                *(p_promedio_anio) = *(p_promedio_anio)/12;
                printf("\nEl promedio del año %d es: %.2f", i+1, *(p_promedio_anio));
            }
            puntero++;
        }
        p_promedio_anio++;
    }
}

void maximoMinimoConPuntero(int *puntero){
    int valorMaximo = 0, valorMinimo = 0;
    int mesMaximo, mesMinimo, anioMaximo, anioMinimo;
    for (size_t i = 0; i < fila; i++)
    {
        for (size_t j = 0; j < columna; j++)
        {
            if (valorMaximo == 0)
            {
                valorMinimo = *(puntero);
                valorMaximo = *(puntero);
                mesMaximo = j;
                mesMinimo = j;
                anioMaximo = i;
                anioMinimo = i;
            }
            else
            {
                if (*(puntero) > valorMaximo)
                {
                    valorMaximo = *(puntero);
                    mesMaximo = j;
                    anioMaximo = i;
                }
                if (*(puntero) < valorMinimo)
                {
                    valorMinimo = *(puntero);
                    mesMinimo = j;
                    anioMinimo = i;
                }
            }
            puntero++;
        }
    }
    printf("\nEl valor máximo se fue %d en el año n° %d en el mes n° %d", valorMaximo, anioMaximo+1, mesMaximo+1);
    printf("\nEl valor minimo se fue %d en el año n° %d en el mes n° %d", valorMinimo, anioMinimo+1, mesMinimo+1);
}
#include <stdio.h>
#include <stdlib.h>
#define fila 5
#define columna 12

int main()
{
    int produccion[fila][columna];
    float promedio_anio[fila];
    for (size_t i = 0; i < fila; i++)
    {
        for (size_t j = 0; j < columna; j++)
        {
            produccion[i][j] = rand() % 60000 + 10000;
            //printf("%d  ", produccion[i][j]);

        }
        //printf("\n");
    }
    for (size_t i = 0; i < fila; i++)
    {
        for (size_t j = 0; j < columna; j++)
        {
            //produccion[i][j] = rand() % 60000 + 10000;
            printf("%d  ", produccion[i][j]);

        }
        printf("\n");
    }
    //int k = 0;
    for (size_t i = 0; i < fila; i++)
    {
        promedio_anio[i] = 0;
        for (size_t j = 0; j < columna; j++)
        {
            promedio_anio[i] = promedio_anio[i] + produccion[i][j];
            if (j == columna-1)
            {
                promedio_anio[i] = promedio_anio[i]/12;
            }
            
        }
        //k++;
        float maximo = 0, minimo;
        int mes, anio;
        for (size_t i = 0; i < fila; i++)
        {
            for (size_t j = 0; j < columna; j++)
            {
                // if ()
                // {
                    
                // }
                
            }
            
        }
        
    }
    
    
    
    return 0;
}

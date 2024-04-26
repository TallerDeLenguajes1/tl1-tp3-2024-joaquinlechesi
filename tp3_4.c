#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrilos","Caramelos","Bebidas"};
typedef struct
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}Producto;
typedef struct
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}Cliente;

void cargarClientes(Cliente *p_ListaClientes, int cantidad);
//void totalDeProducto(Producto *p_producto, int cantidad);
void totalDeProducto(Producto *p_producto);
void mostrarClientes(Cliente *p_ListaClientes, int cantidad);

int main()
{
    int CantidadClientes;
    printf("Ingrese la cantidad total de clientes:\n");
    scanf("%d", &CantidadClientes);
    Cliente *ListaClientes;
    ListaClientes = (Cliente *)malloc(CantidadClientes * sizeof(Cliente));
    srand(time(NULL));
    // ListaClientes = (Cliente *)malloc(CantidadClientes * sizeof(Cliente));
    // int tamanio;
    // for (int i = 0; i < CantidadClientes; i++)
    // {
    //     fflush(stdin);
    //     printf("Cliente n° %d\n", i+1);
    //     ListaClientes[i].ClienteID = i+1; //asigno el ID al cliente
    //     printf("Ingrese el nombre del cliente:\n");
    //     char *buff;
    //     buff = (char *)malloc(100 * sizeof(char));
    //     gets(buff);
    //     tamanio = strlen(buff);
    //     ListaClientes[i].NombreCliente = (char *)malloc(tamanio+1 * sizeof(char));
    //     strcpy(ListaClientes[i].NombreCliente,buff); //asigno el nombre al cliente
    //     ListaClientes[i].CantidadProductosAPedir = rand() % 5 + 1; //genero la cantidad de productos
    //     ListaClientes[i].Productos = (Producto *)malloc(ListaClientes[i].CantidadProductosAPedir * sizeof(Producto));
    //     for (int j = 0; j < ListaClientes[i].CantidadProductosAPedir; j++)
    //     {
    //         ListaClientes[i].Productos[j].ProductoID = j+1; //asigno un ID al producto
    //         ListaClientes[i].Productos[j].Cantidad = rand() % 10 + 1; //genero la cantidad de productos
    //         //ListaClientes[i].Productos[j]
    //         int productoAleatorio = rand() % 5; //genero la cantidad de productos
    //         ListaClientes[i].Productos[j].TipoProducto = (char *)malloc(strlen(TiposProductos[productoAleatorio]+1 * sizeof(char)));
    //         strcpy(ListaClientes[i].Productos[j].TipoProducto,TiposProductos[productoAleatorio]);
    //         ListaClientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
    //     }
    // }
    cargarClientes(ListaClientes, CantidadClientes);

    // puts("Para consultar el costo total de un producto ingrese una opcion:");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d para %s\n", i+1, TiposProductos[i]);
    // }
    // int opcion;
    // scanf("%d", &opcion);
    // for (int i = 0; i < CantidadClientes; i++)
    // {
    //     for (int j = 0; j < ListaClientes[i].CantidadProductosAPedir; j++)
    //     {
    //         if (ListaClientes[i].CantidadProductosAPedir)
    //         {
    //             /* code */
    //         }
    //         /* code */
    //     }
        
        
    //     int resultado;
    // }
    
    mostrarClientes(ListaClientes, CantidadClientes);
        
    return 0;
}

void cargarClientes(Cliente *p_ListaClientes, int cantidad){
    puts("\tFUNCION CARGAR CLIENTES");
    //p_ListaClientes = (Cliente *)malloc(cantidad * sizeof(Cliente));
    int tamanio;
    for (int i = 0; i < cantidad; i++)
    {
        fflush(stdin);
        printf("Cliente n° %d\n", i+1);
        p_ListaClientes[i].ClienteID = i+1; //asigno el ID al cliente
        printf("Ingrese el nombre del cliente:\n");
        char *buff;
        buff = (char *)malloc(100 * sizeof(char));
        gets(buff);
        tamanio = strlen(buff);
        p_ListaClientes[i].NombreCliente = (char *)malloc(tamanio+1 * sizeof(char));
        strcpy(p_ListaClientes[i].NombreCliente,buff); //asigno el nombre al cliente
        p_ListaClientes[i].CantidadProductosAPedir = rand() % 5 + 1; //genero la cantidad de productos
        p_ListaClientes[i].Productos = (Producto *)malloc(p_ListaClientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < p_ListaClientes[i].CantidadProductosAPedir; j++)
        {
            p_ListaClientes[i].Productos[j].ProductoID = j+1; //asigno un ID al producto
            p_ListaClientes[i].Productos[j].Cantidad = rand() % 10 + 1; //genero la cantidad de productos
            //ListaClientes[i].Productos[j]
            int productoAleatorio = rand() % 5; //genero la cantidad de productos
            p_ListaClientes[i].Productos[j].TipoProducto = (char *)malloc(strlen(TiposProductos[productoAleatorio]+1 * sizeof(char)));
            strcpy(p_ListaClientes[i].Productos[j].TipoProducto,TiposProductos[productoAleatorio]);
            p_ListaClientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
    }
    printf("\n");
    
}

//void totalDeProducto(Producto *p_producto, int cantidad){
void totalDeProducto(Producto *p_producto){
    //float resultado = precio->PrecioUnitario * cantidad;
    float resultado = p_producto->PrecioUnitario * p_producto->Cantidad;
    printf("Precio por el total de productos: %.2f\n", resultado);
}

void mostrarClientes(Cliente *p_ListaClientes, int cantidad){
    puts("\tFUNCION MOSTRAR CLIENTES");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Cliente n° %d\nNombre: %s\n", p_ListaClientes->ClienteID, p_ListaClientes->NombreCliente);
        printf("Cantidad de productos del cliente: %d\n", p_ListaClientes->CantidadProductosAPedir);
        for (int j = 0; j < p_ListaClientes->CantidadProductosAPedir; j++)
        {
            printf("ID del Producto: %d\n", p_ListaClientes->Productos->ProductoID); // recordar: estructura hacia otra estructura mediante puntero es con operador flecha
            printf("Nombre del producto:\n%s\n", p_ListaClientes->Productos->TipoProducto);
            printf("Cantidad del producto: %d\n", p_ListaClientes->Productos->Cantidad);
            printf("Precio unitario del producto: %.2f\n", p_ListaClientes->Productos->PrecioUnitario);
            totalDeProducto(p_ListaClientes->Productos);
            p_ListaClientes->Productos++;
        }
        p_ListaClientes++;
        printf("\n\t--.--\n");
    }
    printf("\n");
}
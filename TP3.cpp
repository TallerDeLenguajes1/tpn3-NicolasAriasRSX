#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define TAM 120
char *TiposProductos[]= {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto
{
    int ProductiID;         // ciclo
    int Cantidad;           // 1 - 10
    float PrecioUnitario;   // 10 - 100
    char * TipoProducto;    // De TiposProductos
}Producto;
typedef struct Cliente
{
    int ClienteID;                  //ciclo
    char * NombreCliente;           //ingresado por usuario
    int CantidadProductosAPedir;    // 1- 5
    Producto * Productos;            // dep de la cant de CantidadProductosAPedir
}Cliente;
//******declaracion de Funciones********

void CargarClientes(int CantClientes, Cliente ** Client);
void CostoTotal(Cliente ** Client, int clientes);

int main()
{   
    srand(time(NULL));
    int cantclie;
    Cliente * LIstClient;

    printf("ingrese la cantidad de clientes \n");
    scanf("%d",&cantclie);
    //scanf(" %d");
    LIstClient= (Cliente *)malloc(sizeof(Cliente)* cantclie);
    CargarClientes(cantclie, &LIstClient);
    CostoTotal(&LIstClient, cantclie);

    scanf(" %d");

    
    return 0;
}


void CargarClientes(int CantClientes, Cliente ** Client)
{
  char nombre[TAM];
  for( int i =0; i< CantClientes; i++)
  {
      (*Client + i)->ClienteID= i+ 1;
      printf("Ingrese el nombre del cliente ");
      scanf("%s", nombre);
      (*Client + i)->NombreCliente=(char *) malloc(sizeof(char)* strlen(nombre));
      strcpy((*Client + i)->NombreCliente, nombre);
      //fflush(stdin);
      (*Client + i)->CantidadProductosAPedir= rand() % 5+ 1;
      printf("El cliente pidio %d producros\n",(*Client + i)->CantidadProductosAPedir);
      (*Client + i)->Productos=(Producto *) malloc(sizeof(Producto)*(*Client + i)->CantidadProductosAPedir);
      for( int j= 0; j <(*Client + i)->CantidadProductosAPedir; j++)
      {
          (((* Client + i)->Productos) + j)->ProductiID = j+ 1;
          (((* Client + i)->Productos) + j)->Cantidad=  rand() % 10+ 1;
          (((* Client + i)->Productos) + j)->PrecioUnitario= 10 + rand() % (101 - 10);
          (((* Client + i)->Productos) + j)->TipoProducto= (char *) malloc(sizeof(char)*(strlen(*(TiposProductos + rand() % 5))));
          strcpy((((*Client + i)->Productos) + j)->TipoProducto,*(TiposProductos + rand() % 5 + 1));
          printf("ID Producto: %d\n",(((*Client + i)->Productos) + j)->ProductiID);
          printf("Pidio la cantidad de: %d\n", (((*Client + i)->Productos) +j)->Cantidad);
          printf("Precio por unidad: %.2f\n",((*Client + i)->Productos +j)->PrecioUnitario);
          printf("Tipo de producto: "); puts(((*Client + i)->Productos + j)->TipoProducto);printf("\n");
      }  
  }
    
}

void CostoTotal(Cliente ** Client, int clientes)
{
    float CostTotal= 0;
    for(int i= 0; i< clientes; i++)
    {
        printf("A pagar por cliente\n");
        printf("ID: %d\n", (*Client + i)->ClienteID);
        printf("Nombre: ");puts((* Client)->NombreCliente);printf("\n");
        for( int j= 0; j< (* Client)->CantidadProductosAPedir; j++)
        {
            CostTotal= CostTotal + ((*Client + i)->Productos + j)->Cantidad * ((*Client + i)->Productos + j)->PrecioUnitario;
        }
        printf("Costo a pagar: %.2f\n", CostTotal);
    }
}
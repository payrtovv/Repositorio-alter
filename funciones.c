#include<string.h>
#include<stdio.h>

#include "lecturas.h"
#include "funciones.h"

int CantidadLibros[MAXLETRAS];
char NombresLibros[MAXLIBROS][MAXLETRAS];
float PrecioLibros[MAXLETRAS];

char NombresClientes[MAXLIBROS][MAXLETRAS];
int cedulasClientes[MAXLIBROS];
int fechas[MAXLIBROS][2];
float ValoresPagados[MAXLIBROS];
int cantidadDeProductosComprados[MAXLIBROS];
char NombreCompras[MAXLIBROS][MAXLETRAS];




void IngresarNuevolibro(char NombresLibros[MAXLIBROS][MAXLETRAS], int CantidadLibros[MAXLIBROS], float PrecioLibros[MAXLETRAS], int* LibrosIngresados){
    if (*LibrosIngresados >= MAXLIBROS) {
        printf("No hay almacenamiento suficiente.\n");
        printf("<-------------------------->\n");
        return;
    }   
    printf("Ingrese el nombre del libro a registrar: ");
    fgets(NombresLibros[*LibrosIngresados], MAXLETRAS, stdin);
    for (int i = 0; i < *LibrosIngresados; i++)
    {
        if ((strcmp(NombresLibros[*LibrosIngresados],NombresLibros[i]))==0)
        {
            printf("Libro ya existente.\n");
            printf("<-------------------------->\n");
            return;
        }
    }
    CantidadLibros[*LibrosIngresados] = leerEnteroPositivo("Ingrese la cantidad de libros: ");
    PrecioLibros[*LibrosIngresados] = leerFlotantePositivo("Ingrese el precio del libro: ");
    printf("Producto agregado con exito.\n");
    printf("<-------------------------->\n");
    (*LibrosIngresados)++;
}

void limpiarBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void buscarLibro(char NombresLibros[MAXLIBROS][MAXLETRAS], char buscar[MAXLETRAS], int CantidadLibros[MAXLETRAS], float PrecioLibros[MAXLETRAS], int LibrosIngresados ){
    printf("Ingrese el libro a buscar: ");
    fgets(buscar,MAXLETRAS, stdin);
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            printf("Precio:   %.2f\n", PrecioLibros[i]);
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado\n");
    printf("<-------------------------->\n");
}

void EliminarLibro(char NombresLibros[MAXLIBROS][MAXLETRAS], char buscar[MAXLETRAS], int CantidadLibros[MAXLIBROS], float PrecioLibros[MAXLIBROS], int LibrosIngresados){
    printf("Ingrese el libro a ser eliminado: ");
    fgets(buscar,MAXLETRAS, stdin);
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado y eliminado exitosamente. \n");
            for (int j = 0; j < MAXLETRAS; j++) {
            NombresLibros[i][j] = 0; 
            }
            CantidadLibros[i]=0;
            PrecioLibros[i]=0;
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<-------------------------->\n");
}

void EditarLibro(char NombresLibros[MAXLIBROS][MAXLETRAS], char buscar[MAXLETRAS], int CantidadLibros[MAXLETRAS], float PrecioLibros[MAXLETRAS], int LibrosIngresados ){
    printf("Ingrese el libro a editar: ");
    fgets(buscar,MAXLETRAS, stdin);
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            printf("Precio:   %.2f\n", PrecioLibros[i]);
            CantidadLibros[i] = leerEnteroPositivo("\nIngrese la nueva cantidad de libros: ");
            PrecioLibros[i] = leerFlotantePositivo("Ingrese el nuevo precio de el libro: ");
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<---------------------------->\n");
}

void aumentarStock(char NombresLibros[MAXLIBROS][MAXLETRAS], char buscar[MAXLETRAS], int CantidadLibros[MAXLIBROS], int LibrosIngresados){
    int valor;
    printf("Ingrese el nombre libro al que se quiere aumentar el stock: ");
    fgets(buscar,MAXLETRAS, stdin);
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            valor = leerEnteroPositivo("\nIngrese cuanto se va a aumentar: ");
            CantidadLibros[i] = CantidadLibros[i] + valor;
            printf("Agregado correctamente\n");
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<---------------------------->\n");
}

void facturar(int* ClientesIngresados, int buscarcedula[], int CedulaCompras[], int* NumeroDeCompras, char NombreCompras[MAXLIBROS][MAXLETRAS], int buscar[], int LibrosIngresados){
    buscarcedula = leerEntero("Ingresar la cedula del cliente: ");
    //Validacion de cedula
    for (int i = 0; i < ClientesIngresados; i++)
    {
        if ((strcmp(buscarcedula,cedulasClientes[i]))==0)
        {
            printf("Encontrado\n");
            IngresarFecha(fechas[100][3], NumeroDeCompras);
            CedulaCompras[*NumeroDeCompras] = cedulasClientes[i];
            //NombreCompras[*NumeroDeCompras] = NombresClientes[i];
            fac(buscar, NombresLibros, LibrosIngresados, NumeroDeCompras);
            (*NumeroDeCompras)++;
            return;
        }

    }
    printf("Cliente no encontrado");
    //funcion ingresar cliente
    IngresarFecha(fechas[100][3], NumeroDeCompras);
    CedulaCompras[*NumeroDeCompras] = buscarcedula;
    //NombreCompras[*NumeroDeCompras] = NombresClientes[i];
    fac(buscar, NombresLibros, LibrosIngresados, NumeroDeCompras);
    (*NumeroDeCompras)++;
}

void fac(int buscar[], char NombresLibros[MAXLIBROS][MAXLETRAS], int LibrosIngresados, int NumeroDeCompras){
    int respuesta = 1;
    float valor = 0;
    float valorTotal =0;
    while(respuesta == 1){
        printf("Ingrese el nombre del libro a vender: ");
        for (int i = 0; i < LibrosIngresados; i++)
        {
            if ((strcmp(buscar,NombresLibros[i]))==0)
            {
                int cantidad=0;
                printf("Encontrado\n");
                printf("Ingrese la cantidad de libros a vender");
                scanf("%i", cantidad);
                valor = cantidad * PrecioLibros[i];
                cantidadDeProductosComprados[NumeroDeCompras] += cantidad;
                CantidadLibros[i] = CantidadLibros[i] - cantidad;
            }else
                printf("Libro no encontrado");
            valorTotal = valor + valorTotal;
        }
        printf("Desea seguir comprando? 1=si/2=no");
        scanf("%i", &respuesta);
    }
    printf("Cantidad a pagar: %f", valorTotal);
    ValoresPagados[NumeroDeCompras]=valorTotal;
}

void buscarFarctura(int buscarcedula[], int NumeroDeCompras, int CedulaCompras[]){
    printf("Ingrese el numero de cedula del cliente");
    buscarcedula = leerEntero("Ingresar la cedula del cliente: ");
    for (int i = 0; i < NumeroDeCompras; i++)
    {
        if ((strcmp(buscarcedula,CedulaCompras[i]))==0)
        {
            printf("Encontrado\n");
            printf("fecha: ");
            printf("cedula: ");
            printf("%i", CedulaCompras[i]);
            printf("Nombre: ");
            printf("%s", NombreCompras[i]);
            printf("Valor pagado: ");
            printf("%f", ValoresPagados[i]);
            printf("cantidad de productos: ");
            printf("%i", cantidadDeProductosComprados[i]);
        }

    }
}

void ListadoFacturas(int NumeroDeCompras, int CedulaCompras[]){
    for (int i = 0; i < NumeroDeCompras; i++)
    {
            printf("fecha: ");
            printf("cedula: ");
            printf("%i", CedulaCompras[i]);
            printf("Nombre: ");
            printf("%s", NombreCompras[i]);
            printf("Valor pagado: ");
            printf("%f", ValoresPagados[i]);
            printf("cantidad de productos: ");
            printf("%i", cantidadDeProductosComprados[i]);
            printf("---------------------");
    }
    
}

void IngresarFecha(int fecha[100][3], int NumeroDeCompras){
    printf("Ingrese el dia: ");
    fecha[NumeroDeCompras][0]=leerEnteroEntre("Ingrese el dia: ", 1, 31);
    scanf("%i", fecha[NumeroDeCompras][0]);
    printf("Ingrese el mes: ");
    scanf("%i", fecha[NumeroDeCompras][1]);
    printf("Ingrese el año: ");
    scanf("%i", fecha[NumeroDeCompras][2]);
}
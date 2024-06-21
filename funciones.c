#include<string.h>
#include<stdio.h>

#include "lecturas.h"
#include "funciones.h"



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
    *LibrosIngresados =+1;
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
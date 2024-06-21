#include"funciones.h"
#include<stdio.h>
#include "lecturas.h"

int main(){
    char NombresLibros[MAXLIBROS][MAXLETRAS], buscar[MAXLETRAS];
    int LibrosIngresados=0, respuesta=0, CantidadLibros[MAXLIBROS];
    float PrecioLibros[MAXLIBROS];
    while (respuesta <= 4)
    {   
        printf("/// Inventario Biblioteca del saber \\\\\\ \n");
        printf("Opciones de Inventario: \n");
        printf("1.- Ingresar un libro. \n");
        printf("2.- Buscar un libro. \n");
        printf("3.- Editar un libro. \n");
        printf("4.- Eliminar un libro. \n");
        printf("5.- Salir del programa. \n");
        respuesta = leerEnteroEntre("Ingrese la opcion a elegir: ",1,5);
        limpiarBufferEntrada(); 
        switch (respuesta)
        {
        case 1:
            IngresarNuevolibro(NombresLibros, CantidadLibros, PrecioLibros, &LibrosIngresados);
            break;
        case 2:
            buscarLibro(NombresLibros, buscar, CantidadLibros, PrecioLibros, LibrosIngresados);
            break;
        case 3:
            EditarLibro(NombresLibros, buscar, CantidadLibros, PrecioLibros, LibrosIngresados);
            break;
        case 4:
            EliminarLibro(NombresLibros, buscar, CantidadLibros, PrecioLibros, LibrosIngresados);
            break;
        default:
        printf("Saliendo...");
            break;
        }
    }       
}
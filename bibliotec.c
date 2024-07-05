#include"funciones.h"
#include<stdio.h>
#include "lecturas.h"

int main(){
    char NombresLibros[MAXLIBROS][MAXLETRAS], buscar[MAXLETRAS], NombresClientes[MAXLIBROS][MAXLETRAS];
    int LibrosIngresados=0, respuesta=0, CantidadLibros[MAXLIBROS], fechas[MAXLIBROS], CantidadProductos[MAXLIBROS], Cedulas[MAXLIBROS], ClientesIngresados=0, buscarcedula[9];
    float PrecioLibros[MAXLIBROS], ValoresPagados[MAXLIBROS];
    
    while (respuesta <= 5)
    {   
        printf("/// Inventario Biblioteca del saber \\\\\\ \n");
        printf("Opciones de Inventario: \n");
        printf("1.- Ingresar un libro. \n");
        printf("2.- Buscar un libro. \n");
        printf("3.- Editar un libro. \n");
        printf("4.- Eliminar un libro. \n");
        printf("5.- Agregar stock. \n");
        printf("6.- Salir del programa. \n");
        respuesta = leerEnteroEntre("Ingrese la opcion a elegir: ",1,6);
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
        case 5:
            aumentarStock(NombresLibros, buscar, CantidadLibros, LibrosIngresados);
            break;
        default:
        printf("Saliendo...");
            break;
        }
    }       
}
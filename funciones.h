#define MAXLIBROS 100
#define MAXLETRAS 30

void IngresarNuevolibro(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], float [MAXLETRAS] ,int*);
void buscarLibro(char[MAXLIBROS][MAXLETRAS], char[MAXLETRAS], int[MAXLIBROS], float[MAXLIBROS], int);
void EliminarLibro(char[MAXLIBROS][MAXLETRAS], char[MAXLETRAS], int[MAXLIBROS], float[MAXLIBROS], int);
void EditarLibro(char[MAXLIBROS][MAXLETRAS], char[MAXLETRAS], int[MAXLIBROS], float[MAXLIBROS], int);
void aumentarStock(char[MAXLIBROS][MAXLETRAS], char[MAXLETRAS], int[MAXLIBROS], int);

void limpiarBufferEntrada();

void facturar(int*, int [], int[],int*, char [][], int[], int);

void fac(int [], char [][], int, int );

void buscarFarctura(int );

void IngresarFecha(int [][], int);
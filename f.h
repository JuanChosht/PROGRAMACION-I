#define MaxInventario 1000 //Numero maximo de productos a guardar

typedef struct {
    char marca[100];
    char modelo[100];
    char tipo[100];
    int year;
    float precio;
} producto;

extern producto productos[MaxInventario];
extern int CantProductos; //bucle que suma 1 para guardar [i] cada vez que se ingresa un producto

int opcionmenu(void);
void procesar(int opcion);
void ingresar(void);
void buscar(int cantidadproductos);
void editar(int cantidadproductos);
void procesarbuscar(int opcion);
void mostrar(int cantidadproductos);
void marca(void);
void modelo(void);
void year(void);
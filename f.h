#define MaxInventario 1000 //Numero maximo de productos a guardar

typedef struct {
    char nombre[100];
    int cantidad;
    float precio;
} producto;

extern producto productos[MaxInventario];
extern int CantProductos; //bucle que suma 1 para guardar [i] cada vez que se ingresa un producto

int opcionmenu(void);
void procesar(int opcion);
void ingresar(void);
void mostrar(int cantidadproductos);
void editar(int cantidadproductos);
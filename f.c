#include <stdio.h>
#include "f.h"

producto productos[MaxInventario];
int CantProductos = 0; //bucle que suma 1 para guardar [i] cada vez que se ingresa un producto

int opcionmenu(void){
    int opcion;
    printf("Seleccione una opcion:\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Mostrar producto\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    scanf("%i", &opcion);
    return opcion;
}
void procesar(int opcion){
 switch (opcion) {
        case 1:     
            ingresar();
            break;
        case 2:
            editar(CantProductos);
            break;
        case 3:
            //eliminar producto
            break;
        case 4:
            mostrar(CantProductos);
            break;
        case 0:
            break;
        default:
            printf("Opción inválida.\n");
            break;
    } 
}
void ingresar(void){
    if(CantProductos < MaxInventario){
        printf("Ingrese el nombre del producto: ");
        scanf("%s", productos[CantProductos].nombre); 
        printf("Ingrese la cantidad del producto: ");
        scanf("%i", &productos[CantProductos].cantidad); 
        printf("Ingrese el precio del producto: $");
        scanf("%f", &productos[CantProductos].precio);
        CantProductos++;
    }
}

void editar(int cantidadproductos){
    if(cantidadproductos > 0){
        for (int i = 0; i < cantidadproductos; i++){
            printf("--Producto %i--\n", i + 1);
            printf("Nombre: %s\n", productos[i].nombre);
            continue;
        }
        int index;
        printf("Numero de producto a editar: ");
        scanf("%i", &index);
        index--;

        printf("Ingrese los nuevos datos\n");
        printf("Nombre: ");
        scanf("%s", productos[index].nombre); 
        printf("Cantidad: ");
        scanf("%i", &productos[index].cantidad); 
        printf("Precio: $");
        scanf("%f", &productos[index].precio);
    }
    else{
        printf("No existen productos para editar.\n");
    }

}

void mostrar(int cantidadproductos){
    if(cantidadproductos > 0){
        for(int i = 0; i < cantidadproductos; i++){
            printf("--Producto %i--\n", i+1);
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Cantidad: %i\n", productos[i].cantidad);
            printf("Precio: $%.2f\n", productos[i].precio);
        }
    }
    else{
        printf("No existen productos para mostrar.\n");
    }

}
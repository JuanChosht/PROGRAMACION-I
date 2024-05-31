#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f.h"

producto productos[MaxInventario];
int CantProductos = 0; //bucle que suma 1 para guardar [i] cada vez que se ingresa un producto

int opcionmenu(void){
    int opcion;
    printf("Seleccione una opcion:\n");
    printf("1. Ingresar auto\n");
    printf("2. Editar auto\n");
    printf("3. Buscar autos\n");
    printf("4. Mostrar autos\n");
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
            buscar(CantProductos);
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
        printf("Ingrese la marca del auto: ");
        scanf("%s", productos[CantProductos].marca); 
        printf("Ingrese el modelo del auto: ");
        scanf("%s", productos[CantProductos].modelo);
        printf("Ingrese el tipo de auto: ");
        scanf("%s", productos[CantProductos].tipo); 
        printf("Ingrese el año: ");
        scanf("%i", &productos[CantProductos].year);
        printf("Ingrese el precio: $");
        scanf("%f", &productos[CantProductos].precio);
        CantProductos++;
    }
}
void editar(int cantidadproductos){
    if(cantidadproductos > 0){
        mostrar(cantidadproductos);
        int index;
        printf("Numero de auto a editar: ");
        scanf("%i", &index);
        index--;

        printf("Ingrese los nuevos datos\n");
        printf("Marca del auto:: ");
        scanf("%s", productos[index].marca);
        printf("Modelo del auto: ");
        scanf("%s", productos[index].modelo);
        printf("Modelo del auto: ");
        scanf("%s", productos[index].tipo); 
        printf("Año: ");
        scanf("%i", &productos[index].year); 
        printf("Precio: $");
        scanf("%f", &productos[index].precio);
    }
    else{
        printf("No existen autos para editar.\n");
    }

}

void buscar(int cantidadproductos){

    if(cantidadproductos > 0){
        int opcionb;
        printf("1. Tipo\n");
        printf("2. Modelo\n");
        printf("3. Año\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &opcionb);
        procesarbuscar(opcionb);

        char input[100];
        printf("Seleccione una opcion: ");
        scanf("%s", input);


        int numero = 1;
        for(int i = 0; input[i] != '\0'; i++){
            if(input[i] < '0' || input[i] > '9'){
                numero = 0;
                break;
            }
        }
        if(numero){
            int num = atoi(input);
            for (int i = 0; i < CantProductos; i++) {
                if (num == productos[i].year) {
                    printf("Auto %i", i+1);
                    printf("Tipo: %s\n", productos[i].tipo);
                    printf("Modelo: %s\n", productos[i].modelo);
                    printf("Año: %d\n", productos[i].year);
                }
            }
        }
        else{
            for(int i = 0; i < CantProductos; i++){
                if(strcmp(input, productos[i].tipo) == 0 || strcmp(input, productos[i].modelo) == 0){
                    printf("Auto %i\n", i+1);
                    printf("Tipo: %s\n", productos[i].tipo);
                    printf("Modelo: %s\n", productos[i].modelo);
                    printf("Año: %d\n", productos[i].year);
                }
            }
        }
    
    }
    
}


void procesarbuscar(int opcion){
        switch (opcion)
        {
        case 1: 
            marca();
            break;
        case 2:
            modelo();
            break;
        case 3:
            year();
            break;
        default:
            printf("Opción inválida.\n");
            break;
    }
}

void marca(void){
    for(int i = 0; i < CantProductos; i++){
        int j;
        for(j = i + 1; j < CantProductos; j++){
            if(strcmp(productos[i].tipo, productos[j].tipo) == 0){
                break;
            }
        }
        if(j == CantProductos){
            printf("Tipo: %s\n", productos[i].tipo);
        }
    }
} 

void modelo(void){
    for(int i = 0; i < CantProductos; i++){
        int j;
        for(j = i + 1; j < CantProductos; j++){
            if(strcmp(productos[i].modelo, productos[j].modelo) == 0){
                break;
            }
        }
        if(j == CantProductos){
            printf("Modelo: %s\n", productos[i].modelo);
        }
    }
}

void year(void){
    for(int i = 0; i < CantProductos; i++){
        int j;
        for(j = i + 1; j < CantProductos; j++){
            if(productos[i].year == productos[j].year){
                break;
            }
        }
        if(j == CantProductos){
            printf("Año: %i\n", productos[i].year);
        }
    }
}

void mostrar(int cantidadproductos){
    if(cantidadproductos > 0){
        for(int i = 0; i < cantidadproductos; i++){
            printf("--Auto %i--\n", i+1);
            printf("Marca: %s\n", productos[i].marca);
            printf("Modelo: %s\n", productos[i].modelo);
            printf("Tipo: %s\n", productos[i].tipo);
            printf("Año: %i\n", productos[i].year);
            printf("Precio: $%.2f\n", productos[i].precio);
        }
    }
    else{
        printf("No existen productos para mostrar.\n");
    }
}



    


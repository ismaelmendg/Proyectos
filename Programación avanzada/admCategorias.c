/**********************************
 * ASIGNADO A : Luis Martínez
 * *********************************/
#include <stdio.h>
#include <unistd.h>
#include "biblioteca.h"

int menuCategorias(void);
void admCategoria(void);
void agregarCategoria(void);
void eliminarCategoria(void);
void modificarCategoria(void);
void listarCategorias(void);
void buscarCategoria(void);

void admCategorias(void){

    while(1){
        switch(menuCategorias()){
			case 1:
					agregarCategoria();
					break;
			case 2:
					eliminarCategoria();
					break;
			case 3:
					modificarCategoria();
					break;
			case 4:
					listarCategorias();
					break;
			case 5: 
                    buscarCategoria();
                    break;	
            case 6: 
					return;		
		}
    }

}

int menuCategorias(void){
int opc;

    do{
        puts("OPCIONES DE MANTENIMIENTO CATEGORÍAS\n");
		puts("1) Submenú  AGREGAR CATEGORÍA.");
		puts("2) Submenú  ELIMINAR CATEGORÍA");
		puts("3) Submenú  MODIFICAR CATEGORÍA");
		puts("4) Submenú  LISTAR CATEGORÍAS");
        puts("5) Submenú BUSCAR CATEGORÍA");
		puts("6) Regresar al menú ADMINISTRACIÓN");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 6);

    return opc;
}

void agregarCategoria(void){

    puts("Estás en la función agregarCategoria()");
    sleep(2);
    
    return;
}
void eliminarCategoria(void){
    puts("Estás en la función eliminarCategoria()");
    sleep(2);
    
    return;
}
void modificarCategoria(void){
    puts("Estás en la función modificarCategoria()");
    sleep(2);
    
    return;
}
void listarCategorias(void){
    int i;
    
    puts("Estás en la función listarCategorias()");
    sleep(2);

    fp = fopen("categoriaDeLibros.dat", "rb");
	
    for(i = 0; i < 10; i++)
	{
		fread(&tmp3, sizeof(struct categoriaDeLibro), 1, fp);
		printf("Código: %d\n", tmp3.codigoCategoria);
		printf("Título: %s\n", tmp3.nombreCategoria);
		printf("\n");
	}

	fclose(fp);
    return;
}
void buscarCategoria(void){
    puts("Estás en la función buscarCategoria()");
    sleep(2);
    
    return;
}
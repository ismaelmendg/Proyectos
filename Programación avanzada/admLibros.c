/**********************************
 * ASIGNADO A : Kevin Inzunza
 * *********************************/
#include <stdio.h>
#include <unistd.h>
#include "biblioteca.h"

int menuLibros(void);
void admLibros(void);
void agregarLibro(void);
void eliminarLibro(void);
void modificarLibro(void);
void listarLibros(void);
void buscarLibro(void);

void admLibros(void){

    while(1){
        switch(menuLibros()){
			case 1:
					agregarLibro();
					break;
			case 2:
					eliminarLibro();
					break;
			case 3:
					modificarLibro();
					break;
			case 4:
					listarLibros();
					break;
			case 5: 
                    buscarLibro();
                    break;	
            case 6: 
					return;		
		}
    }

}

int menuLibros(void){
int opc;

    do{
        puts("OPCIONES DE MANTENIMIENTO LIBROS\n");
		puts("1) Submenú  AGREGAR LIBRO.");
		puts("2) Submenú  ELIMINAR LIBRO");
		puts("3) Submenú  MODIFICAR LIBRO");
		puts("4) Submenú  LISTAR LIBROS");
        puts("5) Submenú BUSCAR LIBRO");
		puts("6) Regresar al menú ADMINISTRACIÓN");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 6);

    return opc;
}

void agregarLibro(void){

    puts("Estás en la función agregarLibro()");
    sleep(2);
    
    return;
}
void eliminarLibro(void){
    puts("Estás en la función eliminarLibro()");
    sleep(2);
    
    return;
}
void modificarLibro(void){
    puts("Estás en la función modificarLibro()");
    sleep(2);
    
    return;
}
void listarLibros(void){
    int i;

    puts("Estás en la función listarLibro()");
    sleep(2);
    
    fp = fopen("libros.dat", "rb");
	for(i = 0; i < 20; i++)
	{
		fread(&tmp2, sizeof(struct libro), 1, fp);
		printf("ISBN: %s\n", tmp2.isbn);
		printf("Título: %s\n", tmp2.titulo);
		printf("Autor: %s\n", tmp2.autor);
		printf("Código Categoría: %d\n", tmp2.codigoCategoria);
		printf("Código Materia: %d\n", tmp2.codigoMateria);
		printf("Editorial: %s\n", tmp2.editorial);
		printf("Pais: %s\n", tmp2.pais);
		printf("Año: %d\n", tmp2.anio);
		printf("Páginas: %d\n", tmp2.paginas);

		printf("\n");
	}

	fclose(fp);
    return;
}
void buscarLibro(void){
    puts("Estás en la función buscarLibro()");
    sleep(2);
    
    return;
}
/**********************************
 * ASIGNADO A : Luis Martínez
 * *********************************/
#include <stdio.h>
#include "biblioteca.h"


//variables y cosas 

char junk[10];


//prototipos
int menuCategorias(void);
void admCategoria(void);
void agregarCategoria(void);
void eliminarCategoria(void);
void modificarCategoria(void);
void listarCategorias(void);
void buscarCategoria(void);
void crear(void);


void  admCategoria(void){

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

	fgets(junk, sizeof(junk), stdin);
	fp = fopen("categoriaDeLibros.dat", "r+b");
	
	if(fp == NULL){
		printf("Error en el  archivo\n");
		return;
	}// fin de error al crear
	
	
	
	
	while(!feof(fp)){
		
		fread(&actual,sizeof(actual),1,fp);
		
		printf("Introduzca el nombre de la nueva categoria\n");
		fgets(tmp3.nombreCategoria,sizeof(tmp3.nombreCategoria),stdin);
		
		printf("Introduzca el codigo de la nueva categoria\n");
		scanf("%d",&tmp3.codigoCategoria);
		
		fseek(fp,0,SEEK_END); //poner la nueva categoria al final
		fwrite(&tmp3, sizeof(tmp3), 1, fp);
		
		fclose(fp);
		printf("Se ha guardado la categoria\n");
		return;
	}//fin while

   return; 
   

}//fin agregar


void eliminarCategoria(void){
    
	int x=0;
	int contador;
	fgets(junk, sizeof(junk), stdin);
	fp = fopen("categoriaDeLibros.dat", "r+b");
	
	if(fp == NULL){
		printf("Error en el  archivo\n");
		return;
    }// fin de error al crear
	
	printf("Escriba el codigo de la categoria que quiere eliminar\n");
	scanf("%d",&x);
	
	while(!feof(fp)){
		fread(&actual,sizeof(actual),1,fp);
		contador++;// contar espacios movidos
		
		if(actual.codigoCategoria==x){
			fseek(fp,((contador-1)*sizeof(actual)),SEEK_SET);
			
			tmp3.codigoCategoria==0;
			tmp3.nombreCategoria=="";
			
			
			fwrite(&tmp3, sizeof(tmp3), 1, fp); // lo escribimos en el archivo
			printf("datos borrados del registro\n");
			
			return;
		}
		
	}//fin while
	
	
	printf("El codigo de la materia no se encuentra en registro\n\n");
	
    
    return;
}//fin eliminar


void modificarCategoria(void){
    
	int contador;//para contar los espacios que se mueve el fichero
    int x;
	fgets(junk, sizeof(junk), stdin);
	fp = fopen("categoriaDeLibros.dat", "r+b");
	
	if(fp == NULL){
		printf("Error en el  archivo\n");
		return;
	}//fin if de error
	
	printf("Escriba el codigo de la categoria a modificar\n");
	scanf("%d",&x);
	
	while(!feof(fp)){
	
	fread(&actual,sizeof(actual),1,fp);
	contador++;
	
	if(actual.codigoCategoria==x){
	printf("El codigo actual de la categoria es: %d\n",actual.codigoCategoria );
	printf("El nombre actual de la categoria es: %s\n",actual.nombreCategoria );
		
	printf("Introduzca el codigo nuevo de esta categoria\n");	
	scanf("%d",&tmp3.codigoCategoria);
	fgets(junk, sizeof(junk), stdin);
	
	printf("Introduzca el nombre nuevo de esta categoria\n");	
	fgets(tmp3.nombreCategoria,sizeof(tmp3.nombreCategoria),stdin);
	
	//ahora a escribliro en el documento
	
	fseek(fp,(contador-1)*sizeof(actual),SEEK_SET);
	fwrite(&tmp3, sizeof(tmp3), 1, fp);
	
	fclose(fp);
	printf("Categoria modificada con exito\n");
	return;
	}// fin if
	
	}// fin while
	
	
	
	printf("Ese codigo no se encuentra registrado\n");
	
    
    return;
}//fin modi


void listarCategorias(void){
    int i;
    
    puts("Estás en la función listarCategorias()");
   

    fp = fopen("categoriaDeLibros.dat", "rb");
	
    for(i = 0; i < 12; i++)
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
    
	int x=0;
	
	fgets(junk, sizeof(junk), stdin);
	fp = fopen("categoriaDeLibros.dat", "r+b");
	
	if(fp == NULL){
		printf("Error en el  archivo\n");
		return;
	}// fin de error al crear
    
	printf("Introduzca el codigo de la categria a buscar\n");
	scanf("%d",&x);
	
	while(!feof(fp)){
		fread(&actual,sizeof(actual),1,fp);
		
		if(actual.codigoCategoria==x){
		printf("Nombre de la categoria: %s\n",actual.nombreCategoria);
		printf("Codigo de la categoria: %d\n",actual.codigoCategoria);
		fclose(fp);
		return;
		}//fin if
		
		
	}//fin while
	
	printf("Categoria no registrada\n");
	
	

    
    return;
}//fin listar 




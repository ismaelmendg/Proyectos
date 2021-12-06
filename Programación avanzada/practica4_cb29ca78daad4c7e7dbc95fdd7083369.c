#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
char junk[3];

struct herramienta{
	int codigo;
	char descripcion[50];
	int cantidad;
	float precio;	
};

struct herramienta h;
int cont=0;

char busqueda[50];
int buscarCodigo;

void crear(void);
int menu(void);
void agregarHerramienta(void);
void buscarHerramienta(void);
void eliminarHerramienta(void);
void modificarHerramienta(void);
void listarHerramienta(void);

int main(){
    crear();
    	
	while(1){
		switch( menu() ){
			
			case 1: 
					agregarHerramienta();
			break;
			
			case 2:
					buscarHerramienta();
			break;
			
			case 3:
					eliminarHerramienta();
			break;
			
			case 4: 
					modificarHerramienta();	
			break;
			
			case 5:
					listarHerramienta();
			break;
			
			case 6: exit(0);
		
		}//Fin switch
	}//Fin while
}//Fin main


/***FUNCIÓN MENU***/
int menu(void){
 int opc;
 	
	do{
		puts("\tMENU\t");
		puts("1) Agregar Herramienta");
		puts("2) Buscar Herramienta por Descripción");
		puts("3) Eliminar Herramienta");
		puts("4) Modificar Herramienta");
		puts("5) Listar Herramientas en el Almacén");
		puts("6) Salir");
	
		scanf("%i", &opc);
		fgets(junk, sizeof(junk), stdin);
	}while(opc < 1	|| opc > 6);
		
	return opc;
}//Fin menu

/***CREAR DOCUMENTO***/
void crear(void){

 	fp = fopen("ferreteria.dat", "rb"); 	
     	if(fp == NULL){
	       fp = fopen("ferreteria.dat","wb");
		   fclose(fp);   
        return;
	    }//Fin if
	fclose(fp);
    return;
}//Fin crear


/***FUNCION AGREGAR HERRAMIENTA***/
void agregarHerramienta(void){
 int cont=0;

  puts("\tAGREGAR HERRAMIENTA");
    
 	fp = fopen("ferreteria.dat", "r+b");
 	
 	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
	return;
	}//Fin if
	
	while(!feof(fp)){
	 fread(&h, sizeof(h), 1, fp);
   	 cont++;
	
		if(!strcmp("", h.descripcion)==1){
			printf("Ingrese Código\n");
			scanf("%d", &h.codigo);
			fgets(junk, sizeof(junk), stdin);
			
			puts("Ingrese Descripción");
			fgets(h.descripcion, sizeof(h.descripcion), stdin);
			
			printf("Ingrese Cantidad\n");
			scanf("%d", &h.cantidad);
			printf("Ingrese Precio\n");
			scanf("%f", &h.precio);
			fgets(junk, sizeof(junk), stdin);
			fseek(fp, ((cont-1)*sizeof(h)), SEEK_SET);
			fwrite(&h,sizeof(h),1,fp);
			printf("Datos agregados satisfactoriamente.\n\n");	
			
			fclose(fp);
		return;
		}//Fin if
	}//Fin while
            puts("Ingrese Código");
			scanf("%d", &h.codigo);
			puts("Ingrese Descripción");
			fgets(junk, sizeof(junk), stdin);
			fgets(h.descripcion, sizeof(h.descripcion), stdin);
			puts("Ingrese Cantidad");
			scanf("%d", &h.cantidad);
			puts("Ingrese Precio");
			scanf("%f", &h.precio); 
			printf("Datos agregados satisfactoriamente.\n\n");	
			
			//fgets(junk, sizeof(junk), stdin);
			fwrite(&h,sizeof(h),1,fp);
        
	fclose(fp);
}//Fin agregarHerramienta


/***FUNCION BUSCAR HERRAMIENTA***/
void buscarHerramienta(void){
  puts("\tBUSCAR HERRAMIENTA");
    
    fp = fopen("ferreteria.dat","r+b");
        if(fp == NULL){
            printf("Error al abrir el archivo");
        return;
        }//Fin if
   
     printf("Ingrese la descripcion de la herramienta:\n");
     fgets(busqueda, sizeof(busqueda), stdin);
    
    while(!feof(fp)){
        fread(&h, sizeof(h), 1, fp);
       
        if(!strcmp(busqueda, h.descripcion)==1){
            
            puts("\nHerramienta encontrada\n");
            printf("Codigo %d\n" , h.codigo);
            printf("Descripcion: %s", h.descripcion);
            printf("Cantidad: %d unidades\n", h.cantidad);
            printf("Precio: $%.2f\n\n", h.precio);
            
        fclose(fp);
        return;
        }//Fin if
    }//Fin while
  printf("No se encontro la herramienta que buscaba.\n\n");
}//Fin buscarHerramienta


/***FUNCION ELIMNAR HERRAMIENTA***/
void eliminarHerramienta(void){
 struct herramienta temp = {0 , "", 0, 0.0};
 int cont = 0;
    puts("\tELIMINAR HERRAMIENTA");
    fp = fopen("ferreteria.dat", "r+b");
 	
 	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
	return;
	}//Fin if

	printf("Ingrese el codigo a eliminar\n");
    scanf("%d", &buscarCodigo);
	
	while(!feof(fp)){
	 fread(&h, sizeof(h), 1, fp);
   	 cont++;
         
         if(h.codigo == buscarCodigo){
         
            fseek(fp, ((cont-1)*sizeof(h)), SEEK_SET);
            fwrite(&temp,sizeof(temp),1,fp);
            fclose(fp);
            printf("Datos eliminados Satisfactoriamente\n\n");
         return;
         }//Fin if
    }//Fin while  
    printf("Codigo No Encontrado\n\n"); 
     
}//Fin eliminarHerramienta


/***FUNCION MODIFICAR CODIGO***/
void modificarHerramienta(void){
 int cont=0;
    puts("\tMODIFICAR HERRAMIENTA");
    fp = fopen("ferreteria.dat", "r+b");
 	
 	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
	return;
	}//Fin if

	printf("Ingrese el codigo a modificar\n");
    scanf("%d", &buscarCodigo);
	
	while(!feof(fp)){
	 fread(&h, sizeof(h), 1, fp);
   	 cont++;
         
         if(h.codigo == buscarCodigo){
            
            puts("\tDatos Actuales");
            printf("Codigo %d\n", h.codigo);
            printf("Descripcion: %s", h.descripcion);
            printf("Cantidad: %d unidades\n", h.cantidad);
            printf("Precio: $%.2f\n\n", h.precio);
            
            puts("\tDatos a modificar");
            fgets(junk, sizeof(junk), stdin);
			puts("Ingrese Descripción");
			fgets(h.descripcion, sizeof(h.descripcion), stdin);
			puts("Ingrese Cantidad");
			scanf("%d", &h.cantidad);
			puts("Ingrese Precio");
			scanf("%f", &h.precio); 
			printf("Datos modificados satisfactoriamente.\n\n");	
            
            puts("\tDatos Modificados");
            printf("Codigo %d\n", h.codigo);
            printf("Descripcion: %s", h.descripcion);
            printf("Cantidad: %d unidades\n", h.cantidad);
            printf("Precio: $%.2f\n\n", h.precio);            
            
            fseek(fp, ((cont-1)*sizeof(h)), SEEK_SET);
            fwrite(&h,sizeof(h),1,fp);
            fclose(fp);
         return;
         }//Fin if
    }//Fin while  
    printf("Codigo No Encontrado\n\n"); 

}//Fin modificarHerramienta


/***FUNCION LISTAR HERRAMIENTAS***/
void listarHerramienta(void){
 int i;
 int cont=0;
  
   puts("\tLISTAR HERRAMIENTAS");
    fp = fopen("ferreteria.dat", "rb");
    
    if(fp == NULL){
        printf("No se pudo abrir el archivo");
    return;
    }//Fin if
    fseek(fp, 0, SEEK_SET);
    
    while(fread(&h, sizeof(h), 1, fp)){
     
        if(!(h.codigo == 0)){
              cont++;
              printf("Registro #%d\n",cont);   
              printf("Codigo %d\n", h.codigo);
              printf("Descripcion: %s", h.descripcion);
              printf("Cantidad: %d unidades\n", h.cantidad);
              printf("Precio: $%.2f\n\n", h.precio); 
        }//Fin if
    }//Fin While
    if(cont==0){
        printf("No hay herramientas en el catalogo.\n\n");
    }//Fin if
    
fclose(fp);
}//Fin listarHerramienta





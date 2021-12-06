/**********************************
 * ASIGNADO A : Ismael Mendoza
 * *********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

struct materia tmp4;
extern struct materia;
extern struct materia arrMaterias[30];


int i;
FILE *fp;
char junk[2];
char basura[5];
int menu(void);
int buscarn;
int menuMaterias(void);
void admMaterias(void);
void agregarMateria(void);
void eliminarMateria(void);
void modificarMateria(void);
void listarMaterias(void);
void buscarMateria(void);


void admMaterias(void){
	
    while(1){
        switch(menuMaterias()){
			case 1:
					agregarMateria();
					break;
			case 2:
					eliminarMateria();
					break;
			case 3:
					modificarMateria();
					break;
			case 4:
					listarMaterias();
					break;
			case 5: 
                    buscarMateria();
                    break;	
            case 6: 
					return;		
		}
    }

}

int menuMaterias(void){
int opc;

    do{
        puts("OPCIONES DE MANTENIMIENTO MATERIAS\n");
		puts("1) Submenú  AGREGAR MATERIA.");
		puts("2) Submenú  ELIMINAR MATERIA");
		puts("3) Submenú  MODIFICAR MATERIA");
		puts("4) Submenú  LISTAR MATERIAS");
        puts("5) Submenú BUSCAR MATERIA");
		puts("6) Regresar al menú ADMINISTRACIÓN");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 6);

    return opc;
}

void agregarMateria(void){
    
	int cont=0;
	printf("\tFUUNCION PARA DAR DE ALTA NUEVA MATERIA\n");
	fgets(junk, sizeof(junk), stdin);
	fp = fopen("materias.dat", "r+b");
	if(fp == NULL){
		printf("Error al crear el archivo\n");
		return;
}//Fin if
	while (!feof(fp)){
		fread(&arrMaterias[i],sizeof(arrMaterias[i]),1,fp);
		cont++;
		if(!strcmp("",arrMaterias[i].nombreMateria)==1){
			printf("Dijite el codigo de la materia nueva a registrar: \n");
			scanf("%d", &arrMaterias[i].codigoMateria);
			fgets(junk, sizeof(junk), stdin);
			printf("Escriba el nombre de la materia: \n");
			fgets(arrMaterias[i].nombreMateria, sizeof(arrMaterias[i].nombreMateria), stdin);;
			fseek(fp,((cont-1)*sizeof(arrMaterias[i])),SEEK_SET);
			//fwrite(&arrMateria,sizeof(arrMateria),1,fp);
			fwrite(&arrMaterias[i], sizeof(struct materia), 1, fp);
	    	fclose(fp);
	    	printf("\nDatos agregados exitosamente\n\n");	
	    	return;
}//Fin if	

}//Fin while
		
			printf("Dijite el codigo de la materia nueva a registrar: \n");
			scanf("%d", &arrMaterias[i].codigoMateria);
			fgets(junk, sizeof(junk), stdin);
			printf("Escriba el nombre de la materia: \n");
			fgets(arrMaterias[i].nombreMateria, sizeof(arrMaterias[i].nombreMateria), stdin);;
			//fwrite(&arrMateria, sizeof(arrMateria),1, fp);
			fwrite(&arrMaterias[i], sizeof(struct materia), 1, fp);
			printf("\nDatos agregados exitosamente\n\n");
			fclose(fp);
			
}

void eliminarMateria(void){
    int cont=0;
	struct materia eliminar = {0, ""};
	fgets(basura, sizeof(basura), stdin);
	fp = fopen("materias.dat", "r+b");
	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
	return;
}//Fin if
	printf("\tFuncion de bajas\n");
	printf("Dijite codigo de la materia a dar de baja: ");
	scanf("%d", &buscarn);
	
	while(!feof(fp)){
		fread(&arrMaterias[i],sizeof(arrMaterias[i]),1,fp);
		cont++;
		if(arrMaterias[i].codigoMateria == buscarn){				
			fseek(fp,((cont-1)*sizeof(arrMaterias[i])),SEEK_SET);
			fwrite(&eliminar,sizeof(eliminar),1,fp);
	    	fclose(fp);	
	    	printf("Datos eliminados exitosamente\n\n");	
			return;
}//Fin if
}//Fin while
	printf("El codigo de la materia no se encuentra en registro\n\n");
    return;
}

void modificarMateria(void){
    int cont=0;
	printf("\tFuncion de Cambios\n");
	fgets(basura, sizeof(basura), stdin);
	fp = fopen("materias.dat", "r+b");
	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
		return;
}//Fin if
	printf("Dijite el codigo de la materia a modificar: ");
	scanf("%d", &buscarn);
	
		while(!feof(fp)){
		cont++;
		fread(&arrMaterias[i],sizeof(arrMaterias[i]),1,fp);
		if(arrMaterias[i].codigoMateria == buscarn){	
			printf("El codigo es: %d\n", arrMaterias[i].codigoMateria);
		printf("\tInformacion a modificar.\n");
			printf("Informacion actual de la materia: %s\n", arrMaterias[i].nombreMateria);
			
			fgets(junk, sizeof(junk), stdin);
			printf("Escriba el nombre de la materia nueva a registrar: \n");
			//fgets(junk, sizeof(junk), stdin);
			fgets(arrMaterias[i].nombreMateria, sizeof(arrMaterias[i].nombreMateria), stdin);
			fseek(fp,((cont-1)*sizeof(arrMaterias[i])),SEEK_SET);
			//fwrite(&arrMateria,sizeof(arrMateria),1,fp);
			fwrite(&arrMaterias[i], sizeof(arrMaterias[i]), 1, fp);
	    	fclose(fp);				//struct materia
	    	printf("\nDatos modificados exitosamente\n\n");	
			return;
}//Fin if
}//Fin while
	printf("No se encuentra la materia registrada\n\n");
}

void listarMaterias(void){
    
	int cont=0;
	printf("\tFuncion lista de Materias\n");
	fp = fopen("materias.dat", "rb");
		fseek(fp, 0, SEEK_SET);
	while(fread(&tmp4, sizeof(struct materia), 1, fp)){
		if(!(arrMaterias[i].codigoMateria == 0)){
              cont++;;
		printf("Codigo de la materia: %d\n", tmp4.codigoMateria);
		printf("Nombre de la materia: %s\n", tmp4.nombreMateria);
		printf("\n");
}//fin if
}//Fin while
	if(cont == 0){
				printf("No hay materias registradas\n");
	return;
}//Fin if
	fclose(fp);
	
}

void buscarMateria(void){
    fgets(basura, sizeof(basura), stdin);
	fp = fopen("materias.dat", "r+b");
	if(fp == NULL){
		printf("Error al abrir el archivo.\n");
		return;
}//Fin if
	printf("Dijite codigo de la materia que esta bucando: ");
	scanf("%d", &buscarn);

	while (!feof(fp)){
		fread(&arrMaterias[i],sizeof(arrMaterias[i]),1,fp);
		if(arrMaterias[i].codigoMateria == buscarn){	
			printf("\tInformacion completa.\n");
			printf("El codigo es: %d\n", arrMaterias[i].codigoMateria);
			printf("El nombre de la materia es: %s\n", arrMaterias[i].nombreMateria);
			
			fclose(fp);
			return;
}//Fin if
}//Fin while
printf("%d", buscarn);
	printf("No se encuentra coincidencias del codigo en los registros\n\n");
}

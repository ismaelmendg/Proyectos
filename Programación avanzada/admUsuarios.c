/**********************************
 * ASIGNADO A : Jesús Huerta
 * *********************************/
#include <stdio.h>
#include <unistd.h>
#include "biblioteca.h"

int menuUsuarios(void);
void admUsuarios(void);
void agregarUsuario(void);
void eliminarUsuario(void);
void modificarUsuario(void);
void listarUsuarios(void);
void buscarUsuario(void);

void admUsuarios(void){
    while(1){
        switch(menuUsuarios()){
			case 1:
					agregarUsuario();
					break;
			case 2:
					eliminarUsuario();
					break;
			case 3:
					modificarUsuario();
					break;
			case 4:
					listarUsuarios();
					break;
			case 5: 
                    buscarUsuario();
                    break;	
            case 6: 
					return;		
		}
    }

}

int menuUsuarios(void){
int opc;

    do{
        puts("MANTENIMIENTO DE USUARIOS\n");
		puts("1) Submenú AGREGAR USUARIO.");
		puts("2) Submenú ELIMINAR USUARIO");
		puts("3) Submenú MODIFICAR USUARIO");
		puts("4) Submenú LISTAR USUARIOS");
        puts("5) Submenú BUSCAR USUARIO");
		puts("6) Regresar al menú ADMINISTRACIÓN");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 6);

    return opc;
}

void agregarUsuario(void){

    puts("Estás en la función agregarUsuario()");
    sleep(2);
    
    return;
}
void eliminarUsuario(void){
    puts("Estás en la función eliminarUsuario()");
    sleep(2);
    
    return;
}
void modificarUsuario(void){
    puts("Estás en la función modificarUsuario()");
    sleep(2);
    
    return;
}
void listarUsuarios(void){
    int i;

    puts("Estás en la función listarUsuarios()");
    sleep(2);
    
    fp = fopen("usuarios.dat", "rb");
	for(i = 0; i < 18; i++)
	{
		fread(&tmp, sizeof(struct usuario), 1, fp);
		printf("Código usuario: %d\n", tmp.codigoUsuario);
		printf("Nombre: %s\n", tmp.nombre);
		printf("Apellidos: %s\n", tmp.apellidos);
		printf("Dirección: %s\n", tmp.direccion);
		printf("Localidad: %s\n", tmp.localidad);
		printf("Teléfono: %s\n", tmp.telefono);
		printf("Fecha de nacimiento: %s\n", tmp.fechaDeNacimiento);
		printf("Sexo: %c\n", tmp.sexo);
		printf("\n");
	}
	fclose(fp);
    
    return;
}
void buscarUsuario(void){
    puts("Estás en la función buscarUsuario()");
    sleep(2);
    
    return;
}
#include <stdio.h>

int menuAdm(void);
void administracion(void);
void admUsuarios(void);
void admLibros(void);
void admCategorias(void);
void admMaterias(void);

void administracion(void){

    while(1){
        switch(menuAdm()){
			case 1:
					admUsuarios();
					break;
			case 2:
					admLibros();
					break;
			case 3:
					admCategorias();
					break;
			case 4:
					admMaterias();
					break;
			case 5: 
					return;		
		}
    }

}

int menuAdm(void){
int opc;

    do{
        puts("MENÚ DE ADMINISTRACIÓN\n");
		puts("1) Submenú de USUARIOS.");
		puts("2) Submenú de LIBROS");
		puts("3) Submenú de CATEGORÍAS DE LIBROS");
		puts("4) Submenú de MATERIAS");
		puts("5) Regresar al menú principal");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 5);

    return opc;
}
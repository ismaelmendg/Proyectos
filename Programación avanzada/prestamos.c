#include <stdio.h>

int menuPrestamos(void);
void prestamos(void);
void registrarPrestamo(void);
void devolverPrestamo(void);

void prestamos(void){

    while(1){
        switch(menuPrestamos()){
			case 1:
					registrarPrestamo();
					break;
			case 2:
					devolverPrestamo();
					break;
			case 3: 
					return;		
		}
    }

}

int menuPrestamos(void){
int opc;

    do{
        puts("MENÚ DE PRÉSTAMOS DE LIBROS\n");
		puts("1) Registrar PRÉSTAMO DE LIBRO");
		puts("2) Devolver LIBRO EN PRÉSTAMO ");
		puts("3) Regresar al menú anterior");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 3);

    return opc;
}

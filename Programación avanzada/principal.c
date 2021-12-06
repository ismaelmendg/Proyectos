#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int menuPrincipal(void);
void administracion(void);
void prestamos(void);
void consultas(void);
//void avanzadas(void);

int main(){

    while(1){
        switch(menuPrincipal()){
			case 1:
					administracion();
					break;
			case 2:
					prestamos();
					break;
			case 3:
					consultas();
					break;
//			case 4:
//					avanzadas();
//					break;
			case 4: 
                    system("clear");
					puts("Saliendo del programa...\n");
                    sleep(2);
					exit(0);		
		}
    }

    return 0;
}

int menuPrincipal(void){
int opc;

    do{
        puts("SISTEMA DE BIBLIOTECA\n");
		puts("1) Menú de Administración.");
		puts("2) Menú de Operaciones (Préstamo de Libros)");
		puts("3) Menú de Operaciones (Consulta de Libros)");
		//puts("4) Menú de Consultas Avanzadas");
		puts("4) Salir del programa");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 4);

    return opc;
}
#include <stdio.h>

int menuConsultas(void);
void consultas(void);
void registrarConsulta(void);
void devolverConsulta(void);

void consultas(void){

    while(1){
        switch(menuConsultas()){
			case 1:
					registrarConsulta();
					break;
			case 2:
					devolverConsulta();
					break;
			case 3: 
					return;		
		}
    }

}

int menuConsultas(void){
int opc;

    do{
        puts("MENÚ DE CONSULTAS DE LIBROS\n");
		puts("1) Registrar CONSULTA DE LIBRO");
		puts("2) Devolver LIBRO EN CONSULTA ");
		puts("3) Regresar al menú anterior");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 3);

    return opc;
}

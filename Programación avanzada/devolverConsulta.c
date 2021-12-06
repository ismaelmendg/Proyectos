/**********************************
 * ASIGNADO A : Juan Pablo Padilla
 * *********************************/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "biblioteca.h"

void devolverConsulta(void){
    int i;
    struct tm *ptr;

    puts("Estás en la función devolverConsulta()");
    sleep(2);

    fp = fopen("consultas.dat", "rb");
	for(i = 0; i < 10; i++)
	{
		fread(&tmp6, sizeof(struct consulta), 1, fp);
		printf("Número de consulta: %d\n", tmp6.numDeConsulta);
		printf("Código de usuario: %d\n", tmp6.codigoUsuario);
		printf("ISBN: %s\n", tmp6.isbn);
        ptr = localtime(&tmp6.fechaDeConsulta);
		printf("Fecha de consulta: %d/%d/%d\n", ptr->tm_mday, ptr->tm_mon + 1, ptr->tm_year + 1900);
        //printf("Fecha de consulta: %ld\n", (long int) tmp6.fechaDeConsulta);
		printf("Devuelto: %d\n", tmp6.devuelto);
		printf("\n");
	}
  
	fclose(fp);

    return;
}
/*
struct consulta{
	int numDeConsulta;
	int codigoUsuario;
	char isbn[18];
	time_t fechaDeConsulta;
	short devuelto;
};
struct consulta arrConsultas[50] =
{
	{1, 2354589, "100", 150262753, 0},
	{2, 2477019, "200", 150349153, 1},
	{3, 2490285, "300", 151126753, 1},
	{4, 2354589, "400", 1588018184, 0},
	{5, 2477019, "500", 1588028184, 1},
	{6, 2490285, "600", 1588038184, 1},
	{7, 2354589, "401", 1588048184, 0},
	{8, 2477019, "501", 1588058184, 0},
	{9, 2490285, "300", 1588068184, 0},
	{10, 2490285, "900", 1588068401, 0}
};
*/
#include <time.h>

struct usuario
{
	int codigoUsuario;
	char nombre[50];
	char apellidos[50];
	char direccion[60];
	char localidad[50];
	char telefono[15];
	char fechaDeNacimiento[11];
	char sexo;
};

struct libro
{
	char isbn[18];
	char titulo[150];
	char autor[100];
	int codigoCategoria;
	int codigoMateria;
	char editorial[80];
	char pais[25];
	int anio;
	int paginas;	
};

struct categoriaDeLibro
{
	int codigoCategoria;
	char nombreCategoria[25];
};

struct materia
{
	int codigoMateria;
	char nombreMateria[25];
};

struct prestamo
{
	int numDePrestamo;
	int codigoUsuario;
	char isbn[18];
	time_t fechaDePrestamo;
	short devuelto;
	time_t fechaDeDevolucion;	
};

struct consulta{
	int numDeConsulta;
	int codigoUsuario;
	char isbn[18];
	time_t fechaDeConsulta;
	short devuelto;
};

FILE *fp;
struct usuario tmp;
struct libro tmp2;
struct categoriaDeLibro tmp3;
struct materia tmp4;
struct prestamo tmp5;
struct consulta tmp6;

/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo usuarios.dat
 ***********************************************************/
/*
struct usuario arrUsuarios[50] = {
	{2354589,"ADALBERTO","ALVAREZ MONTES","Salvador de Madariaga #5010,Cd. Juarez","6563417311","24/06/1995",'H'},
	{2477019,"STEPHANIE SARAHI","CORONA GARCIA","Avenida Mexico #2927","Hermosillo, Sonora","6621137199","17/01/1994",'M'},
	{2490285,"LILIA","CRISTERNA SOLIS","Rey Neptuno #5045","Tepic,Nayarit","3111456659","15/11/1994",'M'},
	{2047580,"CARLOS ALBERTO","GALINDO MEZA","Calle 8 ","Acapulco, Guerrero","3311223377","12/08/1995",'H'},
	{2571001,"LUIS FELIPE","GOMEZ PARRA","av magnolias","zapopan, Jalisco","3317046545","04/05/1995",'H'},
	{2564001,"SELENE","GUTIERREZ FERNANDEZ","Victor Hugo 520" ,"zapopan jalisco","3141181842","08/04/1995",'M'},
	{2510969,"SEBASTIAN ROBERTO","HERNANDEZ HUERTA","Leon Tolstoy/Victor hugo y rafael sancio #5412","Zapopan, Jalisco","6121503228","14/02/1995",'H'},
	{2564647,"ERNESTO MICHELLE","IBERRI PACHECO","playa del tesoro #5547","zapopan, Jalisco","3336286441","04/06/1994",'H'},
	{1922826,"ISRAEL","LANDA FUENTES","GIRASOLES ACUEDUCTO","zapopan jalisco","3338369881","28/10/1995",'H'},
	{2600752,"JAVIER","MEDINA CAZARES","Salvador de Madariaga #5010","zapopan, Jalisco","3141062692","03/11/1995",'H'},
	{2540829,"LUZ MARIA","MONFIL GONZALEZ","Victor Hugo #520","zapopan, Jalisco","7831344981","15/05/1995",'M'},
	{2476120,"CESAR DAVID","MORENO ALMIRUDIS","Salvador de Madariaga #5010","zapopan,Jalisco","3319831203","25/01/1995",'H'},
	{1874747,"HUMBERTO","ORNELAS JIMENEZ","tangamandapio","zapopan, Jalisco","3314425735","14/02/1995",'H'},
	{2528535,"CRISTABEL","RAMIREZ GONZALEZ","Haciendas tepeyac","Apatzingan,Mich","3333333333","05/02/1995",'M'},
	{2547750,"RAFAEL AGUSTIN","RODRIGUEZ LOPEZ","Rio Ocotlan #1324 Col. Atlas","Guadalajara, Jalisco","3336352778","19/09/1995",'H'},
	{2567053,"WERNER","SUCHOWITZKI OROZCO","Yextho #58","zapopan, Jalisco","3335552224","07/08/1995",'H'},
	{2451626,"ANGEL GUILLERMO","VENEGAS SANDOVAL","Avenida Mexico #2928","Islas Sandwich, Guerrero","1112223344","04/12/1960",'H'},
	{2488125,"JORGE PABLO","ZALPA SALAS","Avenida Mexico #3030","Ayotzinapa,Guerrero","1112224433","03/12/2014",'H'}
};
*/
/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo libros.dat
 ***********************************************************/
/*
struct libro arrLibros[50] = {
	{"100","AN INTRODUCTION TO OBJECT ORIENTED DESING IN C++" ,"PERRY JO ELLEN" ,11,8001,"ADDISON WESLEY PUBLISHING","USA",1996,324},
	{"200","PROGRAMACION EN TURBO C" ,"SCHILDT HERBERT",11,8001,"MCGRAW HILL","MEXICO",1991,350},
	{"300","THE ART OF COMPUTER PROGRAMMING" ,"KNUTH DONALD E" ,11,8001,"ADDISON WESLEY PUBLISHING","USA",1981,426},
	{"400","INTRODUCCION AL ANALISIS DE CIRCUITOS","BOYLESTAD ROBERT L",22,8002,"PEARSON EDUCACION DE MEXICO","MEXICO",2011,914},
	{"500","HECHOS Y QUIMERAS EDUCACION SUPERIOR CIENCIA Y TECNOLOGIA LIBRO II POLITICA EDUCATIVA","PALLAN FIGUEROA CARLOS",33,8003,"ANUIES 2013","MEXICO",2013,205},
	{"600","BARBA GRIS","ALDISS BRIAN WILSON 1925",44,8004,"BRUGUERA" ,"BARCELONA",1977,315},
	{"700","ANATOMY DESCRIPTIVE AND SURGICAL","GRAY HENRY",55,8005,"NEW YORK BARNES&NOBLE","USA",1995,1096},
	{"800","CIEN ANOS DE SOLEDAD","GARCIA MARQUEZ GABRIEL",44,8004,"MADRID CATEDRA","MADRID",2001,548},
	{"900","Y EL MONO SE CONVIRTIO EN HOMBRE","LEGUIZAMON RAUL O" ,44,8004,"FOLIA UNIVERSITARIA","MEXICO",2006,94},
	{"101","Requierements Engineering For Software And Sistems","LAPLANTE PHILLIP A",66,8006,"CRC/TAYLOR & FRANCIS","USA",2014,325},
	{"201","FISICA PARA INGENIERIA Y CIENCIAS CON FISICA MODERNA","BAUER WOLFGANG",77,8007,"MCGRAW HILL","MEXICO",2014,452},
	{"301","BIOPROCESS ENGINEERING PRINCIPLES","DORAN PAULINE M",88,8008,"ELSEVIER/ACADEMIC PRESS","KIDLINGTON",2013,563},
	{"401","PROBABILIDAD Y ESTADISTICA PARA INGENIERIA Y CIENCIAS","S/D",99,8009,"PEARSON EDUCACION DE MEXICO","MEXICO" ,2012,368},
	{"501","ETNOGRAFIAS DE AMERICA LATINA OCHO ENSAYOS","S/D",33,8003,"CENTRO UNIVERSITARIO DE CIENCIAS SOCIALES Y HUMANIDADES","MEXICO" ,2013,298},
	{"601","THERBORN GORAN 1941","THERBORN GORAN",44,8004,"ALIANZA EDITORIAL","MADRID",2012,356},
	{"701","ANTROPOLOGIA CULTURAL","KOTTAK CONRAD PHILLIP",33,8003,"MCGRAW HILL INTERAMERICANA EDITORES","MEXICO" ,2013,471},
	{"801","LA INSURGENCIA INDEPENDENTISTA EN JALISCO","MURIA JOSE M",100,8010, "INSTITUTO NACIONAL DE ANTROPOLOGIA E HISTORIA","MEXICO" ,2009,109},
	{"901","HABLANDO FUERTE ANTROPOLOGIA JURIDICA COMPARATIVA DE MESOAMERICA","BROKMANN HARO CARLOS",33,8003,"COMISION NACIONAL DE DERECHOS HUMANOS","MEXICO" ,2008,216},
	{"102","ELEMENTOS DE ANTROPOLOGIA PEDAGOGICA","BARRIO MAESTRE JOSE MARIA",33,8003,"BARCELONA EDICIONES RIALP","BARCELONA",2004,271},
	{"202","FUNDAMENTOS DE LA ANTROPOLOGIA UN IDEAL DE LA EXCELENCIA HUMANA","YEPES STORK RICARDO",33,8003,"EDICIONES UNIVERSIDAD DE NAVARRA","ESPANA",1998,320}
};
*/
/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo categoriaDeLibros.dat
 ***********************************************************/
/*
struct categoriaDeLibro arrCategoriaLibros[20] =
{
	11,"Libro",
	22,"Novela",
	33,"Revista",
	44,"Atlas",
	55,"Journal",
	66,"Mapa",
	77,"Fasciculo",
	88,"Encicloiedia",
	99,"Periodico",
	100,"Audio libro"
};
*/
/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo materias.dat
 ***********************************************************/

struct materia arrMaterias[30] =
{
	8001,"Programacion",
	8002,"Electronica",
	8003,"Humanidades",
	8004,"Filosofia",
	8005,"Ingenieria",
	8006,"Fisica",
	8007,"Matematicas",
	8008,"Historia",
	8009,"Biografias",
	8010, "Antropologia"
};

/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo prestamos.dat
 ***********************************************************/
/*
struct prestamo arrPrestamos[50] = 
{
	{1, 2354589, "100", 150521953, 1, 151126753},
	{2, 2477019, "102", 150262753, 1, 150349153},
	{3, 2490285, "202", 150435553, 0, 0 },
	{4, 2354589, "300", 1588038184, 0, 0 },
	{5, 2477019, "400", 1588038284, 0, 0 },
	{6, 2490285, "500", 1588038384, 0, 0 }
};
*/
/***********************************************************
 * El siguiente arreglo se utiliza para inicializar  el
 * archivo consultas.dat
 ***********************************************************/
/*
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
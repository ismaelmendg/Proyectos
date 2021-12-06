

#include <stdio.h>
#include "pADC.h"
#include "PWM.h"
#define alpha 0.05

/*#ifndef NSensor_MediaMovil
   #define NSensor_MediaMovil 1
#endif


#ifndef Muestras_MediaMovil
  #define Muestras_MediaMovil 10
#endif

float  PilaSensor[NSensor_MediaMovil][Muestras_MediaMovil];
float MediaMovil(int ntabla,float valor);

float Ynuevo;*/

int main(void) {

	int *ADCresult = (int*)0x4003B010;
	int ADCfiltrado = 0;
	int ADCraw = 0;

	vfnPWM();

    while(1){
    	vfnADC();

    	//MediaMovil(1, *ADCresult);

    	ADCraw = *ADCresult;
    	ADCfiltrado = (alpha*ADCraw) + ((1-alpha) * ADCfiltrado);

    	vfnC4V(ADCfiltrado);
}}



/*float MediaMovil(int ntabla,float valor){

	int i;
	Ynuevo=0;

  for(i=Muestras_MediaMovil-1;i>0;i--){

	  PilaSensor[ntabla][i] = PilaSensor[ntabla][i-1];
        Ynuevo+=PilaSensor[ntabla][i];}

   PilaSensor[ntabla][0]=valor;
   Ynuevo+=PilaSensor[ntabla][0];

   Ynuevo/=Muestras_MediaMovil;
   return Ynuevo;

}
*/


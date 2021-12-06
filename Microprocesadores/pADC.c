

void delay();
void vfnADC(void){

	int *pRELOJ_PIN = (int*)0x40048038;
	int *pRELOJ_ADC = (int*)0x4004803C;
	int *PCRB		= (int*)0x4004A000; //B0
	int *ADC_SC1A   = (int*)0x4003B000;
	int *ADC_CFG1   = (int*)0x4003B008;

	*pRELOJ_PIN |= 0x400; //Enceder Reloj del Pin
	*pRELOJ_ADC |= 0x8000000 | 0x1000000; //Reloj del ADC
	*PCRB	    = *PCRB & ~(0x700); // Puerto del pin en análogo
	*ADC_SC1A   = 0x8; //AD8 01000
	delay();
	*ADC_CFG1   = 0xD;//Bus dividido entre dos, 16 bits
}

void delay(void){
	int x = 0xFFF;
	while(x--);
}

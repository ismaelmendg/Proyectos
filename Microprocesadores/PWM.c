
void vfnPWM(void){

	int *Clk_Pin   = (int*)0x40048038;
	int *Clk_Pwm   = (int*)0x4004803C;
	int *SIM_SOPT2 = (int*)0x40048004;
	int *PWM_SC    = (int *)0x40038000;

	int *PWM_MOD   = (int *)0x40038008;
	int *pPCRC8    = (int*)0x4004B020;
	int *TPM0_C4SC = (int*)0x4003802C;


	*Clk_Pin   = 0x800;
	*Clk_Pwm   |= 0x1000000;
	*SIM_SOPT2 = 0x1000000; //MCGFLLCLK clock or MCGPLLCLK/2
	*pPCRC8    = 0x300;//alt3
	*PWM_SC    = 0xF; //prescale 128 - CMOD 01 21M/128=164062.5   --  164062/x = 50  --   x = 3281
	*PWM_MOD   = 3281; //3281
	*TPM0_C4SC = 0x28; //MSB - ELSB  para Enge Aligned PWM a la izquierda

}

void vfnC4V(unsigned short ADC){

	int *TPM0_C4V = (int *)0x40038030;

	*TPM0_C4V = 82.025 + (ADC * .0050064);

	//////82.025 - 410.125///// (0.5m * MOD(3281))/20m
////////0.5m - 2.5m

}

/* sistem darbe zamanlayicisini kullanarak timer elde ettik  */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

uint16_t count;

void delay_ms(uint32_t time) {
	count = time; 	// time degerine asagida 1000 degerini verdik dolayisiyla count degeri de 1000 oldu
	while(count); 	// count degeri 0 olana kadar bekletiyor
}

void GPIO_Config(void) {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD , &GPIO_InitStruct);
}

void SysTick_Handler(void) { // her 1ms interrupt a girecek ve bu fonk gelecek 
	if(count > 0)	
		count--;     // ve count degerini 1 azaltacak
}

int main(void) {
	GPIO_Config();
	SysTick_Config(SystemCoreClock/1000); // systemcoreclock 32000000 olarak ayarlandi  // 1000us = 1ms zamanlayici elde ettik.

	/* SystemCoreClock/1000 		1ms de bir interrepta dallanir
	 * SystemCoreClock/100000		10us de bir interrepta dallanir
	 * SystemCoreClock/1000000		1us de bir interrepta dallanir
	 */

  while (1) {
	GPIO_ToggleBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	delay_ms(1000);
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}

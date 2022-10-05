/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"

void atraso(){
	int atraso = 1000000;
	while(atraso) {--atraso;}
}

void piscarLedsAlternado(){

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	while(1){

		GPIOA->ODR |= (1 << 6);
		GPIOA->ODR &= ~(1 << 7);
		atraso();

		GPIOA->ODR |= (1 << 7);
		GPIOA->ODR &= ~(1 << 6);
		atraso();
	}

}

void apertarBotaoEAcender(){

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);

	while (1){
		uint32_t entrada = GPIOE->IDR;
		if (entrada & (1 << 4)){
			GPIOA->ODR |= (1 << 7);
		} else {
			GPIOA->ODR &= ~(1 << 7);
		}
		if (entrada & (1 << 3)){
			GPIOA->ODR |= (1 << 6);
		} else {
			GPIOA->ODR &= ~(1 << 6);
	}
}


void apertaUmAcendeSempreApertaOutroApaga(){
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);

	while (1){
		uint32_t entrada = GPIOE->IDR;
		if (entrada & (1 << 3)){
			GPIOA->ODR |= (1 << 7);
			GPIOA->ODR |= (1 << 6);
		} else {
			while (1){
				uint32_t entrada2 = GPIOE->IDR;
				if (entrada2 & (1 << 4)){
					GPIOA->ODR &= ~(1 << 7);
					GPIOA->ODR &= ~(1 << 6);
				} else {
					GPIOA->ODR |= (1 << 7);
					GPIOA->ODR |= (1 << 6);
					break;
				}

			}
		}
	}
}


int main(void)
{

	for(;;);
}

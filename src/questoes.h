/*
 * questoes.h
 *
 *  Created on: 21 de out de 2022
 *      Author: liedson
 */

#ifndef QUESTOES_H
#define QUESTOES_H

#include "Utility.h"
#include "stm32f4xx.h"

#define PINO3 !(GPIOE->IDR & (1<<3))
#define PINO4 !(GPIOE->IDR & (1<<4))
#define LED1_ON (GPIOA->ODR &= ~(1<<6))
#define LED1_OFF (GPIOA->ODR |= (1<<6))
#define LED2_ON (GPIOA->ODR &= ~(1<<7))
#define LED2_OFF (GPIOA->ODR |= (1<<7))


void questao1(){
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);

	while(1){
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(250);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(250);
	}
}

void questao2(){
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);

	while(1){
		Delay_ms(1900);
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(100);
		GPIOA->ODR |= (1 << 6);

	}
}

void questao3(){
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);

	while(1){
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA->ODR |= (1 << 6);

		Delay_ms(500);

		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(100);
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(500);

	}
}

void questao4(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	int qntd = 0;
	while(1){

		qntd += 1;

		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA->ODR |= (1 << 6);

		int quantidade = 1000-(100*qntd);
		if (quantidade > 0){
			Delay_ms(quantidade);
		} else {
			qntd = 0;
			continue;
		}
	}
}

void questao5(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1 << 2;
	GPIOC->MODER |= (0b01 << 22);

	while(1){
		GPIOC->ODR |= (1<<11);
		Delay_ms(50);
		GPIOC->ODR &= ~(1<<11);
		Delay_ms(50);
		GPIOC->ODR |= (1<<11);
		Delay_ms(50);
		GPIOC->ODR &= ~(1<<11);
		Delay_ms(50);
		GPIOC->ODR |= (1<<11);
		Delay_ms(50);
		GPIOC->ODR &= ~(1<<11);
		Delay_ms(50);
		GPIOC->ODR |= (1<<11);
		Delay_ms(50);
		GPIOC->ODR &= ~(1<<11);
		Delay_ms(600);


	}
}

void questao6(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	while(1){
		LED2_ON;
		Delay_ms(1);

		LED2_OFF;
		Delay_ms(9);

		LED1_ON;
		Delay_ms(9);

		LED1_OFF;
		Delay_ms(1);
	}
}

void questao7(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);

	while(1){

		for(int tempo = 0;tempo < 9000; tempo+=100){
			LED1_ON;
			Delay_us(tempo);
			LED1_OFF;
			Delay_us(9000 - tempo);
		}

		for(int tempo = 0;tempo < 9000; tempo+=100){
			LED1_ON;
			Delay_us(9000 - tempo);
			LED1_OFF;
			Delay_us(tempo);
		}
	}
	Delay_ms(250);
}

void questao8(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	while(1){

		LED1_ON;
		LED2_OFF;
		Delay_ms(250);

		LED2_ON;
		LED1_OFF;
		Delay_ms(250);
	}
}

void questao9(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	int pino6 = 0;
	int pino7 = 0;

	while(1){

		Delay_ms(1000);

		if (pino6 == 0){
			GPIOA->ODR &= ~(1 << 6);
			pino6 = 1;
			continue;
		} else {
			if(pino7 == 0){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR &= ~(1 << 7);
				pino6 = 0;
				pino7 = 1;
				continue;
			} else {
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR |= (1 << 7);
				pino6 = 0;
				pino7 = 0;
				continue;
			}
		}
	}
}

void questao10(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);

	while(1){

		for(int tempo = 0;tempo < 9000; tempo+=100){
			LED1_ON;
			LED2_OFF;
			Delay_us(tempo);
			LED2_ON;
			LED1_OFF;
			Delay_us(9000 - tempo);

		}

		for(int tempo2 = 9000;tempo2 > 0; tempo2-=100){
			LED2_ON;
			LED1_OFF;
			Delay_us(9000 - tempo2);
			LED1_ON;
			LED2_OFF;
			Delay_us(tempo2);
		}
	}
}

void questao12(){

	RCC->AHB1ENR |= 1;

	GPIOA->MODER |= (0b01 << 2);
	GPIOA->MODER |= (0b01 << 4);
	GPIOA->MODER |= (0b01 << 6);
	GPIOA->MODER |= (0b01 << 8);
	GPIOA->MODER |= (0b01 << 10);
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);
	GPIOA->MODER |= (0b01 << 16);

	while(1){

		for(int i = 1; i < 9;i++){

			GPIOA->ODR |= (1 << i);
			Delay_ms(250);
			GPIOA->ODR &= ~(1 << i);
			Delay_ms(250);

		}

		for(int i = 8; i > 0;i--){

			GPIOA->ODR |= (1 << i);
			Delay_ms(250);
			GPIOA->ODR &= ~(1 << i);
			Delay_ms(250);

		}

	}

}

void questao13(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= (1 << 1);

	GPIOA->MODER |= (0b01 << 8); //RED
	GPIOA->MODER |= (0b01 << 10); //YELLOW
	GPIOA->MODER |= (0b01 << 12); //GREEN

	GPIOB->MODER |= (0b01 << 8); //RED
	GPIOB->MODER |= (0b01 << 10); //YELLOW
	GPIOB->MODER |= (0b01 << 12); //GREEN

	while(1){

		GPIOA->ODR |= (0b01 << 6);
		GPIOB->ODR |= (0b01 << 4);

		Delay_ms(500);

		GPIOA->ODR &= ~(0b11 << 6);
		GPIOA->ODR |= (0b01 << 5);

		Delay_ms(500);

		GPIOA->ODR &= ~(0b11 << 5);
		GPIOA->ODR |= (0b01 << 4);
		GPIOB->ODR |= (0b01 << 6);

		Delay_ms(500);

		GPIOB->ODR &= ~(0b11 << 6);
		GPIOB->ODR |= (0b01 << 5);

		Delay_ms(500);

		GPIOB->ODR &= ~(0b11 << 5);
		GPIOB->ODR |= (0b01 << 4);
		GPIOA->ODR &= ~(0b11 << 4);
		GPIOA->ODR |= (0b01 << 6);

	}
}

void questao21(){

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 12);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	while(1) {
		uint32_t entrada = GPIOE->IDR;
		if (entrada & (1 << 4)){
			GPIOA->ODR |= (1 << 6);
		} else {
			GPIOA->ODR &= ~(1 << 6);
		}
	}
}

void questao22(){

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 8);
	GPIOE->PUPDR |= (0b01 << 6);


	while(1) {
		uint32_t entrada = GPIOE->IDR;
		if (entrada & (1 << 4)){
			GPIOA->ODR |= (1 << 6);
		} else {
			GPIOA->ODR &= ~(1 << 6);
		}

		if (entrada & (1 << 3)){
			GPIOA->ODR |= (1 << 7);
		} else {
			GPIOA->ODR &= ~(1 << 7);
		}
	}
}

void questao23(){

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 12);

	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	while(1){
		uint32_t entrada = GPIOE->IDR;
		if (entrada & (1 << 4)){
			GPIOA->ODR |= (0b01 << 6);
		} else {
			while (1){
				uint32_t entrada2 = GPIOE->IDR;
				if (entrada2 & (1 << 4)){
					GPIOA->ODR &= ~(0b11 << 6);
				} else {
					GPIOA->ODR |= (0b01 << 6);
					break;
				}
			}
		}
	}
}

void questao24(){
	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

	//configurando PA6 como saída (o pino PA6 tem um LED conectado)
	GPIOA->MODER |= (0b01 << 12);
	//configurando PA7 como saída (o pino PA6 tem um LED conectado)
	GPIOA->MODER |= (0b01 << 14);

	//Configurando o pino PE3 como entrada
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
	//Configurando o pino PE4 como entrada
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
	int verificarPin = 0;
	while(1)
	{
		LED1_OFF;
		LED2_OFF;
		if (PINO4 && !PINO3){
			verificarPin = 1;
		}
		if (!PINO4 && PINO3){
			verificarPin = 0;
		}
		if ((PINO3 && PINO4) && verificarPin == 1){
			LED1_ON;
			LED2_ON;
		}
	}
}


#endif

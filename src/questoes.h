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

void questao11(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0b01 << 0);
	GPIOA->MODER |= (0b01 << 2);
	GPIOA->MODER |= (0b01 << 4);
	GPIOA->MODER |= (0b01 << 6);
	GPIOA->MODER |= (0b01 << 8);
	GPIOA->MODER |= (0b01 << 10);
	GPIOA->MODER |= (0b01 << 12);
	GPIOA->MODER |= (0b01 << 14);


	while(1){
		for (int i = 0; i < 256; i++){

			GPIOA->ODR = i;
			Delay_ms(250);
		}
	}

}
void questao12(){

	Configure_Clock();
	Delay_Start();

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
		}

		Delay_ms(500);

		for(int i = 8; i > 0;i--){
			GPIOA->ODR |= (1 << i);
			Delay_ms(250);
			GPIOA->ODR &= ~(1 << i);

		}

	}

}

void questao13(){

	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= (1 << 1);

	GPIOA->MODER |= (0b01 << 2); //RED
	GPIOA->MODER |= (0b01 << 4); //YELLOW
	GPIOA->MODER |= (0b01 << 6); //GREEN

	GPIOA->MODER |= (0b01 << 8); //RED
	GPIOA->MODER |= (0b01 << 10); //YELLOW
	GPIOA->MODER |= (0b01 << 12); //GREEN

	while(1){

		GPIOA->ODR |= (1 << 4);
		GPIOA->ODR |= (1 << 3);

		Delay_ms(500);

		GPIOA->ODR &= ~(1 << 3);
		GPIOA->ODR |= (1 << 2);

		Delay_ms(500);

		GPIOA->ODR &= ~(1 << 2);
		GPIOA->ODR &= ~(1 << 4);
		GPIOA->ODR |= (1 << 1);
		GPIOA->ODR |= (1 << 6);

		Delay_ms(500);

		GPIOA->ODR &= ~(1 << 6);
		GPIOA->ODR |= (1 << 5);

		Delay_ms(500);

		GPIOA->ODR &= ~(1 << 1);
		GPIOA->ODR &= ~(1 << 5);
		GPIOA->ODR |= (1 << 4);
		GPIOA->ODR |= (1 << 3);


	}
}

void questao14(){

	Configure_Clock();
	Delay_Start();
	RCC->AHB1ENR |= 1;

	GPIOA->MODER |= (0b01 << 0);
	GPIOA->MODER |= (0b01 << 2);
	GPIOA->MODER |= (0b01 << 4);
	GPIOA->MODER |= (0b01 << 6);
	GPIOA->MODER |= (0b01 << 8);
	GPIOA->MODER |= (0b01 << 10);
	GPIOA->MODER |= (0b01 << 12);

	const uint8_t mask[16]={ 0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01101111, //9
		0b01110111, //A
		0b01111100, //B
		0b00111001, //C
		0b01011110, //D
		0b01111001, //E
		0b01110001}; //F

	while(1){

		for (int i = 0; i < 16; i++){
			GPIOA->ODR = mask[i];
			Delay_ms(500);
		}

		for (int i = 14; i >= 0; i--){
			GPIOA->ODR = mask[i];
			Delay_ms(500);
		}

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

void questao17(){
	Configure_Clock();
	Delay_Start();
	RCC->AHB1ENR |= 1;

	GPIOA->MODER |= (0b01 << 2);

	while (1){
		for (int i = 600; i < 2400; i++){
			GPIOA->ODR |= (1 << 1);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 1);
			Delay_us(20000 - i);
		}

		for (int i = 2400; i >= 600; i--){
			GPIOA->ODR |= (1 << 1);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 1);
			Delay_us(20000 - i);
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

	int ligado = 0;
	LED1_OFF;
	Configure_Clock();
	Delay_Start();

	while(1){


		if (PINO4 && !ligado){
			ligado = 1;
			LED1_ON;
			Delay_ms(250);
		}
		if (PINO4 && ligado){
			ligado = 0;
			LED1_OFF;
			Delay_ms(250);
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

void questao25(){
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
	GPIOE->PUPDR |= (0b01 << 8);

	Configure_Clock();
	Delay_Start();

	int verificarPin = 0;
	int pode = 1;

	while(1){
		LED1_OFF;
		LED2_OFF;
		if (PINO4 && !PINO3 && pode){
			for(int i = 0; i < 10; i++){
				if (PINO3){
					verificarPin = 1;
					break;
				} else {
					Delay_ms(100);
				}
			}
			if (!verificarPin){
				pode = 0;
			}
		}
		if (!PINO4 && PINO3){
			verificarPin = 0;

		pode = 1;

		}
		if ((PINO3 && PINO4) && verificarPin == 1){
			LED1_ON;
			LED2_ON;
			continue;
		}
	}

}

void questao26(){
	Configure_Clock();
	Delay_Start();

	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;

	GPIOA->MODER |= (0b01 << 2);

	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	int i = 0;

	while(1){
		if (PINO4){
			if (PINO3) break;
			if (i == 2400) break;
			for (i; i < 2400; i++){
				GPIOA->ODR |= (1 << 1);
				Delay_us(i);
				GPIOA->ODR &= ~(1 << 1);
				Delay_us(20000 - i);
			}
			break;
		}
		if (PINO3){
			if(PINO4) break;
			if(i == 600) break;
			for (i; i >= 600; i--){
				GPIOA->ODR |= (1 << 1);
				Delay_us(i);
				GPIOA->ODR &= ~(1 << 1);
				Delay_us(20000 - i);
			}
			break;
		}
	}

}


#endif

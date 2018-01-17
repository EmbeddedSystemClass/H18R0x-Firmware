/*
    BitzOS (BOS) V0.0.0 - Copyright (C) 2017 Hexabitz
    All rights reserved

    File Name     : H18R0.c
    Description   : Source code for module H18R0.
										Brushed DC motor drive (TI DRV8837DSGT)
		
		Required MCU resources : 
		
			>> USARTs 1,2,3,5 for module ports.
			>> TIM1_CH1 and TIM1_CH1N for DRV8837DSGT PWM1 and PWM2
			>> GPIOB 15 for Motor Sleep
			>> GPIOB 5 for Motor Direction
			>> ADC_IN8 for Motor Speed
			
*/
	
/* Includes ------------------------------------------------------------------*/
#include "BOS.h"


/* Define UART variables */
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart5;


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/	


/* Create CLI commands --------------------------------------------------------*/


/* -----------------------------------------------------------------------
	|												 Private Functions	 														|
   ----------------------------------------------------------------------- 
*/

/* --- H18R0 module initialization. 
*/
void Module_Init(void)
{	
	/* Array ports */
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_USART5_UART_Init();
	

	
}

/*-----------------------------------------------------------*/

/* --- H18R0 message processing task. 
*/
Module_Status Module_MessagingTask(uint16_t code, uint8_t port, uint8_t src, uint8_t dst)
{
	Module_Status result = H18R0_OK;
	
	switch (code)
	{

		default:
			result = H18R0_ERR_UnknownMessage;
			break;
	}			

	return result;	
}

/*-----------------------------------------------------------*/

/* --- Register this module CLI Commands 
*/
void RegisterModuleCLICommands(void)
{

}

/*-----------------------------------------------------------*/

/* --- Get the port for a given UART. 
*/
uint8_t GetPort(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART5)
			return P1;
	else if (huart->Instance == USART2)
			return P2;
	else if (huart->Instance == USART3)
			return P3;
	else if (huart->Instance == USART1)
			return P4;
		
	return 0;
}

/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   ----------------------------------------------------------------------- 
*/



/* -----------------------------------------------------------------------
	|															Commands																 	|
   ----------------------------------------------------------------------- 
*/


/*-----------------------------------------------------------*/

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/

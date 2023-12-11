/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Lenovo
 */

#include <util/delay.h>.
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "../MCAL/DIO-DRIVER/DIO_MCAL_Interface.h"
#include "../MCAL/GIE-DRIVER/GIE_MCAL_Interface.h"
#include "../MCAL/EXTI-DRIVER/EXTI_MCAL_Interface.h"
#include "../MCAL/ADC-DRIVER/ADC_MCAL_Interface.h"
#include "../MCAL/TMR-DRIVER/TMR_MCAL_Interface.h"
#include "../MCAL/USART-DRIVER/USART_MCAL_Interface.h"
#include "../MCAL/SPI-DRIVER/SPI_MCAL_Interface.h"

#include "../HAL/LCD-DRIVER/LCD_HAL_Interface.h"
#include "../HAL/SEGMENT_DRIVER/SEG_HAL_Interface.h"
#include "../HAL/KPD_DRIVER/KPD_HAL_Interface.h"
#include "../HAL/LM_SENSOR-DIRVER/LM_HAL_Interface.h"
#include "../HAL/STEPPER_MOTOR-DRIVER/STEP_HAL_Interface.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

int main(void) {

	SPI_Init();
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_INPUT);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
	u8 button1, button2;
	while (1) {
		button1 = DIO_GetPinValue(DIO_PORTA, DIO_PIN0);
		button2 = DIO_GetPinValue(DIO_PORTA, DIO_PIN1);
		if (button1 == 0) {
			//slave 1
			DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
			DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
			SPI_Transieve('0');
		}
		if (button1 == 1) {
			//slave 1
			DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
			DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
			SPI_Transieve('1');
		}
		if (button2 == 0) {
			//slave 2
			DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_HIGH);
			DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			SPI_Transieve('0');
		}
		if (button2 == 1) {
			//slave 2
			DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_HIGH);
			DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
			SPI_Transieve('1');
		}
		if(button1 == 0 && button2 ==0 )
		{
			DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
						DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
						SPI_Transieve('0');
		}
	}

}

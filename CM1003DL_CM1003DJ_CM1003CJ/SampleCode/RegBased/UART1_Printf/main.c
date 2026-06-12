/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2025 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "numicro_8051.h"

#define     UART1_P16_P02

/**
 * @brief       Main loop
 * @param       None
 * @return      None
 * @details     UART4 printf send data.
 */
void main (void) 
{
/* Modify HIRC to 24MHz for UART baud rate deviation not over 1%*/
    MODIFY_HIRC(HIRC_24);
	
#ifdef   UART1_P16_P02            /*  if define UART1_P16_P02 initial GPIO and MFP */
    P16_QUASI_MODE;
    P02_INPUT_MODE;
    ENABLE_UART1_TXD_P16;
    ENABLE_UART1_RXD_P02;
#elif defined  UART1_P36_P37      /*  if define UART1_P36_P37 initial GPIO and MFP */
    P36_QUASI_MODE;
    P37_INPUT_MODE;
    ENABLE_UART1_TXD_P36;
    ENABLE_UART1_RXD_P37;
#elif defined  UART1_P10_P00      /*  if define UART1_P10_P00 initial GPIO and MFP */
    P10_QUASI_MODE;
    P00_INPUT_MODE;
    ENABLE_UART1_TXD_P10;
    ENABLE_UART1_RXD_P00;
#endif

    UART_Open(24000000,UART1_Timer3,115200);

    while(1)
    {
      ENABLE_UART1_PRINTF;
      printf("\n hello world !!!");
      DISABLE_UART1_PRINTF;
      Timer0_Delay(24000000,300,1000);
    }
  
}
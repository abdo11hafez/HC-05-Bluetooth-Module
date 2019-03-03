#include "UART.h"
#include "GPIO.h"
#include "stdint.h"
#include "string.h"

void UART_Send_String(int UART_ID ,char* str);

/**
 * Send a string through the (HC-05) bluetooth module using TIVA-C Launchpad
 * working on default baud rate (9600)
 * the HC-05 Rx connected to PB1
 *           Tx connected to PB0
 */
int main(void)
{
    GPIO_Init();
    GPIO_SetAlternFuntion(0, 1);
    UART_Init();
    char * msg1="Start Receiving ..........\n";


    while(1)
    {
        UART_Send_String(0 ,msg1);
    }
 }

void UART_Send_String(int UART_ID ,char* str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
        UART_Send(UART_ID,str[i]);
}

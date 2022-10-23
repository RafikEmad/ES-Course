#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:Rafik";
unsigned char const string_buffer2[100] = "learn-in-depth:Rafik";

void main(void)
{
	Uart_Send_String (string_buffer);
}
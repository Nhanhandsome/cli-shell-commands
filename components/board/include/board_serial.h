/*
 * board_serial.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Admin
 */

#ifndef COMPONENTS_BOARD_INCLUDE_BOARD_SERIAL_H_
#define COMPONENTS_BOARD_INCLUDE_BOARD_SERIAL_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

typedef struct{
	int tx;
	int rx;
	int rst;
	int cts;
}uart_hw_pin_t;

typedef struct Board_Uart_t Board_Uart;

struct Board_Uart_t{
	uart_config_t *config;
	uart_port_t port;
	uart_hw_pin_t *config_pin;
	size_t buff_size;
};

int boart_uart_init(Board_Uart *uart);
int boart_uart_send(Board_Uart *uart,uint8_t* bytes,size_t len);
int boart_uart_recv(Board_Uart *uart,uint8_t* bytes,size_t len);
int boart_uart_available(Board_Uart *uart);

extern Board_Uart uart0;

#endif /* COMPONENTS_BOARD_INCLUDE_BOARD_SERIAL_H_ */

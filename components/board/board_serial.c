/*
 * board_serial.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Admin
 */


#include "board_serial.h"


uart_config_t uart0_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
        .source_clk = UART_SCLK_APB,
};

uart_hw_pin_t uart0_pin = {
		.tx = 1,
		.rx = 3,
		.cts = -1,
		.rst = -1
};

Board_Uart uart0 = {.config = &uart0_config,.config_pin = &uart0_pin,.port = 1,.buff_size = 512};

int boart_uart_init(Board_Uart *uart){

	if(uart->config == NULL || uart->config_pin == NULL ){
		return -1;
	}

	uart_driver_install(uart->port, uart->buff_size,0,0, NULL,0);
	uart_param_config(uart->port, uart->config);
	uart_set_pin(uart->port,uart->config_pin->tx, uart->config_pin->rx, uart->config_pin->rst, uart->config_pin->cts);


	return 0;
}

int boart_uart_send(Board_Uart *uart,uint8_t* bytes,size_t len){
	return uart_write_bytes(uart->port, bytes,len);
}
int boart_uart_recv(Board_Uart *uart,uint8_t* bytes,size_t len){
	return uart_read_bytes(uart->port, bytes,len,(TickType_t)1000/portTICK_PERIOD_MS);
}
int boart_uart_available(Board_Uart *uart){
	size_t len = 0;
	if(uart_get_buffered_data_len(uart->port,&len) == ESP_OK){
		return len;
	}
	return -1;
}

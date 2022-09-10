#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <board_serial.h>
#include <cli_shell.h>
#include <FreeRTOSConfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


int console_putc(char c) {
	//boart_uart_send(c);
	boart_uart_send(&uart0, (uint8_t*) &c, 1);
	return 1;
}

char console_getc(void) {
	uint8_t cr = -1;
	boart_uart_recv(&uart0, (uint8_t*) &cr, 1);
	return (char) cr;
}

int console_available() {
	return boart_uart_available(&uart0);
}

void cli_task(void *arg);

xTaskHandle cli_handle;

void app_main(void) {

	xTaskCreate(cli_task,"cli shell",1024*4,NULL,1, &cli_handle);


}
void cli_task(void *arg){
	boart_uart_init(&uart0);

	sCliShellImpl shell_impl = { .send_char = console_putc, };
	cli_shell_boot(&shell_impl);
	char c;
	while (true) {
		if (console_available() > 0) {
			c = console_getc();
			cli_shell_receive_char(c);
		}
	}
}

#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "clk_user.h"
#include "usart_user.h"
#include "dma_tx.h"
#include "dma_rx.h"

char c[] = "t\r\n";
char message[sizeof(c)];

int main(void) {
	clk_user_init();
	usart2_init();

	while (1) {
		int i;
		int size = strlen(c);

		for (i = 0; i < size; i++) {
			message[i] = c[i];
		}

		dma1_tx((uint32_t) message, size);
	}

}


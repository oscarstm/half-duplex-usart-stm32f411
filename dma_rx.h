/*
 * dma_rx.h
 *
 *  Created on: Mar 10, 2026
 *      Author: oscar
 */

#ifndef DMA_RX_H_
#define DMA_RX_H_

#include "stm32f4xx.h"
#include "usart_user.h"

void dma1_rx(uint32_t rx_buffer, uint32_t rx_length);

#endif /* DMA_RX_H_ */

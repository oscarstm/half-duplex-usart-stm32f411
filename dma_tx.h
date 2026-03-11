/*
 * dma_tx.h
 *
 *  Created on: Mar 10, 2026
 *      Author: oscar
 */

#ifndef DMA_TX_H_
#define DMA_TX_H_

#include "stm32f4xx.h"
#include "usart_user.h"

void dma1_tx(uint32_t tx_buffer, uint32_t tx_length);

#endif /* DMA_TX_H_ */

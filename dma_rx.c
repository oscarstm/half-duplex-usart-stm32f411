/*
 * dma_rx.c
 *
 *  Created on: Mar 10, 2026
 *      Author: oscar
 */

#include "dma_rx.h"

void dma1_rx(uint32_t rx_buffer, uint32_t rx_length) {
	DMA1_Stream7->CR &= ~DMA_SxCR_EN;

	while (DMA1_Stream7->CR & DMA_SxCR_EN) {
		//
	}

	DMA1_Stream7->PAR = (uint32_t) &(USART2->DR);
	DMA1_Stream7->M0AR = rx_buffer;
	DMA1_Stream7->NDTR = rx_length;

	// DMA settings
	DMA1_Stream7->CR &= ~DMA_SxCR_CHSEL_0;
	DMA1_Stream7->CR |= DMA_SxCR_CHSEL_1;
	DMA1_Stream7->CR |= DMA_SxCR_CHSEL_2;
	DMA1_Stream7->CR |= DMA_SxCR_PL_0;
	DMA1_Stream7->CR |= DMA_SxCR_PL_1;
	DMA1_Stream7->CR &= ~DMA_SxCR_MSIZE_0;
	DMA1_Stream7->CR &= ~DMA_SxCR_MSIZE_1;
	DMA1_Stream7->CR &= ~DMA_SxCR_PSIZE_0;
	DMA1_Stream7->CR &= ~DMA_SxCR_PSIZE_1;
	DMA1_Stream7->CR &= ~DMA_SxCR_MINC;
	DMA1_Stream7->CR &= ~DMA_SxCR_DIR_0;
	DMA1_Stream7->CR &= ~DMA_SxCR_DIR_1;
	DMA1_Stream7->CR &= ~DMA_SxCR_TCIE;
	DMA1_Stream7->CR |= DMA_SxCR_EN;

	NVIC_EnableIRQ(DMA1_Stream7_IRQn);
}

void DMA1_Stream7_IRQHandler(void) {
	if (DMA1->HISR & DMA_HISR_TCIF7) {
		DMA1->HIFCR &= ~DMA_HIFCR_CTCIF7;
	}
}

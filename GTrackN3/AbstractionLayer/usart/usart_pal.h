#ifndef __USART_PCL_H
#define __USART_PCL_H

#include <stdbool.h>
#include "stm32f0xx_hal.h"
#include "usart/usart_hcl.h"

/**
 * @brief Reads a string from the UART until a specified character is encountered.
 *
 * This function reads characters from the UART until the specified termination character is encountered
 * or the receive buffer is full. The received characters are stored in the destination buffer.
 *
 * @param huart Pointer to the UART handle.
 * @param terminatedChar The termination character to look for.
 * @param destination Pointer to the destination buffer to store the received string.
 * @return True if the termination character is encountered, false otherwise.
 */
bool PAL_UART_ReadStringUntil(UART_HandleTypeDef* huart, char terminatedChar, char* destination);

/**
 * @brief Sends a null-terminated string through the UART.
 *
 * This function sends each character of the null-terminated string through the UART.
 *
 * @param huart Pointer to the UART handle.
 * @param str Pointer to the null-terminated string to be sent.
 */
void PAL_UART_OutString(UART_HandleTypeDef* huart, const char* str);

/**
 * @brief Sends an unsigned number through the UART.
 *
 * This function sends an unsigned number through the UART as a sequence of characters.
 *
 * @param huart Pointer to the UART handle.
 * @param number The unsigned number to be sent.
 */
void PAL_UART_OutNumber(UART_HandleTypeDef* huart, uint32_t number);

/**
 * @brief Sends a signed number through the UART.
 *
 * This function sends a signed number through the UART as a sequence of characters.
 *
 * @param huart Pointer to the UART handle.
 * @param number The signed number to be sent.
 */
void PAL_UART_OutNumber_Signed(UART_HandleTypeDef* huart, int32_t number);

/**
 * @brief Sends an 8-bit binary data through the UART.
 *
 * This function sends an 8-bit binary data through the UART as a sequence of characters representing the binary value.
 *
 * @param huart Pointer to the UART handle.
 * @param data The 8-bit binary data to be sent.
 */
void PAL_UART_OutBinary_8BIT(UART_HandleTypeDef* huart, uint8_t data);

/**
 * @brief Sends a 16-bit binary data through the UART.
 *
 * This function sends a 16-bit binary data through the UART as a sequence of characters representing the binary value.
 *
 * @param huart Pointer to the UART handle.
 * @param data The 16-bit binary data to be sent.
 */
void PAL_UART_OutBinary_16BIT(UART_HandleTypeDef* huart, uint16_t data);

/**
 * @brief Flushes the transmit and receive buffers of two UARTs.
 *
 * This function flushes the transmit and receive buffers of two UARTs by reading and discarding any available data.
 *
 * @param huart_transmit Pointer to the UART handle of the transmitter UART.
 * @param huart_receive Pointer to the UART handle of the receiver UART.
 */
void PAL_UART_FlushToUART_Char(UART_HandleTypeDef* huart_transmit, UART_HandleTypeDef* huart_receive);

/**
 * @brief Flushes the transmit and receive buffers of two UARTs.
 *
 * This function flushes the transmit and receive buffers of two UARTs by reading and discarding any available data.
 *
 * @param huart_transmit Pointer to the UART handle of the transmitter UART.
 * @param huart_receive Pointer to the UART handle of the receiver UART.
 */
void PAL_UART_FlushToUART_String(UART_HandleTypeDef* huart_transmit, UART_HandleTypeDef* huart_receive);

#endif
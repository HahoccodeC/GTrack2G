#include "usart_pal.h"

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
bool PAL_UART_ReadStringUntil(UART_HandleTypeDef *huart, char terminatedChar, char *destination) {
    static bool isFirstInit = true;
    static char* p_Destination = NULL;
    
    if(isFirstInit) p_Destination = destination;
    isFirstInit = false;
    bool isDone = false;
    if (HCL_UART_IsAvailable(huart)) {
      char data = HCL_UART_InChar(huart);
      while (data != terminatedChar) {
        *p_Destination++ = data;
        if (!HCL_UART_IsAvailable(huart)) break;
        data = HCL_UART_InChar(huart);
      }
      if(data == terminatedChar) isDone = true;
      if (isDone) {
        *p_Destination = '\0';
        p_Destination = destination;
      }
    }

    return isDone;
}

/**
 * @brief Sends a null-terminated string through the UART.
 *
 * This function sends each character of the null-terminated string through the UART.
 *
 * @param huart Pointer to the UART handle.
 * @param str Pointer to the null-terminated string to be sent.
 */
void PAL_UART_OutString(UART_HandleTypeDef* huart, const char* str) {
    while (*str != '\0')
        HCL_UART_OutChar(huart, (uint8_t)*str++);
}

/**
 * @brief Sends an unsigned number through the UART.
 *
 * This function sends an unsigned number through the UART as a sequence of characters.
 *
 * @param huart Pointer to the UART handle.
 * @param number The unsigned number to be sent.
 */
void PAL_UART_OutNumber(UART_HandleTypeDef* huart, uint32_t number) {
    if(number == 0) {
        HCL_UART_OutChar(huart, '0');
        return;
    }

	char number_str[10];
	uint8_t index = 0;
    while (number != 0) {
        number_str[index++] = number % 10 + '0';
        number /= 10;
    }

    while(index--) HCL_UART_OutChar(huart, number_str[index]);
}

/**
 * @brief Sends a signed number through the UART.
 *
 * This function sends a signed number through the UART as a sequence of characters.
 *
 * @param huart Pointer to the UART handle.
 * @param number The signed number to be sent.
 */
void PAL_UART_OutNumber_Signed(UART_HandleTypeDef* huart, int32_t number) {
    if(number == 0) {
		HCL_UART_OutChar(huart, '0');
		return;
	}

    bool isSigned = (number < 0);
	if(isSigned) number = -number;

	char number_str[10];
	uint8_t index = 0;
    while (number != 0) {
        number_str[index++] = number % 10 + '0';
        number /= 10;
    }
	
    if(isSigned) HCL_UART_OutChar(huart, '-');
	while(index--) HCL_UART_OutChar(huart, number_str[index]);
}

/**
 * @brief Sends an 8-bit binary data through the UART.
 *
 * This function sends an 8-bit binary data through the UART as a sequence of characters representing the binary value.
 *
 * @param huart Pointer to the UART handle.
 * @param data The 8-bit binary data to be sent.
 */
void PAL_UART_OutBinary_8BIT(UART_HandleTypeDef* huart, uint8_t data) {
    uint8_t bit;
	uint8_t i = 8;
    while(i--) {
        bit = (data & (1 << i)) ? 1 : 0;
        HCL_UART_OutChar(huart, bit + '0');
    }
}

/**
 * @brief Sends a 16-bit binary data through the UART.
 *
 * This function sends a 16-bit binary data through the UART as a sequence of characters representing the binary value.
 *
 * @param huart Pointer to the UART handle.
 * @param data The 16-bit binary data to be sent.
 */
void PAL_UART_OutBinary_16BIT(UART_HandleTypeDef* huart, uint16_t data) {
    uint8_t bit;
	uint8_t i = 16;
    while(i--) {
        bit = (data & (1 << i)) ? 1: 0;
        HCL_UART_OutChar(huart, bit + '0');
    }
}

/**
 * @brief Flushes the transmit buffer of one UART to the receive buffer of another UART.
 *
 * This function reads characters from the transmit buffer of one UART and writes them to the receive buffer of another UART.
 *
 * @param huart_transmit Pointer to the UART handle of the transmitting UART.
 * @param huart_receive Pointer to the UART handle of the receiving UART.
 */
void PAL_UART_FlushToUART_Char(UART_HandleTypeDef* huart_transmit, UART_HandleTypeDef* huart_receive) {
    if (HCL_UART_IsAvailable(huart_transmit)) {
        char data = HCL_UART_InChar(huart_transmit);
        HCL_UART_OutChar(huart_receive, data);
    }
}

/**
 * @brief Flushes the transmit buffer of one UART to the receive buffer of another UART.
 *
 * This function continuously flushes the transmit buffer of one UART to the receive buffer of another UART until the transmit buffer is empty.
 *
 * @param huart_transmit Pointer to the UART handle of the transmitting UART.
 * @param huart_receive Pointer to the UART handle of the receiving UART.
 */
void PAL_UART_FlushToUART_String(UART_HandleTypeDef* huart_transmit, UART_HandleTypeDef* huart_receive) {
    while (HCL_UART_IsAvailable(huart_transmit)) {
        PAL_UART_FlushToUART_Char(huart_transmit, huart_receive);
    }
}
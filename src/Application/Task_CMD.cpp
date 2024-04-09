/**
 ******************************************************************************
 * @file    task_CMD.cpp
 * @author  –Ï’‹??
 * @brief   √¸¡Ó??
 * @verbatim
 * @endverbatim
 ******************************************************************************
 */
#include "Include.h"

void Task_CMD(void)
{
    digitalWrite(BOARD_LED, HIGH);
    while (1)
    {
        if (CMDstate == CMD_ON)
        {
            CMDClear();
            while (CMDstate == CMD_ON)
            {
                CMDInput(USART_LOG);
                CMDlanguage(CMD_Stack,USART_LOG);
                CMDClear();
                vTaskDelay(20 / portTICK_PERIOD_MS);
            }
        }
        else if (CMDstate == CMD_OFF)
        {
            vTaskDelete(NULL);
        }
    }
}

void CMDClear()
{
    for (size_t i = 0; i < CMD_STK; i++)
    {
        CMD_Stack[i] = '\0';
    }
}

void CMDReply()
{
    UART_SendChars(USART_LOG, CMD_Stack);
}

void CMDW_ReplyInput(uint8_t USARTx, char *string, String reply)
{
    UART_SendString(USARTx, "Maid : ");
    UART_SendChars(USARTx, string);
    UART_SendString(USARTx, " : ");
    UART_SendString(USARTx, reply);
    UART_SendString(USARTx, " \n");
}

void CMDW_Chat(uint8_t USARTx, String string)
{
    UART_SendString(USARTx, "Maid : ");
    UART_SendString(USARTx, string);
    UART_SendString(USARTx, "\n");
}

void CMDW_Tip(uint8_t USARTx, char *string)
{
    UART_SendString(USARTx, "Maid : ");
    UART_SendChars(USARTx, string);
}

void CMDInput(uint8_t USARTx)
{
    UART_SendString(USARTx, ">>>");
    while (CMD_Stack[0] == '\0' || CMD_Stack[0] == 0xEE)
        vTaskDelay(50 / portTICK_PERIOD_MS);
    UART_SendString(USARTx, CMD_Stack);
    UART_SendString(USARTx, "\n");
}

void Open_Task_CMD(void)
{
    CMDstate = CMD_ON;
    taskENTER_CRITICAL();
    xTaskCreate((TaskFunction_t)Task_CMD,
                (const char *const)"Task_CMD",
                (uint16_t)256,
                (void *const)NULL,
                (UBaseType_t)0x10,
                (TaskHandle_t *)NULL);
    taskEXIT_CRITICAL();
}

void CMDLoad(char* input)
{
    uint16_t count = 0;
    while (input[count] != '\0' && count <CMD_STK-1-1)
    {
        CMD_Stack[count] = input[count];
        count++;
    }
    CMD_Stack[count] = '\0';
}
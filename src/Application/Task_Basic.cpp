#include "Include.h"
/**
 ******************************************************************************
 * @file    task_Basic.cpp
 * @author  徐哲�?
 * @brief   基�?�任务
 * @verbatim
 *         （需要一直运行的任务�?
 * @endverbatim
 ******************************************************************************
 */

void Task_State() // �?开关�?��?
{
    while (1)
    {
        if (BoardState == BOARD_SLEEP)
        {
            UART_SendString(USART_LOG, "BoardState : Uno_Sleep\n");
            while (BoardState == BOARD_SLEEP)
            {
                digitalWrite(LED_BOARD, LOW);
                vTaskDelay(50 / portTICK_PERIOD_MS);
            }
        }
        else if (BoardState == BOARD_WAKEUP)
        {
            UART_SendString(USART_LOG, "BoardState : Uno_Waking \n");
            while (BoardState == BOARD_WAKEUP)
            {
                if (CMDstate == CMD_OFF)
                {
                    digitalWrite(LED_BOARD, HIGH);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(LED_BOARD, LOW);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(LED_BOARD, HIGH);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(LED_BOARD, LOW);
                    vTaskDelay(850 / portTICK_PERIOD_MS);
                }
                else
                {
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                }
            }
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
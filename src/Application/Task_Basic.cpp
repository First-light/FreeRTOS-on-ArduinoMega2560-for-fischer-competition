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
        if (boardState == BOARD_SLEEP)
        {
            UART_SendString(USART_LOG, "boardState : Uno_Sleep\n");
            while (boardState == BOARD_SLEEP)
            {
                digitalWrite(BOARD_LED, LOW);
                vTaskDelay(50 / portTICK_PERIOD_MS);
            }
        }
        else if (boardState == BOARD_WAKEUP)
        {
            UART_SendString(USART_LOG, "boardState : Uno_Waking \n");
            while (boardState == BOARD_WAKEUP)
            {
                if (CMDstate == CMD_OFF)
                {
                    digitalWrite(BOARD_LED, HIGH);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(BOARD_LED, LOW);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(BOARD_LED, HIGH);
                    vTaskDelay(50 / portTICK_PERIOD_MS);
                    digitalWrite(BOARD_LED, LOW);
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
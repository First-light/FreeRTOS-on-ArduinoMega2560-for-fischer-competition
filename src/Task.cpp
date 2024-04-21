#include "Include.h"

void Task_Chassis()
{
    UART_SendString(USART_LOG, "Task_Chassis Ready\n");
    while (1)
    {
        //FIS_SendByte(1);
        vTaskDelay(25 / portTICK_PERIOD_MS); // ??100ms读一次串??
    }
}

void Task_Analyse()
{
    UART_SendString(USART_LOG, "Task_Analyse Ready\n");
    while (1)
    {

        vTaskDelay(25 / portTICK_PERIOD_MS); // ??100ms读一次串??
    }
}

void Task_Sensor()
{
    UART_SendString(USART_LOG, "Task_Sensor Ready\n");
    while (1)
    {

        vTaskDelay(25 / portTICK_PERIOD_MS); // ??100ms读一次串??
    }
}
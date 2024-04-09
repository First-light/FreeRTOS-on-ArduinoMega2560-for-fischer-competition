/**
  ******************************************************************************
  * @file    main.cpp
  * @author  徐哲�?
  * @brief   主函�?
  * @verbatim
  *         FreeRTOS基本框架
  *         �?持Arduino Uno，Mega等Arduino 系列�?
  *         最低可�?2KB RAM下运行，�?RAM过小�?能出现BUG
  *         基于vscode �? platformio 开发平�?
  *         最后一次修改于2023/9/3
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"
/******************************变量定义**********************************/
void Task_Chassis();
void Task_Analyse();
void Task_Sensor();

/******************************主函�?**********************************/
void Device_Init()
{
  Serial.begin(USART_BaudRate);
  pinMode(LED_BOARD,OUTPUT);
}

void setup() 
{
  Device_Init();
  UART_SendString(USART_LOG,"Device Ready\n");
  xTaskCreateStatic(  (TaskFunction_t     ) USARTS_IRQHandler,
                      (const char *const  ) "USART_IRQHandler",
                      (const uint32_t     ) USART_IRQHandler_STK,
                      (void *const        ) NULL,
                      (UBaseType_t        ) USART_IRQHandler_PRI,
                      (StackType_t *const ) USART_IRQHandlerStack,  
                      (StaticTask_t*const ) &USART_IRQHandler_TCB ); 

  xTaskCreateStatic((TaskFunction_t     ) Task_State,
                    (const char *const  ) "Task_State",
                    (const uint32_t     ) Task_State_STK,
                    (void *const        ) NULL,
                    (UBaseType_t        ) Task_State_PRI,
                    (StackType_t *const ) Task_StateStack,  
                    (StaticTask_t*const ) &Task_State_TCB ); 

  xTaskCreate(  (TaskFunction_t     ) Task_Chassis,
                (const char * const ) "Task_Chassis", 
                (uint16_t           ) 128,
                (void * const       ) NULL,
                (UBaseType_t        ) 0x10,
                (TaskHandle_t      *) NULL);  

  xTaskCreate(  (TaskFunction_t     ) Task_Analyse,
                (const char * const ) "Task_Analyse", 
                (uint16_t           ) 128,
                (void * const       ) NULL,
                (UBaseType_t        ) 0x10,
                (TaskHandle_t      *) NULL);         

  xTaskCreate(  (TaskFunction_t     ) Task_Sensor,
                (const char * const ) "Task_Sensor", 
                (uint16_t           ) 128,
                (void * const       ) NULL,
                (UBaseType_t        ) 0x10,
                (TaskHandle_t      *) NULL);                          

  vTaskStartScheduler();  
  UART_SendString(USART_LOG,"Main Task Ready\n");
}

void loop() 
{
  //不需要写东西
}




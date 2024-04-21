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
  Serial.begin(USART_0_BAUDRATE);
  Serial1.begin(USART_1_BAUDRATE);
  Serial2.begin(USART_2_BAUDRATE);
  pinMode(BOARD_LED,OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN5,OUTPUT);
  pinMode(IN6,OUTPUT);
  pinMode(IN7,OUTPUT);
  pinMode(IN8,OUTPUT);
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  digitalWrite(IN5,0);
  digitalWrite(IN6,0);
  digitalWrite(IN7,0);
  digitalWrite(IN8,0);

  pinMode(M1A,OUTPUT);
  pinMode(M1B,OUTPUT);
  pinMode(M1P,OUTPUT);
  digitalWrite(M1A,0);
  digitalWrite(M1B,0);
  analogWrite(M1P,130);

  pinMode(M2A,OUTPUT);
  pinMode(M2B,OUTPUT);
  pinMode(M2P,OUTPUT);
  digitalWrite(M2A,0);
  digitalWrite(M2B,0);
  analogWrite(M2P,130);

  pinMode(M3A,OUTPUT);
  pinMode(M3B,OUTPUT);
  pinMode(M3P,OUTPUT);
  digitalWrite(M3A,0);
  digitalWrite(M3B,0);
  analogWrite(M3P,130);

  pinMode(M4A,OUTPUT);
  pinMode(M4B,OUTPUT);
  pinMode(M4P,OUTPUT);
  digitalWrite(M4A,0);
  digitalWrite(M4B,0);
  analogWrite(M4P,200);

  pinMode(LEDF1,OUTPUT);
  pinMode(LEDF2,OUTPUT);
  pinMode(FIRE1,OUTPUT);
  pinMode(FIRE2,OUTPUT);
  digitalWrite(LEDF1,0);
  digitalWrite(LEDF2,0);
  digitalWrite(FIRE1,0);
  digitalWrite(FIRE2,0);
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




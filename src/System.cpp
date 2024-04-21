/**
  ******************************************************************************
  * @file    System.cpp
  * @author  徐哲??
  * @brief   ??件??????初始化
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"

BoardState boardState = BOARD_WAKEUP; 
CMDTypeState CMDstate = CMD_OFF;

StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
StaticTask_t USART_IRQHandler_TCB;

StackType_t Task_StateStack[Task_State_STK];
StaticTask_t Task_State_TCB;

char USART_Receive_Buffer[USART_BUFFER_STK];

char CMD_Stack[CMD_STK] = {0};
uint8_t CMD_Ifout = 0;
uint8_t CMD_Outport = 0; 
uint8_t USART_IRQNFLAG = 0;

uint8_t fis_in[8] = {0};

COMFunDict My_USART0_Prop_Array[] = {//字典
	{USART_UNO_1CLAW,Usart_Uno_1Claw},
};

COMFunDict My_USART1_Prop_Array[] = {//字典
	{USART_UNO_1CLAW,Usart_Uno_1Claw},
};

//串口定义
Arduino_COM_typedef MY_USART0 ={(const uint8_t)     0,
                                (const uint8_t)     sizeof(My_USART0_Prop_Array)/
                                                    sizeof(My_USART0_Prop_Array[0]),
                                (COMFunDict* )      My_USART0_Prop_Array,
                                };

Arduino_COM_typedef MY_USART1 ={(const uint8_t)     1,
                                (const uint8_t)     sizeof(My_USART1_Prop_Array)/
                                                    sizeof(My_USART1_Prop_Array[0]),
                                (COMFunDict* )      My_USART1_Prop_Array,
                                };









/**
  ******************************************************************************
  * @file    System.cpp
  * @author  ÂæêÂì≤ËΩ?
  * @brief   Á°?‰ª∂Ë?æÂ?áÂàùÂßãÂåñ
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








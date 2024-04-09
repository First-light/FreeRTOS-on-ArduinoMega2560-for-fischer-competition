/**
  ******************************************************************************
  * @file    System.cpp
  * @author  å¾å“²è½?
  * @brief   ç¡?ä»¶è?¾å?‡åˆå§‹åŒ–
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"

Board_State_Typedef BoardState = BOARD_WAKEUP; 
CMDStateTypedef CMDstate = CMD_OFF;

StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
StaticTask_t USART_IRQHandler_TCB;

StackType_t Task_StateStack[Task_State_STK];
StaticTask_t Task_State_TCB;

char USART_Receive_Buffer[USART_Buffer_STK];
char CMD_Stack[CMD_MAX_STACK] = {0};








/**
  ******************************************************************************
  * @file    TaskBasic.h
  * @author  徐哲??
  * @brief   任务头文??
  * @verbatim
  *             ??头文件定义已下内容：
  *             -任务相关宏以及任务分配空间和任务优先??
  *             -任务相关类型定义
  *             -任务变量声明
  *             -一些基??定义
  * @endverbatim
  ******************************************************************************  
*/ 
#ifndef _TASKBASIC_H_
#define _TASKBASIC_H_

#include "System.h"

/******************************任务??**********************************/
#define USART_IRQHandler_STK            128
#define USART_IRQHandler_PRI            0x10

#define Task_State_STK                  128
#define Task_State_PRI                  0x10
/******************************类型**********************************/

/******************************任务函数**********************************/
void Task_CMD(void);
void Open_Task_CMD(void);
void USARTS_IRQHandler(void);//串口??????
void Task_State();//初???任务创??
//任务及内存分??

/******************************任务变量声明**********************************/
extern StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
extern StaticTask_t USART_IRQHandler_TCB;

extern StackType_t Task_StateStack[Task_State_STK];
extern StaticTask_t Task_State_TCB;

#endif 
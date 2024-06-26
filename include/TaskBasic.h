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

/*****************************任务宏定义**********************************/
#define USART_IRQHandler_STK 1512
#define USART_IRQHandler_PRI 0x99
#define Task_State_STK 128
#define Task_State_PRI 0x10
/*****************************任务函数**********************************/
// 启动任务
void Task_State();

// 串口
void USARTS_IRQHandler(void);

// CMD函数声明
void Task_CMD(void);
void Open_Task_CMD(void);

void CMDW_ReplyInput(uint8_t USARTx, char *string, String reply);
void CMDW_Tip(uint8_t USARTx, char *string);
void CMDW_Chat(uint8_t USARTx, String string);

void CMDInput(uint8_t USARTx);
void CMDReply();
void CMDClear();
void CMDlanguage(char *cmd,uint8_t USARTx);
void CMDLoad(char* input);
/******************************处理函数声明**********************************/
void Usart_Uno_1Claw(COMFrame *Frame);
/******************************任务变量声明**********************************/
extern StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
extern StaticTask_t USART_IRQHandler_TCB;
extern StackType_t Task_StateStack[Task_State_STK];
extern StaticTask_t Task_State_TCB;


#endif
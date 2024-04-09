/**
  ******************************************************************************
  * @file    TaskBasic.h
  * @author  ����??
  * @brief   ����ͷ��??
  * @verbatim
  *             ??ͷ�ļ������������ݣ�
  *             -������غ��Լ��������ռ����������??
  *             -����������Ͷ���
  *             -�����������
  *             -һЩ��??����
  * @endverbatim
  ******************************************************************************  
*/ 
#ifndef _TASKBASIC_H_
#define _TASKBASIC_H_

#include "System.h"

/******************************����??**********************************/
#define USART_IRQHandler_STK            128
#define USART_IRQHandler_PRI            0x10

#define Task_State_STK                  128
#define Task_State_PRI                  0x10
/******************************����**********************************/

/******************************������**********************************/
void Task_CMD(void);
void Open_Task_CMD(void);
void USARTS_IRQHandler(void);//����??????
void Task_State();//��???����??
//�����ڴ��??

/******************************�����������**********************************/
extern StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
extern StaticTask_t USART_IRQHandler_TCB;

extern StackType_t Task_StateStack[Task_State_STK];
extern StaticTask_t Task_State_TCB;

#endif 
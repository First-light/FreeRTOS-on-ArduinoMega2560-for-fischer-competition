/**
  ******************************************************************************
  * @file    ComProplist.h
  * @author  徐哲�?
  * @brief   串口协�??字典头文�?
  * @verbatim
  *             �?头文件定义已下内容：
  *             -串口号及其标签的�?
  *             -字典数组声明
  *             -字典属性�?
  *             -处理函数声明
  *             -发送函数声�?
  * @endverbatim
  ******************************************************************************  
  */ 
#ifndef _USART_H_
#define _USART_H_

#include "Comlib.h"
/* ************************************ 全局声明 **************************************** */
#define USART_0 0
#define USART_1 1
#define USART_2 2
#define USART_3 3
#define USART_4 4

#define USART_SERIAL0 Serial
#define USART_SERIAL1 Serial1
#define USART_SERIAL2 Serial2
#define USART_SERIAL3 Serial3


void UART_SendByte(uint8_t USARTx,uint8_t data);
void UART_SendString(uint8_t USARTx,String string);
void UART_SendInt(uint8_t USARTx,int Num);
void UART_SendChars(uint8_t USARTx,char* string);
/* ************************************ 字典声明 **************************************** */
extern COMFunDict My_USART0_Prop_Array[];
extern COMFunDict My_USART1_Prop_Array[];
extern COMFunDict My_USART2_Prop_Array[];
extern COMFunDict My_USART3_Prop_Array[];
extern COMFunDict My_USART4_Prop_Array[];
#endif

/**
 ******************************************************************************
 * @file    Include.h
 * @author  徐哲�?
 * @brief   头文件集合头文件
 * @verbatim   将所有用到的头文件放在这�?
 *             （一�?用于main里include�?
 * @endverbatim
 ******************************************************************************
 */

//??�⣺
//1.�����ܼ���ͷ�ļ�����ӣ������ڴ���??
//2.��ΪArduino���� vTaskDelay(20/portTICK_PERIOD_MS);���delay20ms
#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "System.h"
#include "Comlib.h"
#include "Usartx.h"
#include "TaskBasic.h"
#include "Analyse.h"

/******************************�ض���궨**********************************/
#define USART_LOG USART_0
#define USART_LOG_SERIAL USART_SERIAL0
/******************************�����궨**********************************/
#define USART_BaudRate 9600
#define USART_Buffer_STK 128
#define CMD_MAX_STACK 64
/******************************���Ŷ���**********************************/
#define RGB_PIN_RED 9
#define RGB_PIN_GREED 10
#define RGB_PIN_BLUE 11
#define LED_BOARD 13
/******************************��������**********************************/

/******************************ö�ٶ���**********************************/
typedef enum
{
  BOARD_SLEEP,
  BOARD_WAKEUP
} Board_State_Typedef;

typedef enum
{
  CMD_OFF,
  CMD_ON,
} CMDStateTypedef;
/******************************��������**********************************/
extern Board_State_Typedef BoardState;
extern char CMD_Stack[CMD_MAX_STACK]; // 缓冲�?
extern CMDStateTypedef CMDstate;      // CMD开�?
/* ************************************ �������� **************************************** */
#define USART_UNO_1CLAW 0x99
void Usart_Uno_1Claw(COMFrame *Frame);
#endif
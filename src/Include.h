/**
 ******************************************************************************
 * @file    Include.h
 * @author  寰愬摬杞?
 * @brief   澶存枃浠堕泦鍚堝ご鏂囦欢
 * @verbatim   灏嗘墍鏈夌敤鍒扮殑澶存枃浠舵斁鍦ㄨ繖閲?
 *             锛堜竴鑸?鐢ㄤ簬main閲宨nclude锛?
 * @endverbatim
 ******************************************************************************
 */

//??题：
//1.尽可能减少头文件的添加，减少内存消??
//2.因为Arduino性能 vTaskDelay(20/portTICK_PERIOD_MS);最低delay20ms
#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "System.h"
#include "Comlib.h"
#include "Usartx.h"
#include "TaskBasic.h"
#include "Analyse.h"

/******************************重定向宏定**********************************/
#define USART_LOG USART_0
#define USART_LOG_SERIAL USART_SERIAL0
/******************************参数宏定**********************************/
#define USART_BaudRate 9600
#define USART_Buffer_STK 128
#define CMD_MAX_STACK 64
/******************************引脚定义**********************************/
#define RGB_PIN_RED 9
#define RGB_PIN_GREED 10
#define RGB_PIN_BLUE 11
#define LED_BOARD 13
/******************************函数定义**********************************/

/******************************枚举定义**********************************/
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
/******************************变量定义**********************************/
extern Board_State_Typedef BoardState;
extern char CMD_Stack[CMD_MAX_STACK]; // 缂撳啿鍖?
extern CMDStateTypedef CMDstate;      // CMD寮�鍏?
/* ************************************ 任务声明 **************************************** */
#define USART_UNO_1CLAW 0x99
void Usart_Uno_1Claw(COMFrame *Frame);
#endif
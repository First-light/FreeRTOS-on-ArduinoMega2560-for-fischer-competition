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
#define USART_BUFFER_STK 128
#define CMD_STK USART_BUFFER_STK
/******************************引脚定义**********************************/
#define RGB_PIN_RED 9
#define RGB_PIN_GREED 10
#define RGB_PIN_BLUE 11
#define BOARD_LED 13

#define L_MOTOR_PORTa 
#define L_MOTOR_PORTb 
#define L_MOTOR_PWM 
 
#define R_MOTOR_PORTa
#define R_MOTOR_PORTb
#define R_MOTOR_PWM

#define BOND1_PORTa
#define BOND1_PORTb
#define BOND1_PWM

#define BOND2_PORTa
#define BOND2_PORTb
#define BOND2_PWM
/******************************函数定义**********************************/

/******************************枚举定义**********************************/
typedef enum
{
  BOARD_SLEEP,
  BOARD_WAKEUP
} BoardState;

typedef enum
{
  CMD_OFF,
  CMD_ON,
} CMDTypeState;

typedef enum
{
  MOTOR_OFF,
  MOTOR_DIR,
  MOTOR_PWM,
  MOTOR_PIDSPEED,
  MOTOR_PIDPOSITION,
} MotorState;

typedef struct
{
  MotorState state;
  uint8_t port_a;
  uint8_t port_b;
  uint8_t port_pwm;
  double  current_speed;
  double  current_position;
  double  expected_speed;
  double  expected_position;
  double  expedted_pwm;
} MOTORTypedef;

/******************************变量定义**********************************/
extern BoardState boardState;
extern char CMD_Stack[CMD_STK]; // 缂撳啿鍖?
extern CMDTypeState CMDstate;      // CMD寮�鍏?
/* ************************************ 任务声明 **************************************** */
#define USART_UNO_1CLAW 0x99
void Usart_Uno_1Claw(COMFrame *Frame);
#endif
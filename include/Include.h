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
#define USART_BUFFER_STK 128
#define CMD_STK USART_BUFFER_STK
/******************************���Ŷ���**********************************/
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
/******************************��������**********************************/

/******************************ö�ٶ���**********************************/
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

/******************************��������**********************************/
extern BoardState boardState;
extern char CMD_Stack[CMD_STK]; // 缓冲�?
extern CMDTypeState CMDstate;      // CMD开�?
/* ************************************ �������� **************************************** */
#define USART_UNO_1CLAW 0x99
void Usart_Uno_1Claw(COMFrame *Frame);
#endif
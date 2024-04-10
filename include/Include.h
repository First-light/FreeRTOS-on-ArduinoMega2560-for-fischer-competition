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
//3.出现板子异常降速，程序运行怪异，一般是分配的内存不够了
//4.串口接收数据偶尔会导致数据损坏，数据被截断的情况（被分成多段送来了）
#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "System.h"
#include "Comlib.h"
#include "Usartx.h"
#include "TaskBasic.h"
#include "Analyse.h"

/******************************重定向宏定**********************************/
#define USART_LOG USART_1
#define USART_LOG_SERIAL USART_SERIAL0
/******************************参数宏定**********************************/
#define USART_0_BAUDRATE 9600
#define USART_1_BAUDRATE 38400

#define USART_BUFFER_STK 128
#define CMD_STK USART_BUFFER_STK
/******************************引脚定义**********************************/
#define RGB_PIN_RED 9
#define RGB_PIN_GREED 10
#define RGB_PIN_BLUE 11
#define BOARD_LED 13

#define RX1 19
#define TX1 18
#define HC05_KEY 22

/******************************任务标签定义**********************************/
#define USART_UNO_1CLAW 0x99
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
extern char CMD_Stack[CMD_STK]; 
extern CMDTypeState CMDstate;      
extern uint8_t CMD_Ifout;
extern uint8_t CMD_Outport; 
extern uint8_t USART_IRQNFLAG;

extern uint8_t HC05key;
extern uint8_t HC05power;

extern Arduino_COM_typedef MY_USART0;
extern Arduino_COM_typedef MY_USART1;


#endif
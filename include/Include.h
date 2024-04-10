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
//3.���ְ����쳣���٣��������й��죬һ���Ƿ�����ڴ治����
//4.���ڽ�������ż���ᵼ�������𻵣����ݱ��ضϵ���������ֳɶ�������ˣ�
#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "System.h"
#include "Comlib.h"
#include "Usartx.h"
#include "TaskBasic.h"
#include "Analyse.h"

/******************************�ض���궨**********************************/
#define USART_LOG USART_1
#define USART_LOG_SERIAL USART_SERIAL0
/******************************�����궨**********************************/
#define USART_0_BAUDRATE 9600
#define USART_1_BAUDRATE 38400

#define USART_BUFFER_STK 128
#define CMD_STK USART_BUFFER_STK
/******************************���Ŷ���**********************************/
#define RGB_PIN_RED 9
#define RGB_PIN_GREED 10
#define RGB_PIN_BLUE 11
#define BOARD_LED 13

#define RX1 19
#define TX1 18
#define HC05_KEY 22

/******************************�����ǩ����**********************************/
#define USART_UNO_1CLAW 0x99
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
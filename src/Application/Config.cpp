/**
  ******************************************************************************
  * @file    Config.cpp
  * @author  徐哲�?
  * @brief   �?�?�?
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"



void USART_0_IRQHandler()
{
   if( Serial.available()) 
    {
      char USART_0_Stack[USART_BUFFER_STK] = {0};
      uint8_t count = 0;
      uint16_t temp;
      char temp_char;

      while(Serial.available())//取完所有数�?
      {
        temp = Serial.read();
        temp_char = (char)temp;
        if(boardState == BOARD_WAKEUP)//复制一份给处理函数
        {
          Get_Frame_COM(temp,&MY_USART0);
        }
        if(count <= USART_BUFFER_STK-1-1)//复制一份给CMD缓冲�?
        {
          USART_0_Stack[count] = temp_char;
          count++;
        }
      }
      USART_0_Stack[count] = '\0';
      if (USART_0_Stack[0] != 0xEE && CMDstate == CMD_ON)
      {
        CMDLoad(USART_0_Stack);
      }
      if(USART_0_Stack[0] == '@' && CMDstate == CMD_OFF)//CMD唤醒�?
      {
        Open_Task_CMD();
      }
    }
}


void USARTS_IRQHandler()//�?�?�?
{
  while(1)
  {
    USART_0_IRQHandler();
    vTaskDelay(100/portTICK_PERIOD_MS);//�?100ms读一次串�?
  }
}


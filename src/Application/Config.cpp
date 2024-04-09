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
      uint8_t count = 0;
      uint16_t temp;
      char temp_char;
      while(Serial.available())//取完所有数�?
      {
        temp = Serial.read();
        temp_char = (char)temp;
        if(BoardState == BOARD_WAKEUP)//复制一份给处理函数
        {
          Get_Frame_COM(temp,&MY_USART0);
        }
        if(count <= CMD_MAX_STACK-1-1)//复制一份给CMD缓冲�?
        {
          CMD_Stack[count] = temp_char;
          count++;
        }
      }
      CMD_Stack[count] = '\0';//结尾
      if(strcmp(CMD_Stack,"@") == 0 && CMDstate == CMD_OFF)//CMD唤醒�?
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
    vTaskDelay(25/portTICK_PERIOD_MS);//�?100ms读一次串�?
  }
}


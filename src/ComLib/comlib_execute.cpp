/**
  ******************************************************************************
  * @file    comlib_execute.cpp
  * @author  徐哲�?
  * @brief   串口接受处理函数
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"

void Usart_Uno_1Claw(COMFrame *Frame)
{
    char temp = Frame->Data.uint8_ts[0];
    switch (temp)
    {
        
    case 0x00:  BoardState = BOARD_SLEEP;   break;
    case 0x01:  BoardState = BOARD_WAKEUP;  break; 

    default:break;
    }
}
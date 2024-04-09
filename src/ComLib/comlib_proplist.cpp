/**
 ******************************************************************************
 * @file    comlib_proplist.c
 * @author  
 * @brief   �?代码提供了COM消息处理函数词典的定�?:

 *  @verbatim
 *           �?字典用于ProcessFrame()�?根据属性值查找�?�应的消�?处理函数
 * 		     根据需求在ExecuteLib.c�?添加相应的消�?处理函数后，更新相应的proplist.c�?
 * 		     在头文件Comproplist.h�?设置相应的属性�?
 *  @endverbatim
 ******************************************************************************
 */
#include "Include.h"

/*******************************属性和方法字典***********************************/

COMFunDict My_USART0_Prop_Array[] = {//字典
	{USART_UNO_1CLAW,Usart_Uno_1Claw},
};

//串口定义
Arduino_COM_typedef MY_USART0 ={(const uint8_t)     0,
                                (const uint8_t)     sizeof(My_USART0_Prop_Array)/
                                                    sizeof(My_USART0_Prop_Array[0]),
                                (COMFunDict* )      My_USART0_Prop_Array,
                                };







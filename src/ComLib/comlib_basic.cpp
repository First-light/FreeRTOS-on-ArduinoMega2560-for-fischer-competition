/**
  ******************************************************************************
  * @file    Comlib_basic.c
  * @author  徐哲�?
  * @brief   串口协�??核心
  * @verbatim
  * 
  * @endverbatim
  ******************************************************************************  
  */ 
#include "Include.h"

void (*Find_Method_COM(uint8_t Prop, COMFunDict* Props_Array, 
    uint8_t Props_Count))(COMFrame* Frm);
/*************************
 * 发送（SendFrame）和接受（GetFrame）的接口
 * *************************/
/**
 * @brief  发送帧数据
 * @param  �?
 * @retval �?
 */
void Send_Frame_COM(COMFrame* Send_Frame, Arduino_COM_typedef* USARTx) 
{
    uint8_t *Send_Buf_Temp;
    uint8_t Send_Buf[COM_FRAME_MAX_LENGTH];//发送缓�?
    uint8_t Length = Send_Frame->Length;
    uint8_t LengthTemp = Length;

    Send_Buf_Temp = &Send_Buf[0];//回到开�?

    *Send_Buf_Temp++ = COM_FRAME_MARK;//帧头
    *Send_Buf_Temp++ = LengthTemp;//跳过帧长�?
    *Send_Buf_Temp++ = Send_Frame->Prop;//帧属�?

    for (int i = 0; i < Length; i++)
    {
        uint8_t Temp = Send_Frame->Data.uint8_ts[i];
        if (Temp == COM_FRAME_MARK) //FF通过�?义�??EE输出
        {
            *Send_Buf_Temp++ = COM_FRAME_ESCAPE;
            LengthTemp++;
        }
        *Send_Buf_Temp++ = Temp;
    }

    *Send_Buf_Temp++  = COM_FRAME_MARK;//帧尾封�??
    LengthTemp       += 4;//帧头帧尾加入帧长�?
    Send_Buf[1]       = LengthTemp;//帧总长

    COM_Write(Send_Buf,LengthTemp,USARTx);
}

/**
 * @brief  接收帧数�?
 * @param  接收帧数�?的指针，�?以是 &Frame1_rcv，�?�应CAN1 ;也可以是&Frame2_rcv，�?�应CAN2
 * @retval �?
 */
void Get_Frame_COM(uint8_t Data, Arduino_COM_typedef* USARTx) {
    COMRecStatus* pRecInfo;
    COMFrame* pFrame;
    uint8_t Rec_Status, pre_Data;

    pRecInfo       = &(USARTx->COM_Rec_Status);
    pFrame         = &(USARTx->COM_Rec);

    pre_Data   = pRecInfo->preData;
    Rec_Status = pRecInfo->RecStatus;

    if (Data == COM_FRAME_MARK && Rec_Status != TAIL_CONFIRM) 
    {
        if (pre_Data != COM_FRAME_ESCAPE) 
        {
            pRecInfo->RecStatus = HEAD_DETECT;
            Rec_Status = HEAD_DETECT;
        } 
        else 
        {
            if (pFrame->Length > 0)
                pFrame->Length--;
        }
    }

    switch (Rec_Status) 
    {
        case HEAD_DETECT:
            pRecInfo->RecStatus = LENGTH_ACQUIRE;
            break;

        case LENGTH_ACQUIRE:
            if (Data < 4) 
                pRecInfo->RecStatus = HEAD_DETECT;
            else 
            {
                pRecInfo->RecLength = Data;
                pFrame->Length = 0;
                pRecInfo->RecStatus = PROP_ACQUIRE;
            }
            break;

        case PROP_ACQUIRE:
            pFrame->Prop = Data;
            if (pRecInfo->RecLength == 4)
                pRecInfo->RecStatus = TAIL_CONFIRM;
            else 
                pRecInfo->RecStatus = DATA_ACQUIRE;
            break;

        case DATA_ACQUIRE:
            pRecInfo->RecLength--;
            pFrame->Data.uint8_ts[pFrame->Length++] = Data;
            if (pRecInfo->RecLength == 4) 
                pRecInfo->RecStatus = TAIL_CONFIRM;
            break;

        case TAIL_CONFIRM:
            if (COM_FRAME_MARK == Data)
                Process_Frame_COM(pFrame,USARTx);
            pRecInfo->RecStatus = HEAD_DETECT;
            break;
        
        default:
            break;
    }
    pRecInfo->preData = Data;
}

void Process_Frame_COM(COMFrame* Rec_Frame, Arduino_COM_typedef* USARTx) 
{
    void (*Fun)(COMFrame * Frm);

    COMFunDict* Props_Array;
    uint8_t Props_Count;

    Props_Array = USARTx->Prop_Array;
    Props_Count = USARTx->Prop_Count;
    
    if ((Fun = Find_Method_COM(Rec_Frame->Prop, Props_Array, Props_Count)) != 0) 
        Fun(Rec_Frame);
}

void (*Find_Method_COM( uint8_t Prop, COMFunDict* Props_Array, uint8_t Props_Count))(COMFrame* Frm) 
{
    uint8_t i;
    for (i = 0; i < Props_Count; ++i) {
        if (Props_Array[i].Prop == Prop) 
            return Props_Array[i].Fun;
    }
    return 0;
}

void COM_Write(uint8_t* Send_Buf,uint8_t Length,Arduino_COM_typedef* USARTx)
{
    uint8_t* p = Send_Buf;
	 while(Length>0)//当str指向的字符不为空，则继续
	 {
		 UART_SendByte(USARTx->SerialNum,*p);
         p++;//指针
		 Length--;//数量减少
	 }
}
/*********--------      end      --------*********/

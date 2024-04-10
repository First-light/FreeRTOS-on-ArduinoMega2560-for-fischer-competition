/**
 ******************************************************************************
 * @file    Comlib.h
 * @author  ������
 * @brief   ����Э��ͷ�ļ�
 * @verbatim
 *             ��ͷ�ļ������������ݣ�
 *             -COM֡�ĺ�
 *             -COM״̬�ĺ�
 *             -COM֡�ڵ����ݸ�ʽ����
 *             -COM֡����
 *             -��COM״̬��������
 *             -��������ֵ�봦������Ӧ�ṹ
 *             -��COM�ṹ��Ķ���
 *             -����Э����ĺ�������
 * @endverbatim
 ******************************************************************************
 */

#ifndef _COMLIB_H_
#define _COMLIB_H_

/******************************��COMͨ��Э��Ķ���*********************************/
#define COM_FRAME_MAX_LENGTH 0XE0 // ������󳤶�
#define COM_FRAME_MARK 0XEE       // ֡ͷ
#define COM_FRAME_ESCAPE 0XFF     // ת���

/******************************��COM״̬�Ķ���*********************************/
#define HEAD_DETECT 0
#define LENGTH_ACQUIRE 1
#define PROP_ACQUIRE 2
#define DATA_ACQUIRE 3
#define TAIL_CONFIRM 4
/******************************��COM֡�ڵ����ݸ�ʽ����*********************************/
typedef union
{
    int8_t int8_ts[128];
    int16_t int16_ts[64];
    int32_t int32_ts[32];
    uint8_t uint8_ts[128];
    uint16_t uint16_ts[64];
    uint32_t uint32_ts[32];
    float floats_ts[32];
} COMData;
/******************************COM֡����*********************************/
typedef struct
{
    uint8_t Length;
    uint8_t Prop;
    COMData Data;
} COMFrame;

/******************************��COM״̬��������*********************************/
typedef struct
{
    uint8_t RecStatus;
    uint8_t RecCounts;
    uint8_t preData;
    uint8_t RecLength;
} COMRecStatus;

/******************************��������ֵ�봦������Ӧ�ṹ*********************************/
typedef struct
{
    uint16_t Prop;              // ��������
    void (*Fun)(COMFrame *Frm); // �����Զ�Ӧ�Ĵ�����
} COMFunDict;

/******************************��COM�ṹ��Ķ���*********************************/
typedef struct arduino_com_typedef
{
    const uint8_t SerialNum;
    const uint8_t Prop_Count;
    COMFunDict *Prop_Array;
    COMFrame COM_Rec;
    COMRecStatus COM_Rec_Status;
} Arduino_COM_typedef;

/******************************���ĺ���*********************************/

void Send_Frame_COM(COMFrame *, Arduino_COM_typedef *);
void Get_Frame_COM(uint8_t, Arduino_COM_typedef *);
void Process_Frame_COM(COMFrame *, Arduino_COM_typedef *);
void COM_Write(uint8_t *, uint8_t, Arduino_COM_typedef *);

#endif

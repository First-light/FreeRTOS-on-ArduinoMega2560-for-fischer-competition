/**
  ******************************************************************************
  * @file    task_CMD.cpp
  * @author  徐哲�?
  * @brief   命令�?
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 
#include "Include.h"

typedef enum{
    LAN_NULL,
    LAN_CMDOFF,
}LanguageType;

typedef struct language {
    const char* code;
    LanguageType type;
}Language;

//函数声明
void CMDW_ReplyInput(uint8_t USARTx,char* string,String reply);
void CMDW_Tip(uint8_t USARTx,char* string);
void CMDW_Chat(uint8_t USARTx,String string);

void CMD_WaitInput(uint8_t USARTx);
void CMDReply();
void CMDClear();
void CMDlanguage(char* cmd);

//�?言声明
Language LanguageList[] = {
    {"quit",LAN_CMDOFF},
};

const uint16_t LanguageCount =  sizeof(LanguageList)/
                                sizeof(LanguageList[0]);

//函数                           
void Task_CMD(void)
{
    digitalWrite(LED_BOARD, HIGH);
    while (1)
    {
        if (CMDstate == CMD_ON)
        {
            CMDClear();
            while(CMDstate == CMD_ON)
            {
                CMD_WaitInput(USART_LOG);
                CMDlanguage(CMD_Stack);
                CMDClear();
                vTaskDelay(20/portTICK_PERIOD_MS);
            }
        }else 
        if (CMDstate == CMD_OFF)
        {
            vTaskDelete(NULL);
        }

    }
}
void CMDClear()
{
    for (size_t i = 0; i < CMD_MAX_STACK; i++)
    {
        CMD_Stack[i] = '\0';
    }
}

void CMDlanguage(char* cmd)
{
    LanguageType lang = LAN_NULL;
    Language* p = LanguageList;
    for (size_t i = 0; i < LanguageCount; i++)
    {
        if (strcmp(cmd, p->code) == 0)
        {
            lang = p->type;
            break;
        }
        p++;
    }
    switch (lang)
    {

    case LAN_CMDOFF:
        CMDW_ReplyInput(USART_LOG,CMD_Stack,"CMDOFF"); 
        CMDstate = CMD_OFF;
        break;
    default:
        CMDW_ReplyInput(USART_LOG,CMD_Stack,"No Such Language");
        break;
    }
}

void CMDReply()
{
    UART_SendChars(USART_LOG,CMD_Stack);
}

void CMDW_ReplyInput(uint8_t USARTx,char* string,String reply)
{
    UART_SendString(USARTx,"Maid : ");
    UART_SendChars(USARTx,string);
    UART_SendString(USARTx," : ");
    UART_SendString(USARTx,reply);
    UART_SendString(USARTx," \n");
}

void CMDW_Chat(uint8_t USARTx,String string)
{
    UART_SendString(USARTx,"Maid : ");
    UART_SendString(USARTx,string);
    UART_SendString(USARTx,"\n");
}

void CMDW_Tip(uint8_t USARTx,char* string)
{
    UART_SendString(USARTx,"Maid : ");
    UART_SendChars(USARTx,string);
}

void CMD_WaitInput(uint8_t USARTx)
{
    UART_SendString(USARTx,">>>");
    while(CMD_Stack[0] == '\0' || CMD_Stack[0] == 0xEE )vTaskDelay(50/portTICK_PERIOD_MS);
    UART_SendString(USARTx,CMD_Stack);
    UART_SendString(USARTx,"\n");
}

void Open_Task_CMD(void)
{
    CMDstate = CMD_ON;
    taskENTER_CRITICAL();
    xTaskCreate((TaskFunction_t     ) Task_CMD,
                (const char * const ) "Task_CMD", 
                (uint16_t           ) 256,
                (void * const       ) NULL,
                (UBaseType_t        ) 0x10,
                (TaskHandle_t      *) NULL);
    taskEXIT_CRITICAL();
}
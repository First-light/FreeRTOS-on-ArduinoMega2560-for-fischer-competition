#include "Include.h"


typedef enum
{
    LAN_NULL,
    LAN_CMDOFF,
    LAN_FISH,
    LAN_USART0,
    LAN_USART1,
    LAN_NOTOUT,
} LanguageType;

typedef struct language
{
    const char *code;
    LanguageType type;
} Language;

Language LanguageList[] = {
    {"quit", LAN_CMDOFF},
    {"fish",LAN_FISH},
    {"usart0",LAN_USART0},
    {"usart1",LAN_USART1},
    {"notout",LAN_NOTOUT},
};

void CMDlanguage(char *cmd,uint8_t USARTx)
{
    LanguageType lang = LAN_NULL;
    Language *p = LanguageList;
    uint16_t LanguageCount = sizeof(LanguageList) /sizeof(LanguageList[0]);
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
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "CMDOFF");
        CMDstate = CMD_OFF;
        break;
    case LAN_FISH:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "FISCHER");
        break;
    case LAN_USART0:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "USART_0 output");
        CMD_Ifout = 1;
        CMD_Outport = USART_0;
        break;
    case LAN_USART1:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "USART_1 output");
        CMD_Ifout = 1;
        CMD_Outport = USART_1;
        break;
    case LAN_NOTOUT:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "Not out");
        CMD_Ifout = 0;
        break;
    default:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "No Such Language");
        break;
    }
}
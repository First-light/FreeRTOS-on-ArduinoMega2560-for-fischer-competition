#include "Include.h"


typedef enum
{
    LAN_NULL,
    LAN_CMDOFF,
    LAN_FISH,
} LanguageType;

typedef struct language
{
    const char *code;
    LanguageType type;
} Language;

Language LanguageList[] = {
    {"quit", LAN_CMDOFF},
    {"fish",LAN_FISH},
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
    default:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "No Such Language");
        break;
    }
}
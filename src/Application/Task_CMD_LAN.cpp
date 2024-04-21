#include "Include.h"


typedef enum
{
    LAN_NULL,
    LAN_CMDOFF,
    LAN_USART0,
    LAN_USART1,
    LAN_NOTOUT,
    LAN_FISH_1,
    LAN_FISH_2,
    LAN_FISH_3,
    LAN_FISH_4,
    LAN_FISH_5,
    LAN_FISH_6,
    LAN_FISH_7,
    LAN_FISH_8,
    LAN_FISH_9,
    LAN_FISH_10,
    LAN_FISH_11,
    LAN_FISH_12,
    LAN_FISH_13,
    LAN_FISH_14,
    LAN_FISH_15,
    LAN_PORT_1,
    LAN_PORT_2,
    LAN_PORT_3,
    LAN_PORT_4,
    LAN_PORT_5,
    LAN_PORT_6,
    LAN_PORT_7,
    LAN_PORT_8,
    LAN_PORT_9,
    LAN_PORT_10,
    LAN_PORT_11,
    LAN_PORT_12,
    LAN_PORT_13,
    LAN_PORT_14,
    LAN_PORT_15,
} LanguageType;

typedef struct language
{
    const char *code;
    LanguageType type;
} Language;

Language LanguageList[] = {
    {"quit", LAN_CMDOFF},
    {"usart0",LAN_USART0},
    {"usart1",LAN_USART1},
    {"notout",LAN_NOTOUT},
    {"fish1",LAN_FISH_1},
    {"fish2",LAN_FISH_2},
    {"fish3",LAN_FISH_3},
    {"fish4",LAN_FISH_4},
    {"fish5",LAN_FISH_5},
    {"fish6",LAN_FISH_6},
    {"fish7",LAN_FISH_7},
    {"fish8",LAN_FISH_8},
    {"fish9",LAN_FISH_9},
    {"fishA",LAN_FISH_10},
    {"fishB",LAN_FISH_11},
    {"fishC",LAN_FISH_12},
    {"fishD",LAN_FISH_13},
    {"fishE",LAN_FISH_14},
    {"fishF",LAN_FISH_15},
    {"port1",LAN_PORT_1},
    {"port2",LAN_PORT_2},
    {"port3",LAN_PORT_3},
    {"port4",LAN_PORT_4},
    {"port5",LAN_PORT_5},
    {"port6",LAN_PORT_6},
    {"port7",LAN_PORT_7},
    {"port8",LAN_PORT_8},
    {"port9",LAN_PORT_9},
    {"portA",LAN_PORT_10},
    {"portB",LAN_PORT_11},
    {"portC",LAN_PORT_12},
    {"portD",LAN_PORT_13},
    {"portE",LAN_PORT_14},
    {"portF",LAN_PORT_15},
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

    case LAN_FISH_1:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_1");
        digitalWrite(IN1,1);
        digitalWrite(IN2,0);
        break;
    case LAN_FISH_2:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_2");
        digitalWrite(IN1,0);
        digitalWrite(IN2,1);
        break;
    case LAN_FISH_3:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_3");
        digitalWrite(IN3,1);
        digitalWrite(IN4,0);
        break;
    case LAN_FISH_4:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_4");
        digitalWrite(IN3,0);
        digitalWrite(IN4,1);
        break;
    case LAN_FISH_5:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_5");
        digitalWrite(IN5,1);
        break;
    case LAN_FISH_6:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_6");
        digitalWrite(IN6,1);
        break;
    case LAN_FISH_7:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_7");
        digitalWrite(IN7,1);
        digitalWrite(IN8,0);
        break;
    case LAN_FISH_8:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_8");
        digitalWrite(IN7,0);
        digitalWrite(IN8,1);
        break;
    case LAN_FISH_9:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_9");
        break;
    case LAN_FISH_10:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_10");
        break;
    case LAN_FISH_11:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_11");
        break;
    case LAN_FISH_12:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_1");
        break;
    case LAN_FISH_13:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_13");
        break;
    case LAN_FISH_14:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_14");
        break;
    case LAN_FISH_15:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_FISH_15");
        digitalWrite(IN1,0);
        digitalWrite(IN2,0);
        digitalWrite(IN3,0);
        digitalWrite(IN4,0);
        digitalWrite(IN5,0);
        digitalWrite(IN6,0);
        digitalWrite(IN7,0);
        digitalWrite(IN8,0);
        break;

    case LAN_PORT_1:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_1");
        digitalWrite(M1A,1);
        digitalWrite(M1B,0);
        break;
    case LAN_PORT_2:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_2");
        digitalWrite(M1A,0);
        digitalWrite(M1B,1);
        break;
    case LAN_PORT_3:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_3");
        digitalWrite(M2A,1);
        digitalWrite(M2B,0);
        break;
    case LAN_PORT_4:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_4");
        digitalWrite(M2A,0);
        digitalWrite(M2B,0);
        break;
    case LAN_PORT_5:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_5");
        digitalWrite(M3A,1);
        digitalWrite(M3B,0);
        break;
    case LAN_PORT_6:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_6");
        digitalWrite(M3A,0);
        digitalWrite(M3B,1);
        break;
    case LAN_PORT_7:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_7");
        digitalWrite(M4A,1);
        digitalWrite(M4B,0);
        break;
    case LAN_PORT_8:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_8");
        digitalWrite(M4A,0);
        digitalWrite(M4B,1);
        break;
    case LAN_PORT_9:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_9");
        digitalWrite(LEDF2,1);
        digitalWrite(FIRE1,1);
        break;
    case LAN_PORT_10:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_10");
        break;
    case LAN_PORT_11:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_11");
        break;
    case LAN_PORT_12:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_12");
        break;
    case LAN_PORT_13:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_13");
        break;
    case LAN_PORT_14:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_14");
        digitalWrite(LEDF2,0);
        digitalWrite(FIRE1,0);
        break;
    case LAN_PORT_15:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "LAN_PORT_15");
        digitalWrite(M1A,0);
        digitalWrite(M1B,0);
        digitalWrite(M3A,0);
        digitalWrite(M3B,0);
        digitalWrite(M4A,0);
        digitalWrite(M4B,0);
        break;

    default:
        CMDW_ReplyInput(USART_LOG, CMD_Stack, "No Such Language");
        break;
    }
}
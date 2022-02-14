#include "japi.h"

// origin function
RequestExtraIntegerData RequestExtraIntegerData_o;
RequestExtraBooleanData RequestExtraBooleanData_o;
RequestExtraStringData RequestExtraStringData_o;
RequestExtraRealData RequestExtraRealData_o;
DzAPI_Map_GetMapLevel DzAPI_Map_GetMapLevel_o;
DzAPI_Map_HasMallItem DzAPI_Map_HasMallItem_o;
DzAPI_Map_IsRedVIP DzAPI_Map_IsRedVIP_o;
DzAPI_Map_IsBlueVIP DzAPI_Map_IsBlueVIP_o;

#include <cstdio>
// hooked function
int RequestExtraIntegerData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6)
{
    auto sb1 = from_string(param1);
    auto sb2 = from_string(param2);
    //printf("RequestExtraIntegerData_h: %d %s %s [%d %d %d %d]\n", dataType, sb1, sb2, param3, param4, param5, param6);
    // return RequestExtraIntegerData_o(dataType, whichPlayer, param1, param2, param3, param4, param5, param6);
    switch (dataType)
    {
    case 10:
        //printf("rpg lobby\n");
        return true;
    case 15:
        //printf("red vip\n");
        return true;
    case 16:
        //printf("blue vip\n");
        return true;
    case 22:
        //printf("has mall item\n");
        return true;
    case 44:
        //printf("buy reforged\n");
        return true;
    case 48:
        //printf("connoisseur\n");
        return true;
    case 49:
        //printf("battle net account\n");
        return true;
    case 50:
        //printf("author\n");
        return true;
    case 3:
        //printf("level\n");
        return 200;
    case 14:
        //printf("ladder level\n");
        return 200;
    case 17:
        //printf("ladder rank\n");
        return 1;
    case 18:
        //printf("level rank\n");
        return 1;
    case 30:
        //printf("platform vip\n");
        return 1;
    case 41:
        //printf("mall item count\n");
        return 1;
    case 52:
        //printf("custom rank\n");
        return 1;
    case 33:
        //printf("comsumable item\n");
        return 10000;
    case 45:
        //printf("played games\n");
        return 10000;
    case 46:
        //printf("comment count\n");
        return 10000;
    case 47:
        //printf("friend count\n");
        return 10000;
    case 51:
        //printf("comment total count\n");
        return 10000;
    case 54:
        //printf("sign in\n");
        return 999999999;
    case 56:
        //printf("all map time\n");
        return 100000000;
    case 65:
        //printf("bbs\n");
        return 999999999;
    case 69:
        if (0 == strcmp("power", sb1))
            param4 = 100000;
        //printf("chmoney\n");
        return 1000000;
    default:
        return RequestExtraIntegerData_o(dataType, whichPlayer, param1, param2, param3, param4, param5, param6);
    }
}
bool RequestExtraBooleanData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6)
{
    auto sb1 = from_string(param1);
    auto sb2 = from_string(param2);
    //printf("RequestExtraBooleanData_h: %d %s %s [%d %d %d %d]\n", dataType, sb1, sb2, param3, param4, param5, param6);
    // return RequestExtraBooleanData_o(dataType, whichPlayer, param1, param2, param3, param4, param5, param6);
    return true;
}

int RequestExtraStringData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6)
{
    return RequestExtraStringData_o(dataType, whichPlayer, param1, param2, param3, param4, param5, param6);
}

float RequestExtraRealData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6)
{
    return RequestExtraRealData_o(dataType, whichPlayer, param1, param2, param3, param4, param5, param6);
}

int DzAPI_Map_GetMapLevel_h(uint32_t player)
{
    return 200;
}
bool DzAPI_Map_HasMallItem_h(uint32_t whichPlayer, uint32_t key)
{
    char *sb = from_string(key);
    if (0 == strcmp("JJTG", sb))
        return false;
    return true;
}

int DzAPI_Map_IsRedVIP_h(uint32_t player)
{
    return true;
}
int DzAPI_Map_IsBlueVIP_h(uint32_t player)
{
    return true;
}
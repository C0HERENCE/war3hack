#ifndef JAPI_H
#define JAPI_H
#include "inject/hook.h"
#include "jass/string/jass_string.h"

// function type
typedef int(__cdecl* RequestExtraIntegerData)(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
typedef bool(__cdecl* RequestExtraBooleanData)(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
typedef int(__cdecl* RequestExtraStringData)(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
typedef float(__cdecl* RequestExtraRealData)(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
typedef int(__cdecl* DzAPI_Map_GetMapLevel)(uint32_t player);
typedef bool(__cdecl* DzAPI_Map_HasMallItem)(uint32_t whichPlayer, uint32_t key);
typedef bool(__cdecl* DzAPI_Map_IsRedVIP)(uint32_t player);
typedef bool(__cdecl* DzAPI_Map_IsBlueVIP)(uint32_t player);
// orgin function
extern RequestExtraIntegerData RequestExtraIntegerData_o;
extern RequestExtraBooleanData RequestExtraBooleanData_o;
extern RequestExtraStringData RequestExtraStringData_o;
extern RequestExtraRealData RequestExtraRealData_o;
extern DzAPI_Map_GetMapLevel DzAPI_Map_GetMapLevel_o;
extern DzAPI_Map_HasMallItem DzAPI_Map_HasMallItem_o;
extern DzAPI_Map_IsRedVIP DzAPI_Map_IsRedVIP_o;
extern DzAPI_Map_IsBlueVIP DzAPI_Map_IsBlueVIP_o;

// hooked function
int RequestExtraIntegerData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
bool RequestExtraBooleanData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
int RequestExtraStringData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
float RequestExtraRealData_h(int dataType, uint32_t whichPlayer, jstring_t param1, jstring_t param2, bool param3, int param4, int param5, int param6);
int DzAPI_Map_GetMapLevel_h(uint32_t player);
bool DzAPI_Map_HasMallItem_h(uint32_t whichPlayer, uint32_t key);
int DzAPI_Map_IsRedVIP_h(uint32_t player);
int DzAPI_Map_IsBlueVIP_h(uint32_t player);
#endif
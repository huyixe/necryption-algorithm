#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>

#include "1.h"

char  morse[8];                                         //一个莫尔斯码

void MorseToEn(char* morse)
{
    if (strcmp(morse, ".-") == 0) printf("a");
    if (strcmp(morse, "-...") == 0) printf("b");
    if (strcmp(morse, "-.-.") == 0) printf("c");
    if (strcmp(morse, "-..") == 0) printf("d");
    if (strcmp(morse, ".") == 0) printf("e");
    if (strcmp(morse, "..-.") == 0) printf("f");
    if (strcmp(morse, "--.") == 0) printf("g");
    if (strcmp(morse, "....") == 0) printf("h");
    if (strcmp(morse, "..") == 0) printf("i");
    if (strcmp(morse, ".---") == 0) printf("j");
    if (strcmp(morse, "-.-") == 0) printf("k");
    if (strcmp(morse, ".-..") == 0) printf("l");
    if (strcmp(morse, "--") == 0) printf("m");
    if (strcmp(morse, "-.") == 0) printf("n");
    if (strcmp(morse, "---") == 0) printf("o");
    if (strcmp(morse, ".--.") == 0) printf("p");
    if (strcmp(morse, "--.-") == 0) printf("q");
    if (strcmp(morse, ".-.") == 0) printf("r");
    if (strcmp(morse, "...") == 0) printf("s");
    if (strcmp(morse, "-") == 0) printf("t");
    if (strcmp(morse, "..-") == 0) printf("u");
    if (strcmp(morse, "...-") == 0) printf("v");
    if (strcmp(morse, ".--") == 0) printf("w");
    if (strcmp(morse, "-..-") == 0) printf("x");
    if (strcmp(morse, "-.--") == 0) printf("y");
    if (strcmp(morse, "--..") == 0) printf("z");
    if (strcmp(morse, "-----") == 0) printf("0");
    if (strcmp(morse, ".----") == 0) printf("1");
    if (strcmp(morse, "..---") == 0) printf("2");
    if (strcmp(morse, "...--") == 0) printf("3");
    if (strcmp(morse, "....-") == 0) printf("4");
    if (strcmp(morse, ".....") == 0) printf("5");
    if (strcmp(morse, "-....") == 0) printf("6");
    if (strcmp(morse, "--...") == 0) printf("7");
    if (strcmp(morse, "---..") == 0) printf("8");
    if (strcmp(morse, "----.") == 0) printf("9");
    if (strcmp(morse, ".-.-.-") == 0) printf(".");
    if (strcmp(morse, "---...") == 0) printf(":");
    if (strcmp(morse, "--..--") == 0) printf(",");
    if (strcmp(morse, "-.-.-.") == 0) printf(";");
    if (strcmp(morse, "..--..") == 0) printf("?");
    if (strcmp(morse, "-...-") == 0) printf("=");
    if (strcmp(morse, ".----.") == 0) printf("'");
    if (strcmp(morse, "-..-.") == 0) printf("/");
    if (strcmp(morse, "-.-.--") == 0) printf("!");
    if (strcmp(morse, "-....-") == 0) printf(" ");
    if (strcmp(morse, "..--.-") == 0) printf("_");
    if (strcmp(morse, ".-..-.") == 0) printf("\"");
    if (strcmp(morse, "-.--.") == 0) printf("(");
    if (strcmp(morse, "-.--.-") == 0) printf(")");
    if (strcmp(morse, "...-..-") == 0) printf("$");
    if (strcmp(morse, "....") == 0) printf("&");
    if (strcmp(morse, ".--.-.") == 0) printf("@");
    if (strcmp(morse, ".-.-.") == 0) printf("+");
}

int get_morse(char* p, char div)
{
    int i = 0;
    while (*p != div && *p != '\0')                  //判断是否为分隔符或已到最后
    {
        morse[i] = *p;                              //将分隔出的摩尔斯电码赋给数组
        i++;
        p++;
    }
    morse[i] = '\0';                                  //确保morse是一个字符串
    if (*p == '\0')return i;                         //最后一个电码时返回0
    else return i + 1;                                //否则返回下一个摩尔斯码的首地址
}

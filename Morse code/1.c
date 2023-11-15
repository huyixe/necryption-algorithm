#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>

#include "1.h"

char  morse[8];                                         //һ��Ī��˹��

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
    while (*p != div && *p != '\0')                  //�ж��Ƿ�Ϊ�ָ������ѵ����
    {
        morse[i] = *p;                              //���ָ�����Ħ��˹���븳������
        i++;
        p++;
    }
    morse[i] = '\0';                                  //ȷ��morse��һ���ַ���
    if (*p == '\0')return i;                         //���һ������ʱ����0
    else return i + 1;                                //���򷵻���һ��Ħ��˹����׵�ַ
}

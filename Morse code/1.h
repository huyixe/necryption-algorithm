#define _CRT_SECURE_NO_WARNINGS 1 

#ifndef __1_H //就是头文件名（全大写后加个_H

#define __1_H


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

char  morse[8];

void MorseToEn(char* morse);

int get_morse(char* p, char div);

#endif
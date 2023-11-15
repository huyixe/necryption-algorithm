#define _CRT_SECURE_NO_WARNINGS 1 

#ifndef __1_H //就是头文件名（全大写后加个_H

#define __1_H


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

unsigned char* base64_encode(unsigned char* str);

unsigned char* bae64_decode(unsigned char* code);

#endif
#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

#include"1.h"

int main()
{
    char origin[200];                              //用户输入
    char* p = origin;
    char div;                                       //分隔符
    int str_start;//新字符串开始的位置
    int i;
    for (i = 0; i < 200; i++)                            //清空数组
        origin[i] = '\0';
    printf("Enter the separator:");
    div = getchar();
    getchar();                                      //丢弃输入产生的换行符
    printf("Enter the morse code:");
    gets(origin);                                  //读入摩尔斯电码

    while (str_start = get_morse(p, div))
    {
        MorseToEn(morse);                          //翻译模块
        p += str_start;                              //将指针指向后一个摩尔斯电码
    }
    getchar();  //防止程序闪退
    printf(div);
    return 0;
}
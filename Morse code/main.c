#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

#include"1.h"

int main()
{
    char origin[200];                              //�û�����
    char* p = origin;
    char div;                                       //�ָ���
    int str_start;//���ַ�����ʼ��λ��
    int i;
    for (i = 0; i < 200; i++)                            //�������
        origin[i] = '\0';
    printf("Enter the separator:");
    div = getchar();
    getchar();                                      //������������Ļ��з�
    printf("Enter the morse code:");
    gets(origin);                                  //����Ħ��˹����

    while (str_start = get_morse(p, div))
    {
        MorseToEn(morse);                          //����ģ��
        p += str_start;                              //��ָ��ָ���һ��Ħ��˹����
    }
    getchar();  //��ֹ��������
    printf(div);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1 

/*һ�����Գ���*/
#include "1.h"  
#include <stdio.h> 
#include <string.h>   

int main(int argc, char** argv)
{
    unsigned char* buf = NULL;
    if (strcmp(argv[1], "-d") == 0)
    {
        buf = base64_decode(argv[2]);
        printf("%s\n", buf);
    }
    else
    {
        buf = base64_encode(argv[1]);
        printf("%s\n", buf);
    }

    free(buf);

    return 0;
}

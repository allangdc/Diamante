#include <stdio.h>
#include <stdlib.h>
#include "../Diamante.X/motor.h"

#define CODEBLOCKS

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int main()
{
    char PORTD;
    Motor right;
    Motor_Init(&right, RIGHT_MOTOR, &PORTD);
    Motor_AddPosition(&right, 0, 0b00001000);
    Motor_AddPosition(&right, 1, 0b00000100);
    Motor_AddPosition(&right, 2, 0b00000010);
    Motor_AddPosition(&right, 3, 0b00000001);
    PORTD = 0b10101010;
    while(1)
    {
        printf("PORTD=%s ", byte_to_binary(PORTD));
        system("PAUSE");
        Motor_Move(&right, FORWARD_MOTOR);
    }
    printf("Hello world!\n");
    return 0;
}

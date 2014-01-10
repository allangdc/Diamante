#include "motor.h"

#ifdef CODEBLOCKS
#include <stdio.h>
#endif

void Motor_Init(Motor* motor, MOTOR_TYPE id, unsigned char* port)
{
    motor->type = id;
    motor->port = port;
}

void Motor_AddPosition(Motor* motor, char position, char value)
{
    motor->position[position] = value;
}

void Motor_Move(Motor* motor, MOTOR_DIRECTION move)
{
    unsigned char port, i;
    port = 0;
    for(i=0; i<4; i++)
        port |= motor->position[i]; /* 11110000 */
    port = ~port;                   /* 00001111 */
    port &= *(motor->port);         /* 00001010 */
    switch(move)
    {
        case FORWARD_MOTOR:
            if(motor->pos < 3)
                motor->pos++;
            else
                motor->pos = 0;
            break;
        case BACK_MOTOR:
            if(motor->pos > 0)
                motor->pos--;
            else
                motor->pos = 3;
            break;
    }
    port |= motor->position[motor->pos];    /* 10001010 */
    *(motor->port) = port;
}

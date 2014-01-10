/*
 * File:   main.c
 * Author: allan
 *
 * Created on 9 de Janeiro de 2014, 01:56
 */


#include <pic18f4550.h>
#include <htc.h>
#include <xc.h>
#include <stdio.h>
#include "motor.h"

#define _XTAL_FREQ 20000000

char mallocref=0xAA;
char *next_alloc=&mallocref + 1;
void *malloc(int size)
{
    char  *this_alloc;
    this_alloc = next_alloc;
    //if ((END_OF_ALLOC_SPACE - this_alloc) < size)
      //return -1;
    next_alloc += size;
    return this_alloc;
}
void free(void *ptr)
{
    if (ptr)
        next_alloc = (char*)ptr;
}

void DelayMS(unsigned int ms)
{
    unsigned int i;
    unsigned int div;
    div = ms / 10;
    for(i=0; i<div; i++)
        __delay_ms(10);
}

void ConfigMotors(Motor *left, Motor *right)
{
    Motor_Init(right, RIGHT_MOTOR, &PORTD);
    Motor_AddPosition(right, 0, 0b00000001);
    Motor_AddPosition(right, 1, 0b00000010);
    Motor_AddPosition(right, 2, 0b00000100);
    Motor_AddPosition(right, 3, 0b00001000);
    
    Motor_Init(left, LEFT_MOTOR, &PORTD);
    Motor_AddPosition(left, 0, 0b10000000);
    Motor_AddPosition(left, 1, 0b01000000);
    Motor_AddPosition(left, 2, 0b00100000);
    Motor_AddPosition(left, 3, 0b00010000);

    
    TRISD = 0b00000000;
}

int main(void)
{
    Motor left, right;
    ConfigMotors(&left, &right);

    PORTD = 0b10101010;
    while(1)
    {
        Motor_Move(&left, FORWARD_MOTOR);
        Motor_Move(&right, BACK_MOTOR);
        DelayMS(50);
    }
    return 0;
}

/* 
 * File:   motor.h
 * Author: allan
 *
 * Created on 9 de Janeiro de 2014, 20:21
 */

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        LEFT_MOTOR,
        RIGHT_MOTOR
    } MOTOR_TYPE;

    typedef enum
    {
        BACK_MOTOR,
        FORWARD_MOTOR
    } MOTOR_DIRECTION;

    typedef struct motor
    {
        MOTOR_TYPE      type;
        char            position[4];
        char            pos;
        unsigned char   *port;
    } Motor;

    void Motor_Init(Motor *motor, MOTOR_TYPE id, unsigned char *port);
    void Motor_AddPosition(Motor *motor, char position, char value);
    void Motor_Move(Motor *motor, MOTOR_DIRECTION move);


#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */


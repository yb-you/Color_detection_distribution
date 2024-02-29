#include "stm32f10x.h"
#include <stdio.h>

uint16_t CCR1_Val = 0;

uint16_t open = 1000;
uint16_t sense = 1500;
uint16_t close = 2000;
//uint16_t CCR3_Val = 0;
//uint16_t CCR4_Val = 0;
//int m_speed[6] = {0, 100, 1000, 1500, 2000, 2500};
//int m;

TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure_PWM;
int motor2();
void motor2_sensing();
void motor2_close();
int motor(char R_data)
{
 
     
    switch (R_data)
    {
        case 'R':
            CCR1_Val = 900;
            break;
        case 'G':
            CCR1_Val = 1200;
            break;
        case 'Y':
            CCR1_Val = 1550;
            break;
        case 'O':
            CCR1_Val = 1800;
            break;
    }

    printf("CCR1_Val : %d\n", CCR1_Val);
    TIM_OCInitStructure_PWM.TIM_Pulse = CCR1_Val;
    TIM_OC1Init(TIM4, &TIM_OCInitStructure_PWM);
    delay_m();
    delay_m();
    while(1)
    {
        if(motor2()==1)
        {
            break;
        }
    }
    return 1;
}
int motor2()
{

    printf("motor2 open\n");
    TIM_OCInitStructure_PWM.TIM_Pulse = open;
    TIM_OC2Init(TIM4, &TIM_OCInitStructure_PWM);
    delay_m();
    delay_m();

    printf("motor2 close\n");
    TIM_OCInitStructure_PWM.TIM_Pulse = close;
    TIM_OC2Init(TIM4, &TIM_OCInitStructure_PWM);
    delay_m();
    delay_m();

    return 1;
}
void motor2_sensing()
{
    printf("motor2 sensing\n");
    TIM_OCInitStructure_PWM.TIM_Pulse = sense;
    TIM_OC2Init(TIM4, &TIM_OCInitStructure_PWM);
    delay_m();
}
void motor2_close()
{
    printf("motor2 close\n");
    TIM_OCInitStructure_PWM.TIM_Pulse = close;
    TIM_OC2Init(TIM4, &TIM_OCInitStructure_PWM);
}
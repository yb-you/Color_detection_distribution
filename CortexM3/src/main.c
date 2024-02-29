#include "stm32f10x.h"
#include "SPI_define.h"     // SPI1, SPI2를 쉽게 사용할 수 있도록 정의한 부분
//#include "USART_define.h"

#include <stdio.h>

/*
    현 프로젝트는 USART3의 Tx, Rx를 이용한 자가통신 구현 프로젝트이다.
    USART3도 SPI와 마찬가지로 Serial 통신으로, Tx, Rx로 구현되어있다.
    다만 SPI와 다르게 Master/Slave 구조가 아니기 때문에 MISO, MOSI의 Pin이 존재하지 않고 Tx, Rx의 Pin만 존재한다.
     (이전 SPI통신은 SPIy(Master), SPIz(Slave)의 통신으로, USART로 치면 USART1, USART3 사이의 통신이였다. 하지만 현 프로젝트에서는 USART3 하나를 이용한 통신 방식으로 구현되었다.)
*/

// TIM
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure_PWM;




void RCC_Configuration(void);
void GPIO_Configuration(void);
//void NVIC_Configuration(void);
void TIM_Configuration(void);
//void EXTI_Configuration(void);
void USART1_Configuration(); //Printf에 사용
void USART3_Configuration();
//void SPIy_Master_Configuration(void);
//void SPIz_Slave_Configuration(void);

// USART 통신에 사용할 변수 데이터
//uint8_t Send_data = 11;
char Receive_data = 'N';
char Send_data = 3;
int motor(char R_data);
void motor2_close();
int main(void)
{
    //RCC 초기화
    SystemInit();
  
    RCC_Configuration();
    //NVIC_Configuration();
    GPIO_Configuration();
    TIM_Configuration();
    //EXTI_Configuration();
    USART1_Configuration();
    USART3_Configuration();
    //SPIy_Master_Configuration();
    //SPIz_Slave_Configuration();



    // USART3의 통신 구현 //     // USART3의 통신 구현 //     // USART3의 통신 구현 //
    // USART3의 통신 구현 //     // USART3의 통신 구현 //     // USART3의 통신 구현 //
    // USART3의 통신 구현 //     // USART3의 통신 구현 //     // USART3의 통신 구현 //
    // USART3의 통신 구현 //     // USART3의 통신 구현 //     // USART3의 통신 구현 //
    printf("-----------------------------\n");
    // USART 통신 구현부
    while(1)
        {
            printf("main while start\n");
            motor2_close();
            Receive_data = 'N';
            delay_m();
            motor2_sensing();
            delay_m();
            while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);    
                USART_SendData(USART3, Send_data);  
            delay_m();
            while (USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET);    // 3. RXNE는 RX Not Empty로, USART3 Rx의 Tmp 공간에 값이 들어왔는지 확인한다.
                Receive_data = USART_ReceiveData(USART3);                         // 4. USART3 Rx의 Tmp공간에 값이 들어왔으면, 해당 값을 변수(Receive_data)로 받아 통신을 완료시킨다.

            printf("Received data is %c\n", Receive_data);
            printf("-----------------------------\n");
            if(Receive_data!='N')
            {
                while(1)
                   { if(motor(Receive_data)==1){break;}}
               printf("main while end\n");
               delay_m();
           }
        }
    
}
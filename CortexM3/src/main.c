#include "stm32f10x.h"
#include "SPI_define.h"     // SPI1, SPI2�� ���� ����� �� �ֵ��� ������ �κ�
//#include "USART_define.h"

#include <stdio.h>

/*
    �� ������Ʈ�� USART3�� Tx, Rx�� �̿��� �ڰ���� ���� ������Ʈ�̴�.
    USART3�� SPI�� ���������� Serial �������, Tx, Rx�� �����Ǿ��ִ�.
    �ٸ� SPI�� �ٸ��� Master/Slave ������ �ƴϱ� ������ MISO, MOSI�� Pin�� �������� �ʰ� Tx, Rx�� Pin�� �����Ѵ�.
     (���� SPI����� SPIy(Master), SPIz(Slave)�� �������, USART�� ġ�� USART1, USART3 ������ ����̿���. ������ �� ������Ʈ������ USART3 �ϳ��� �̿��� ��� ������� �����Ǿ���.)
*/

// TIM
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure_PWM;




void RCC_Configuration(void);
void GPIO_Configuration(void);
//void NVIC_Configuration(void);
void TIM_Configuration(void);
//void EXTI_Configuration(void);
void USART1_Configuration(); //Printf�� ���
void USART3_Configuration();
//void SPIy_Master_Configuration(void);
//void SPIz_Slave_Configuration(void);

// USART ��ſ� ����� ���� ������
//uint8_t Send_data = 11;
char Receive_data = 'N';
char Send_data = 3;
int motor(char R_data);
void motor2_close();
int main(void)
{
    //RCC �ʱ�ȭ
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



    // USART3�� ��� ���� //     // USART3�� ��� ���� //     // USART3�� ��� ���� //
    // USART3�� ��� ���� //     // USART3�� ��� ���� //     // USART3�� ��� ���� //
    // USART3�� ��� ���� //     // USART3�� ��� ���� //     // USART3�� ��� ���� //
    // USART3�� ��� ���� //     // USART3�� ��� ���� //     // USART3�� ��� ���� //
    printf("-----------------------------\n");
    // USART ��� ������
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
            while (USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET);    // 3. RXNE�� RX Not Empty��, USART3 Rx�� Tmp ������ ���� ���Դ��� Ȯ���Ѵ�.
                Receive_data = USART_ReceiveData(USART3);                         // 4. USART3 Rx�� Tmp������ ���� ��������, �ش� ���� ����(Receive_data)�� �޾� ����� �Ϸ��Ų��.

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
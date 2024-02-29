
/*
!!! Primary linker script file generated automatically !!!
This file contains the input and output files names
It also includes the secondary/main linker script that is specified in the Ride options (default or custom)
*/

SEARCH_DIR(".")
SEARCH_DIR("C:\Users\qwe92\Desktop\project\obj")
SEARCH_DIR("C:\Program Files (x86)\Raisonance\Ride\Lib\ARM")
INPUT("C:\Users\qwe92\Desktop\project\obj\main.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_it.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\SPI_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\EXTI_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\USART_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\TIM_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\NVIC_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\RCC_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\GPIO_config.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\motor.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\delay.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\system_stm32f10x.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\startup_stm32f10x_md.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\misc.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_spi.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_exti.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_flash.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_tim.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_gpio.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_usart.o")
INPUT("C:\Users\qwe92\Desktop\project\obj\stm32f10x_rcc.o")
EXTERN( __io_putchar )
EXTERN( _write )
GROUP(
"STM32x_io_putchar_thumb.a"
"std_sbrk_thumb.lib"
"smallprintf_thumb.a"
"libc.a"
"libm.a"

)
INCLUDE "C:\Users\qwe92\Desktop\project\obj\STM32F103_128K_20K_FLASH.ld"
OUTPUT("C:\Users\qwe92\Desktop\project\Application0.elf")

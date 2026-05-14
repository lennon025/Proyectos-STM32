#include "stm32f4xx.h"

volatile uint32_t tick = 0;

void SysTick_Handler(void) {
    tick++;
}

int main(void) {
    // Configurar LED
    RCC->AHB1ENR |= (1 << 1);
    GPIOB->MODER = (GPIOB->MODER & ~(3 << 24)) | (1 << 24);
    GPIOB->OTYPER &= ~(1 << 12);
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~(3 << 24)) | (1 << 24);
    
    // Configurar SysTick
    SysTick_Config(SystemCoreClock / 1000);
    
    uint32_t ultimo = 0;
    uint32_t estado = 0;
    
    while(1) {
        if((tick - ultimo) >= 500) {    // Espera 500 ms
        ultimo = tick;
            if(estado == 0) {
                GPIOB->BSRR = (1 << 12);     // Solo encender
                estado = 1;
            } else {
                GPIOB->BSRR = (1 << 28);    // Solo apagar
                estado = 0;
            }
    
        }
    }
}
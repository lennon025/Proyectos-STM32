#include "stm32f4xx.h"

volatile uint32_t tick = 0;

void SysTick_Handler(void) {
    tick++;
}

int main(void) {
    // Activar reloj GPIOB
    RCC->AHB1ENR |= (1 << 1);
    
    // Configurar PB13 (ROJO)
    GPIOB->MODER = (GPIOB->MODER & ~(3 << 26)) | (1 << 26);
    GPIOB->OTYPER &= ~(1 << 13);
    
    // Configurar PB14 (VERDE)
    GPIOB->MODER = (GPIOB->MODER & ~(3 << 28)) | (1 << 28);
    GPIOB->OTYPER &= ~(1 << 14);
    
    // Configurar PB15 (AMARILLO)
    GPIOB->MODER = (GPIOB->MODER & ~(3 << 30)) | (1 << 30);
    GPIOB->OTYPER &= ~(1 << 15);
    
    // Configurar SysTick
    SysTick_Config(SystemCoreClock / 1000);
    
    uint32_t ultimo_rojo = 0;
    uint32_t ultimo_verde = 0;
    uint32_t ultimo_amarillo = 0;
    
    while(1) {
        // ROJO se enciende al inicio (0ms)
        if((tick - ultimo_rojo) >= 0 && ultimo_rojo == 0) {
            ultimo_rojo = tick;
            GPIOB->BSRR = (1 << 13);   // ROJO encender
            GPIOB->BSRR = (1 << 30);   // VERDE apagar
            GPIOB->BSRR = (1 << 31);   // AMARILLO apagar
        }
        
        // VERDE se enciende a los 600ms
        if((tick - ultimo_verde) >= 600 && ultimo_verde == 0) {
            ultimo_verde = tick;
            GPIOB->BSRR = (1 << 14);   // VERDE encender
            GPIOB->BSRR = (1 << 29);   // ROJO apagar
            GPIOB->BSRR = (1 << 31);   // AMARILLO apagar
        }
        
        // AMARILLO se enciende a los 600ms
        if((tick - ultimo_amarillo) >= 1200 && ultimo_amarillo == 0) {
            ultimo_amarillo = tick;
            GPIOB->BSRR = (1 << 15);   // AMARILLO encender
            GPIOB->BSRR = (1 << 29);   // ROJO apagar
            GPIOB->BSRR = (1 << 30);   // VERDE apagar
        }
        
        // REINICIAR CICLO después de 1800ms (resetea las banderas)
        if(tick >= 1800) {
            tick = 0;
            ultimo_rojo = 0;
            ultimo_verde = 0;
            ultimo_amarillo = 0;
        }
    }
}

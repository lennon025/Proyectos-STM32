#include "stm32f4xx.h"

int main(void) {
    // Activar reloj de GPIOA
    RCC->AHB1ENR |= (1 << 0);
    RCC->AHB1ENR |= (1 << 1);

    // Configurar PA0 como entrada con pull-up
    GPIOA->MODER &= ~(3 << 0);           // entrada
   // GPIOB->MODER &= ~(3 << 10);           // entrada PB5
    GPIOA->PUPDR = (GPIOA->PUPDR & ~(3 << 0)) | (1 << 0);  // pull-up
    
    // Configurar PA5 como salida (LED)
    GPIOA->MODER = (GPIOA->MODER & ~(3 << 10)) | (1 << 10);
    GPIOA->OTYPER &= ~(1 << 5);
    //Configura PB5 como salida led
    GPIOB->MODER = (GPIOB->MODER & ~(3 << 10)) | (1 << 10);
    GPIOB->OTYPER &= ~(1 << 5);

    while(1) {
        // Si botón pulsado (PA0 = 0), enciende LED
        if(((GPIOA->IDR >> 0) & 1) == 0) {
            GPIOA->BSRR = (1 << 5);     // Encender
            GPIOB->BSRR = (1 << 21);     // APAGAR
        } else {
            GPIOA->BSRR = (1 << 21);    // Apagar
            GPIOB->BSRR = (1 << 5);    // Encender
        }
        
        for(int i = 0; i < 10000; i++);
    }
}
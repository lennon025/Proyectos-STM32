# Semáforo con temporización no bloqueante

Proyecto que implementa un semáforo con tres LEDs (rojo, verde, amarillo) usando **SysTick** como temporizador no bloqueante.  
Sin HAL, sin delay bloqueante. C puro sobre registros.

---

## 🔌 Conexión

| Componente | Pin |
|------------|-----|
| LED Rojo | PB13 |
| LED Verde | PB14 |
| LED Amarillo | PB15 |

---

## 🚦 Secuencia del semáforo

| Tiempo (ms) | ROJO (PB13) | VERDE (PB14) | AMARILLO (PB15) |
|-------------|-------------|--------------|-----------------|
| 0 | 			🟢  ENCENDIDO | ⚫ apagado    | ⚫ apagado |
| 600 | 		⚫ apagado 	 | 🟢  ENCENDIDO  | ⚫ apagado |
| 1200 | 		⚫ apagado   | ⚫ apagado    | 🟢  ENCENDIDO |
| 1800 | (se repite ciclo) | | |

# Светофор с неблокирующей синхронизацией

Проект реализует светофор с тремя светодиодами (красный, зеленый, желтый) с использованием **SysTick** в качестве неблокирующего таймера.  
Без HAL, без блокирующего delay. Чистый C поверх регистров.

---

## 🔌 Подключение

| Компонент | Вывод |
|-----------|-------|
| Красный LED | PB13 |
| Зеленый LED | PB14 |
| Желтый LED | PB15 |

---

## 🚦 Последовательность работы светофора

| Время (мс) | КРАСНЫЙ (PB13) | ЗЕЛЕНЫЙ (PB14) | ЖЕЛТЫЙ (PB15) |
|------------|----------------|----------------|---------------|
| 0 |            🟢  ВКЛЮЧЕН   | ⚫ выключен    | ⚫ выключен |
| 600 |          ⚫ выключен  | 🟢 ВКЛЮЧЕН      | ⚫ выключен |
| 1200 |         ⚫ выключен  | ⚫ выключен    | 🟡 ВКЛЮЧЕН |
| 1800 | (цикл повторяется) | | |

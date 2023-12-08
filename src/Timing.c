#include "Timing.h"


void TIMER_Init(TIMER* timer, TIM_HandleTypeDef* tim) {
    timer->_tim = tim;
    HAL_TIM_Base_Start(timer->_tim);
}

void TIMER_delayUS(TIMER* timer, uint16_t us) {
    //__disable_irq();
    timer->_tim->Instance->CNT = 0;
    while (timer->_tim->Instance->CNT < us);
    //__enable_irq();
}


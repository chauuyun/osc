#ifndef	_EXCEPTION_H_
#define	_EXCEPTION_H_

#include "u_list.h"

#define UART_IRQ_PRIORITY  1
#define TIMER_IRQ_PRIORITY 0

typedef struct irqtask
{
    struct list_head listhead;
    unsigned long long priority; // store priority (smaller number is more preemptive)
    void *task_function;         // task function pointer
} irqtask_t;

void irqtask_add(void *task_function, unsigned long long priority);
void irqtask_run(irqtask_t *the_task);
void irqtask_run_preemptive();
void irqtask_list_init();

// Appendix A: Defines P.19: https://github.com/Tekki/raspberrypi-documentation/blob/master/hardware/raspberrypi/bcm2836/QA7_rev3.4.pdf p16
#define CORE0_INTERRUPT_SOURCE ((volatile unsigned int*)(0x40000060)) //4,10: core interrupt source: 由這個暫存器去查找interrupt來源

#define INTERRUPT_SOURCE_CNTPNSIRQ (1<<1) // set bit1為1(CNTPNSIRQ interrupt)
#define INTERRUPT_SOURCE_GPU (1<<8)       // set bit8為1(GPU interrupt)

#define IRQ_PENDING_1_AUX_INT (1<<29)     // set bit29為1(Aux interrupt)

void el1_interrupt_enable();
void el1_interrupt_disable();

void el1h_irq_router();
void el0_sync_router();
void el0_irq_64_router();

void invalid_exception_router(); // exception_handler.S

#endif /*_EXCEPTION_H_*/

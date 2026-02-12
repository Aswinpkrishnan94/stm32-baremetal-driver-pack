#include <stdint.h>

/* Stack top defined in linker script */
extern uint32_t _estack;

/* Core exception handlers */
void Reset_Handler(void);
void NMI_Handler(void)            __attribute__((weak));
void HardFault_Handler(void)      __attribute__((weak));
void MemManage_Handler(void)      __attribute__((weak));
void BusFault_Handler(void)       __attribute__((weak));
void UsageFault_Handler(void)     __attribute__((weak));
void SVC_Handler(void)            __attribute__((weak));
void DebugMon_Handler(void)       __attribute__((weak));
void PendSV_Handler(void)         __attribute__((weak));
void SysTick_Handler(void)        __attribute__((weak));

/* Default handler */
void Default_Handler(void)
{
    while (1)
    {
        __asm__("bkpt 0");
    }
}

/* Weak aliases */
void NMI_Handler(void)        { Default_Handler(); }
void HardFault_Handler(void)  { Default_Handler(); }
void MemManage_Handler(void)  { Default_Handler(); }
void BusFault_Handler(void)   { Default_Handler(); }
void UsageFault_Handler(void) { Default_Handler(); }
void SVC_Handler(void)        { Default_Handler(); }
void DebugMon_Handler(void)   { Default_Handler(); }
void PendSV_Handler(void)     { Default_Handler(); }
void SysTick_Handler(void)    { Default_Handler(); }

/*
 * Interrupt Vector Table
 * Placed at start of Flash via linker section
 */
__attribute__((section(".isr_vector")))
const void *vector_table[] =
{
    /* Core Exceptions */
    (void *)&_estack,       /* Initial Stack Pointer */
    Reset_Handler,          /* Reset Handler */
    NMI_Handler,            /* NMI */
    HardFault_Handler,      /* Hard Fault */
    MemManage_Handler,      /* MPU Fault */
    BusFault_Handler,       /* Bus Fault */
    UsageFault_Handler,     /* Usage Fault */
    0, 0, 0, 0,             /* Reserved */
    SVC_Handler,            /* SVCall */
    DebugMon_Handler,       /* Debug Monitor */
    0,                      /* Reserved */
    PendSV_Handler,         /* PendSV */
    SysTick_Handler,        /* SysTick */

    [16 ... 255] = Default_Handler
};
	

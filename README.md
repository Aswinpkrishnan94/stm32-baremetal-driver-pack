Register-level STM32 driver pack designed to demonstrate firmware ownership from reset to application.

Primary target: STM32H7
Secondary target: STM32F4
Approach: Bare-metal first (no HAL)

Architecture Overview
  Reset_Handler
        ↓
  system_init()
        ↓
  Application
        ↓
  BSP (Board Support)
        ↓
  Drivers (RCC, GPIO)
        ↓
  Hardware Registers

  Design principles:
    1) No vendor HAL or auto-generated code
    2) Layered architecture
    3) Board-independent application
    4) Deterministic initialization
    5) Minimal and scalable drivers




**Week 1 – Core Bring-up**

    Custom startup code (vector table, Reset_Handler)
    Manual .data and .bss initialization
    Custom linker script (Flash/RAM layout)
    
    System entry structure:
    Reset_Handler → system_init() → main()



**Week 2 - Driver Foundation**

    Core
        Memory map (core/memory_map.h)
        System initialization layer (core/system)
    
    Drivers
    RCC
        Peripheral clock enable
        Peripheral reset support
        Read-back synchronization
    GPIO
        Pin initialization
        Read / Write / Toggle
        Atomic output using BSRR
    
    BSP
        Board abstraction (bsp/board)
        LED mapped to PA5
        Application does not access registers directly
    
    Example
        examples/led_blink
        Demonstrates full boot → BSP → driver → hardware flow.

**Week 3**
        Day 1 - bit macros

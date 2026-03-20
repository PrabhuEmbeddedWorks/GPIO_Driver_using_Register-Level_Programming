# Reusable GPIO Driver using Register-Level Programming (STM32 + Keil Simulation)

## 1. Project Overview

This project demonstrates how to design a reusable GPIO driver using register-level programming while maintaining portability and modularity. The simulation approach ensures functionality can be validated even in the absence of physical hardware.

---

## 2. Objectives

- Develop a reusable GPIO driver module
- Implement register-level programming concepts
- Maintain modular structure using header and source files
- Simulate GPIO behavior without hardware
- Demonstrate abstraction similar to a Hardware Abstraction Layer (HAL)

---

## 3. Tools and Environment

| Tool | Description |
|------|------------|
| Keil µVision (MDK-ARM) | IDE with built-in simulator |
| STM32F1xx Device Pack | Provides STM32F103 support |
| ARM CMSIS | Cortex-M core support |
| Language | Embedded C |

---

## 4. Project Structure

```

GPIO_DRIVER_KEIL/
│
├── main.c
├── gpio_driver.c
├── gpio_driver.h
│
├── RTE/
├── Objects/
└── Listings/

```

---

## 5. Installation and Setup

### Step 1: Install Keil µVision

1. Download MDK-ARM from official Keil website
2. Install using default settings
3. Launch µVision IDE

---

### Step 2: Install Required Packs

Open:

```

Project → Manage → Pack Installer

```

Install the following:

- Keil::STM32F1xx_DFP
- ARM::CMSIS

Ensure both show status as:

```

Up to date

```

---

## 6. Project Creation

### Step 3: Create New Project

```

Project → New µVision Project

```

- Create a new folder named `GPIO_DRIVER_KEIL`
- Save the project

---

### Step 4: Select Target Device

Navigate to:

```

STMicroelectronics → STM32F1 Series → STM32F103 → STM32F103C8

```

Click OK.

---

### Step 5: Configure Run-Time Environment (RTE)

In the RTE window, select:

- CMSIS → CORE
- Device → Startup

Do not select any middleware, RTOS, or additional drivers.

Click OK.

---

## 7. Project Configuration

### Step 6: Enable Simulator

Open:

```

Project → Options for Target (Alt + F7)

```

Under Debug tab:

- Select "Use Simulator"
- Ensure no hardware debugger is selected

---

### Step 7: Disable Flash Programming

Under Utilities tab:

- Uncheck "Use Target Driver for Flash Programming"

Click OK.

---

## 8. File Creation

### Step 8: Add Source Files

Right-click on:

```

Source Group 1 → Add New Item

```

Create the following files:

- main.c
- gpio_driver.c
- gpio_driver.h

---

## 9. Simulation Adjustment

Due to simulator limitations, remove hardware-dependent files:

- startup_stm32f10x.s
- system_stm32f10x.c

Right-click each file and select "Remove".

---

## 10. Build Project

### Step 9: Build

```

Project → Build Target (F7)

```

Expected result:

```

Build Finished. 0 Errors

```

---

## 11. Run Simulation

### Step 10: Start Debug Session

```

Debug → Start/Stop Debug Session

```

or press:

```

Ctrl + F5

```

---

### Step 11: Run Program

```

Run → Run (F5)

```

The program will now execute continuously.

---

## 12. Output Verification

### Step 12: Open Watch Window

```

View → Watch Window → Watch 1

```

---

### Step 13: Add Expression

Double-click on `<Enter expression>` and add:

```

GPIOA_ODR_SIM

```

---

### Step 14: Observe Output

The value will toggle continuously:

```

0x00000000
0x00000020
0x00000000
0x00000020

```

---

## 13. Output Explanation

### Bit-Level Analysis

| Value | Binary | Description |
|------|--------|------------|
| 0x00000000 | 00000000 | Pin LOW |
| 0x00000020 | 00100000 | Pin 5 HIGH |

---

### Behavior

```

LOW → HIGH → LOW → HIGH

```

This represents periodic toggling of GPIO pin 5, equivalent to LED blinking.

---

### Why 0x20?

```

(1 << 5) = 32 = 0x20

```

This corresponds to setting bit position 5.

---

## 14. Design Features

- Modular driver architecture
- Separation of application and hardware layers
- Register-level control using bitwise operations
- Reusable and portable design
- Clean API interface for GPIO operations

---

## 15. Simulation Strategy

### Problem

Keil simulator does not support direct access to STM32 peripheral registers.

### Solution

A software-simulated register variable is used:

```

GPIOA_ODR_SIM

```

This mimics the behavior of the actual GPIO output data register.

---

## 16. Verification Method

The GPIO driver was verified by observing the simulated register value in the Watch window during execution. The alternating values confirm correct toggle functionality.

---

## 17. Key Takeaways

- Register-level programming provides precise control over hardware
- Modular design improves reusability and maintainability
- Simulation requires abstraction when hardware is unavailable
- Bitwise operations are fundamental in embedded systems

---

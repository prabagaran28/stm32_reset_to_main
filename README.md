# stm32_reset_to_main
booting stm32f1 bulephill from srach using gnu toolchain 
bare minial setup to   run c code . not using standard lib and newlib
 * On-chip flash 32kb
 * on-chip ram 10kb
 * STM32F103c6t6

![img](https://github.com/prabagaran28/stm32_reset_to_main/blob/81539022e91b9031b348da0e93c03e85825ad277/STM32F103-Blue-Pill-1536x1000.jpg)
* VS Code with the Cortex-Debug extension
## Compiling with custom linker script and startup file


https://github.com/user-attachments/assets/a5ba96fe-dcf0-4c83-9710-8d489af78b7c


If you want to link your program without the default C library (`libc`), startup files, and linker script, you can use the following `arm-none-eabi-gcc` command:

```bash
arm-none-none-eabi-gcc -mcpu=cortex-m3 -mthumb -std=c11 -O0 -g -c main.c -o main.o
arm-none-none-eabi-gcc -mcpu=cortex-m3 -mthumb -std=c11 -O0 -g -c crt.c -o crt.o
arm-none-none-eabi-gcc -nolibc -nostartfiles -T linker.ld -Wl,-Map=blink.elf main.o crt.o -o blink.elf
```















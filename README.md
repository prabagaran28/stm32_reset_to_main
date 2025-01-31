# stm32_reset_to_main
booting stm32f1 bulephill from srach using gnu toolchain 
bare minial setup to   run c code . not using standard lib and newlib
## Compiling with custom linker script and startup file

If you want to link your program without the default C library (`libc`), startup files, and linker script, you can use the following `arm-none-eabi-gcc` command:

```bash
arm-none-none-eabi-gcc -mcpu=cortex-m3 -mthumb -std=c11 -O0 -g -c main.c -o main.o
arm-none-none-eabi-gcc -mcpu=cortex-m3 -mthumb -std=c11 -O0 -g -c crt.c -o crt.o
arm-none-none-eabi-gcc -nolibc -nostartfiles -T linker.ld -Wl,-Map=blink.elf main.o crt.o -o blink.elf



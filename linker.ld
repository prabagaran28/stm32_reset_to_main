
MEMORY 
{
    flash(rx): ORIGIN = 0x08000000, LENGTH = 32k
    ram(rwx): ORIGIN = 0x20000000, LENGTH =  10k
}

__estack = ORIGIN(ram)+ LENGTH(ram);

SECTIONS 
{
    .text :
    {      . = ALIGN(4);
          __stext = ABSOLUTE(.);
            boot.o(.ivt)
             *(.text)
        . = ALIGN(4);
        __etext = ABSOLUTE(.);

    }>flash 

    .data :
    {    . = ALIGN(4);
          __sdata = ABSOLUTE(.);
           *(.data)
           . = ALIGN(4);
           __edata = ABSOLUTE(.);
    }>ram AT>flash 

    .bss :
    {   
        . = ALIGN(4);
        __sbss = ABSOLUTE(.);
        *(.bss)
        . = ALIGN(4);
        __ebss = ABSOLUTE(.);
        

    }>ram
}
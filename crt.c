extern int main(void);
extern unsigned int __estack;
extern unsigned int __sdata;
extern unsigned int __edata;
extern unsigned int __etext;
extern unsigned int __sbss;
extern unsigned int __ebss;
void Reset_Handler(void);
void nmi_Handler(void);
void Hard_Handler(void);
void copy_to_data(void);
void fill_bss(void);
#define TOTAL_VECTOR (59U)
typedef void (*fptr_t)(void);

__attribute((used,section(".ivt")))
fptr_t tables[TOTAL_VECTOR]= {
    (fptr_t)&__estack,
    Reset_Handler,
    nmi_Handler,
    Hard_Handler
};

void Reset_Handler()
{
    copy_to_data();
    fill_bss();
    main();
}
void nmi_Handler()
{
    while(1);
}
void Hard_Handler()
{
    while(1);
}

void fill_bss()
{ unsigned int *ptr_bss = &__sbss;
    while(ptr_bss < &__ebss)
    {
           *ptr_bss++ = 0;
    }
}
void copy_to_data()
{
    unsigned int *src_ptr = &__etext;
    unsigned int *dsc_ptr = &__sdata;
    while( dsc_ptr< &__edata)
    {
        *dsc_ptr++ = *src_ptr++ ;
    }
}
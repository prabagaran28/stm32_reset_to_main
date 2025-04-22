 extern unsigned int __estack;
 extern unsigned int __sdata;
 extern unsigned int __edata;
 extern unsigned int __sbss;
 extern unsigned int __ebss;
extern unsigned int __etext;
extern unsigned int main(void);
 #define IVT (49)
 void nmi_handler(void); 
 void haultfault_handler(void);
void reset_handler(void);
 typedef void (*fpointer)(void);

 __attribute__((used,section(".ivt")))
 static const fpointer table[IVT]={
        (fpointer)&__estack,
        reset_handler,
        nmi_handler,
        haultfault_handler,

 };

 void reset_handler()
 {
     unsigned int *sptr;
     unsigned int *dptr;
     sptr =&__sdata;
     dptr =&__etext;
     for(; sptr<&__edata;)
     {
         *sptr++ = *dptr++;
     }
      sptr = &__sbss;
     for(; sptr<&__ebss;)
     {
          *sptr++ = 0;
     }
     #define NVIC_CCR *((volatile unsigned int *)(0xE000ED14)) 
     NVIC_CCR |= 0x200;
     main();
     while(1)
     {
        
     }

     
 }

 void haultfault_handler()
 {
    while(1);
    
 }
 void nmi_handler()
 {
    while(1);
 }
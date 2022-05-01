#include<16f877.h>

#device ADC=10;

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(d)

#define use_portb_lcd TRUE
#include<lcd.c>

unsigned long int i=0, aci=0;

void servo(unsigned long int b,c){

output_high(pin_d7);
delay_us(550+b); // PWM dolu kýsým
output_low(pin_d7);
delay_us(19450-b); // PWM dolu kýsmý 20ms tamamlayacak kýsým
printf(lcd_putc,"\fAci = %u Derece",c);
continue;

}

void main(){
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);

setup_adc_ports(ALL_ANALOG);
setup_adc(adc_clock_div_32);
set_adc_channel(0);

set_tris_a(0x01);
set_tris_d(0x00);
set_tris_b(0x00);

output_b(0x00);
output_d(0x00);

lcd_init();

while(true){

i = read_adc();
aci = i*2/11.1;
i=i*2;
servo(i,aci);

}

}












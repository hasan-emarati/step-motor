////////// WWW.EMIC.IR //////////
#include <mega16.h>
#include <delay.h>

void main(void)
{
unsigned char step[8]={0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09};
int i ;
int round=0;
int bala = 1;
int play = 0;

DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
  DDRB=0xff;
  DDRD=0x00;
  DDRA=0xff;
while (1)
 {

          if(bala==0 && play==1){
         for(i=0;i<=7;i++)
          {
           PORTC=step[i];
           delay_ms(100);

              if(PIND.1==0)
                  {
                       bala=1;
                        play=0;
                         PORTA.0=0;PORTA.1=1;

                    }



            if(i==7)
               {
                      round=round+1;
                }
          }
     }


         if(bala==1 && round!=0){
         for(i=7;i>=0;i--)
          {
           PORTC=step[i];
           delay_ms(100);

            if(PIND.1==0)
                  {
                       bala=1;
                        play=0;
                         PORTA.0=0;PORTA.1=1;

                    }
            if(i==0)
               {
                      round=round-1;
                }
          }

     }

     PORTB=round;

       if(round==7 ){bala=1;}
       if(round==0 ){bala=0;}
       if(PIND.0==0)
       {
       bala=0;
       PORTA.0=1;PORTA.1=0;
       play=1;
         delay_ms(1000);
       }





 }



}
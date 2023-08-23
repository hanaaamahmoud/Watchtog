

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "TIMER_TEST_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>

/**************************** Watch Dog************************/
  void WDT_voidEnable(void);
  void WDT_voidDisable(void);
  void WDT_voidSleep(u8 Copy_u8Value);




  int main()
 {
	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN7,DIO_PIN_OUT);

	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH);

	_delay_ms(1000);

	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW);
	WDT_voidEnable();
	WDT_voidSleep(6);

  }

  void WDT_voidSleep(u8 Copy_u8Value)
 {
  WDTCR&=0b11111000;
 WDTCR|=Copy_u8Value;
}
  void WDT_voidEnable(void)
  {
	SET_BIT(WDTCR,WDE);
  }
  void WDT_voidDisable(void)
{
  WDTCR|=0b00011000;
WDTCR=0;
}
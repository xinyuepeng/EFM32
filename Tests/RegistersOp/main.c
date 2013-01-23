#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"

int main(void)
{
  /* Chip errata */
  CHIP_Init();
  
  /* Ensure core frequency has been updated */
  //SystemCoreClockUpdate();
  
  /* enable timer0 clock */
  CMU->HFPERCLKEN0 |= CMU_HFPERCLKEN0_TIMER0;
  
  /* start the timer */
  TIMER0->CMD = 1;
  /* count the 1000 */
  while(TIMER0->CNT < 1000);
  
  while(1)
    ;
  
  return 0;
}
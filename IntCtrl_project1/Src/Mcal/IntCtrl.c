#include "IntCtrl.h"
#include "BIT_math.h"
#include "IntCtrl_Cfg.h"

void IntCtrl_init(void)
{
	/*APINT reg group priority*/
	
	APINT_R = 0x05FA0000 | (PRIGROUP_VALUE<<PRIGROUP_START);

}

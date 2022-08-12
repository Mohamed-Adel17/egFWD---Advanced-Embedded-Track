#include "IntCtrl.h"
#include "BIT_math.h"
#include "IntCtrl_Cfg.h"
void IntCtrl_init(void)
{
	/*APINT reg group priority*/
	SET_BITS_VALUE(APINT_R,VECTKEY_START,VECTKEY_LEN,VECTKEY_VALUE)
	SET_BITS_VALUE(APINT_R,PRIGROUP_START,PRIGROUP_LEN,PRIGROUP_VALUE)
}

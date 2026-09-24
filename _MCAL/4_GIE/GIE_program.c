/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< GIE_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 18, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : GIE
 */


#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"
#include "../../_MCAL/4_GIE/GIE_interface.h"
#include "../../_MCAL/4_GIE/GIE_private.h"

/*
 * Breif : This Function used to enable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I) ;
}
/*
 * Breif : This Function used to disable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_VoidDisable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}

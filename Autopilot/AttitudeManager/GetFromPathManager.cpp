#include "GetFromPathManager.hpp"

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/


#ifndef SIMULATION

// dummy implementation until real one is required.
PMError_t PM_GetCommands(PMCommands *Commands)
{
	(void) Commands;

	PMError_t errorStruct;
	errorStruct.errorCode = 0;

	return errorStruct;
}

#else

#endif

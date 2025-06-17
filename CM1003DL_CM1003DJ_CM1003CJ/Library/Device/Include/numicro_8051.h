
/* for Keil */
#if defined __C51__
#include "cm1003_64k_keil.h"

/* for IAR */
#elif defined __ICC8051__
#include "cm1003_64k_iar.h"

/* for SDCC */
#elif defined __SDCC__
#include "cm1003_64k_sdcc.h"

#endif

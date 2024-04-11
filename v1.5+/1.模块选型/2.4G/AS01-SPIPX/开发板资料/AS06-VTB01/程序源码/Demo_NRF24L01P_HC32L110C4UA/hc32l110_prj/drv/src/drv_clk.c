#include "drv_clk.h"

void SystemClkConfig(void)
{
	Clk_SwitchTo(ClkRCL);
    Clk_SetRCHFreq(ClkFreq22_12Mhz);
    Clk_SwitchTo(ClkRCH);
}

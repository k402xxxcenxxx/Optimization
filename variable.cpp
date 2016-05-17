#include "variable.h"
variable::variable()
{
	coefficient = 0.0;
	powerX = 0.0;
	powerY = 0.0;
}

variable::~variable()
{
}
variable variable::PartialDifferentiation(symbol s)
{
	variable v = variable();

	if (s == x) {
		v.coefficient = coefficient * powerX;
		v.powerX = powerX - 1;

		v.zerolization();
	}
}
void variable::zerolization() {
	if (coefficient <= 1.0e-31) {
		powerX = 0.0;
		powerY = 0.0;
	}
}
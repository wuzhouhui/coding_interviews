#include <math.h>
#include <stdlib.h>

static double do_pow(double base, unsigned long exp)
{
	if (exp == 0)
		return(1);
	if (exp == 1)
		return(base);
	if (exp % 2)
		return(do_pow(base, exp - 1) * base);
	base = do_pow(base, exp / 2);
	return(base * base);
}

double power(double base, int exp)
{
	if (fabs(base) <= 1e-5 && exp <= 0)
		abort();
	unsigned long ulexp;
	if (exp < 0)
		ulexp = -(long int)exp;
	else
		ulexp = exp;
	base = do_pow(base, ulexp);
	return(exp < 0 ? 1 / base : base);
}

int main(void)
{
}

#include "Debug.h"

int main()
{
	double x = 2;

	DBG_WRITE("test : x : %f", x);

	EXPR_VAL(x*x + 2);

	ASSERT(x == 0, "x : %f", x);
}

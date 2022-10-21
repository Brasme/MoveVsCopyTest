#include "big.h"
#include <string.h>

#pragma warning( disable : 4996)

#if PRODUCT==PRODUCT_A
void big_init_product_default(big_t* big)
{
	if (big == NULL)
		return;

	strncpy(big->productA, "Product A stuff",BIG_PRODUCT_A_STR_SIZE);
}
#endif

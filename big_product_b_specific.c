#include "big.h"
#include <string.h>

#if PRODUCT==PRODUCT_B
void big_init_product_default(big_t* big)
{
	if (big == NULL)
		return;
	strncpy(big->productB, "Product B stuff", BIG_PRODUCT_B_STR_SIZE);
}
#endif
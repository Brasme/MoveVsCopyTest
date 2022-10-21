#include "big.h"

Big::Big()
{
}
Big::Big(uint64_t counter)
{
	big_init(&big, counter);
}
Big& Big::set_language(char* languageStr)
{
	big_set_language(&big, languageStr);
	return *this;
}

Big& Big::set_counter(uint64_t counter)
{
	big_set_counter(&big, counter);
	return *this;
}

Big& Big::set_debug(char* debugStr)
{
	big_set_debug(&big, debugStr);
	return *this;
}

Big& Big::init_product_default()
{
	big_init_product_default(&big);
	return *this;
}

Big& Big::init(uint64_t counter)
{
	big_init(&big, counter);
	return *this;
}

Big Big::create(uint64_t counter)
{
	Big big(counter);
	return big;
}

Big Big::create_and_update(uint64_t counter)
{
	Big big = create(counter);
	big.big.languageStr[0] = 'C';
	return big;
}


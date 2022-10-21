#pragma once

#define PRODUCT_A 423456
#define PRODUCT_B 423789

#define _KM_STR(x) #x 
#define KM_STR(x) _KM_STR(x)
#define KM_MESSAGE(MSG) __pragma(message(__FILE__ "(" KM_STR(__LINE__) "):" KM_STR(MSG)))

#ifndef PRUDUCT
KM_MESSAGE(WARNING: The compiler definition PRODUCT should be defined - see the product.h file reg numbers defaults to PRODUCT_A)
#define PRODUCT PRODUCT_A
#elif PRODUCT==PRODUCT_A
KM_MESSAGE("OK: Product = " PRODUCT_A " (product A)")
#elif PRODUCT==PRODUCT_B
KM_MESSAGE("OK: Product = " PRODUCT_B " (product B)")
#else
KM_MESSAGE("WARNING: Product = " PRODUCT " (unknown, revert to product A)")
#undef PRODUCT
#define PRODUCT PRODUCT_A
#endif

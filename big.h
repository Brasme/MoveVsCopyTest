#pragma once

#include "product.h"
#include <stdint.h> /* uint64_t */

#ifdef __cplusplus
extern "C" {
#endif

#if PRODUCT==PRODUCT_A
	#define BIG_SIZE 1024
	#define BIG_LANGUAGE_STR_SIZE 16
	#define BIG_COUNTER_STR_SIZE 16
	#define BIG_DEBUG_STR_SIZE 16
	#define BIG_PRODUCT_A_STR_SIZE 16
	#define BIG_PADDING_SIZE (BIG_SIZE-BIG_LANGUAGE_STR_SIZE-sizeof(uint64_t)-BIG_COUNTER_STR_SIZE-BIG_DEBUG_STR_SIZE-BIG_PRODUCT_A_STR_SIZE)
	typedef struct {
		char languageStr[BIG_LANGUAGE_STR_SIZE];
		uint64_t counter;
		char counterHexStr[BIG_COUNTER_STR_SIZE];
		char debugStr[BIG_DEBUG_STR_SIZE];
		char productA[BIG_PRODUCT_A_STR_SIZE];
		char padding[BIG_PADDING_SIZE];
	} big_t;
#endif

#if PRODUCT==PRODUCT_B
	#define BIG_SIZE 1024
	#define BIG_LANGUAGE_STR_SIZE 16
	#define BIG_COUNTER_STR_SIZE 16
	#define BIG_DEBUG_STR_SIZE 16
	#define BIG_PRODUCT_B_STR_SIZE 16
	#define BIG_PADDING_SIZE (BIG_SIZE-BIG_LANGUAGE_STR_SIZE-sizeof(uint64_t)-BIG_COUNTER_STR_SIZE-BIG_DEBUG_STR_SIZE-BIG_PRODUCT_B_STR_SIZE)
	typedef struct {
		char languageStr[BIG_LANGUAGE_STR_SIZE];
		uint64_t counter;
		char counterHexStr[BIG_COUNTER_STR_SIZE];
		char debugStr[BIG_DEBUG_STR_SIZE];
		char productB[BIG_PRODUCT_B_STR_SIZE];
		char padding[BIG_PADDING_SIZE];
	} big_t;
#endif

	void big_set_language(big_t* big, char* languageStr);
	void big_set_counter(big_t* big, uint64_t counter);
	void big_set_debug(big_t* big, char* debugStr);
	
	void big_init_product_default(big_t* big);
	void big_init(big_t *big,uint64_t counter);

	big_t big_create(uint64_t counter);
	big_t big_create_and_update(uint64_t counter);

	char *big_dump(const big_t* big,char *dst,size_t dstSize);

#ifdef __cplusplus
}
#endif
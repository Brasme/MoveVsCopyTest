#include "big.h"
#include <stddef.h> // NULL
#include <stdio.h> // memset
#include <string.h>

static char* hexChar = "0123456789abcdef";
void big_set_language(big_t *big,char* languageStr)
{
    if (big == NULL)
        return;

    char* b = big->languageStr;
    unsigned i = 0;
    while (i < 15 && *languageStr!='\0') {
        *(b++) = *(languageStr++);
        ++i;
    }
    while (i < 16) {
        *b = '\0';
        ++i;
    }
}

void big_set_counter(big_t* big, uint64_t counter)
{
    if (big == NULL)
        return;
    big->counter = counter;
    char* b = big->counterHexStr;
    size_t i = BIG_COUNTER_STR_SIZE;
    while (i > 8) {
        --i;
        b[i] = '\0';    
    }
    while (i>0) {
        --i;
        b[i] = hexChar[counter & 0xf];
        counter = counter >> 4;
    }
    
}

void big_set_debug(big_t* big, char* debugStr)
{
    if (big == NULL)
        return;

    char* b = big->debugStr;
    unsigned i = 0;
    while (i < 15 && *debugStr != '\0') {
        *(b++) = *(debugStr++);
        ++i;
    }
    while (i < 16) {
        *b = '\0';
        ++i;
    }
}


void big_init(big_t *big,uint64_t counter)
{    
    if (big == NULL)
        return;
    big_set_language(big, "c");
    big_set_counter(big, counter);
    big_set_debug(big, "Level 2");
    big_init_product_default(big);
    memset((void*)big->padding, 0, BIG_PADDING_SIZE);    
}

big_t big_create(uint64_t counter)
{
    big_t big;    
    big_init(&big,counter);
    return big;
}

big_t big_create_and_update(uint64_t i)
{
    big_t big;
    big = big_create(i);
    big_set_language(&big, "C");
    return big;
}

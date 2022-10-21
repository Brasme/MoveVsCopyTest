
#include "big.h"
#include "gtest/gtest.h"
#include <chrono>

TEST(big_test, big_struct)
{
#if PRODUCT==PRODUCT_A
	EXPECT_EQ(BIG_SIZE, 1024);
	EXPECT_EQ(BIG_LANGUAGE_STR_SIZE, 16);
	EXPECT_EQ(BIG_COUNTER_STR_SIZE, 16);
	EXPECT_EQ(BIG_DEBUG_STR_SIZE, 16);
	EXPECT_EQ(BIG_PRODUCT_A_STR_SIZE, 16);
	EXPECT_EQ(BIG_PADDING_SIZE, 952);
	EXPECT_EQ(sizeof(big_t), BIG_SIZE);
	EXPECT_EQ(offsetof(big_t, languageStr),0);
	EXPECT_EQ(offsetof(big_t, counter), 16);
	EXPECT_EQ(offsetof(big_t, counterHexStr),16+8);
	EXPECT_EQ(offsetof(big_t, debugStr), 16+8+16);
	EXPECT_EQ(offsetof(big_t, productA), 16+8+16+16);
	EXPECT_EQ(offsetof(big_t, padding),  16+8+16+16+16);
#endif
}

size_t numCharsEqualTo(const char* b, char ch, size_t n)
{
	size_t num = 0;
	for (size_t i = 0; i < n; ++i) {
		if (b[i] == ch)
			num++;
	}
	return num;
}

TEST(big_test, big_create_and_update)
{
	big_t big;
	
	memset(&big,'@', BIG_SIZE);
	
	size_t numNotInitialized = numCharsEqualTo((char*)&big, '@', sizeof(big_t));
	EXPECT_EQ(numNotInitialized, BIG_SIZE);

	big= big_create_and_update(0x12345);
	
	numNotInitialized = numCharsEqualTo((char*)&big,'@',sizeof(big_t));
	EXPECT_EQ(numNotInitialized, 0);

	EXPECT_STREQ(big.languageStr, "C");
	EXPECT_EQ(big.counter, 0x12345);
	EXPECT_STREQ(big.counterHexStr, "00012345");
	EXPECT_STREQ(big.debugStr, "Level 2");
	EXPECT_EQ(numCharsEqualTo(big.padding, '\0', BIG_PADDING_SIZE),BIG_PADDING_SIZE);	
}

typedef std::chrono::high_resolution_clock perf_clock_t;
typedef perf_clock_t::time_point perf_time_t;
typedef std::chrono::duration<double> perf_duration_t;

TEST(big_test, big_c_performance_test) 
{
	perf_time_t t0 = perf_clock_t::now();
	perf_time_t t1 = perf_clock_t::now();
	
	big_t big = big_create_and_update(0);
	
	size_t N = 1000000;

	t0 = perf_clock_t::now();
	for (size_t n = 0; n < N; ++n) {
		big_t tmp = big_create_and_update(n);
		big.counter = tmp.counter;
	}
	t1 = perf_clock_t::now();

	perf_duration_t t = std::chrono::duration_cast<perf_duration_t>(t1 - t0);

	std::cout << "Time (N=" << N << "): " << t.count() << " seconds\n";
}
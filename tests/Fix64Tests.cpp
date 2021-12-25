#include "gtest/gtest.h"
#include "../src/utilities/Fix64.h"
#include "../src/fpm/fixed.hpp"

TEST(Fix64, Add) 
{
	Fix64 a(10.2);
	Fix64 b(21.67);
	Fix64 c = a + b;
	ASSERT_EQ(Fix64(31.87), c);
}

TEST(Fix64, Substract)
{
	Fix64 a(10.2);
	Fix64 b(21.67);
	Fix64 c = a - b;
	ASSERT_EQ(c, Fix64(-11.47));
}

TEST(Fix64, Multiply)
{
	Fix64 a(123.1234);
	Fix64 b(89.9867);
	Fix64 c = a * b;
	Fix64 d(11079.467559);
	ASSERT_EQ(d, c);
}

TEST(Fix64, Divide)
{
	Fix64 a(53.123);
	Fix64 b(21.67);
	Fix64 c = a / b;
	ASSERT_EQ(Fix64(2.451453), c);
}

TEST(Fix64, Sqrt)
{
	Fix64 a(256);
	Fix64 res;
	res = Fix64::Sqrt(a);
	ASSERT_EQ(Fix64(16), res);
}

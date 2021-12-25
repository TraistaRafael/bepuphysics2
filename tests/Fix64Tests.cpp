#include "gtest/gtest.h"
#include "../src/utilities/Fix64.h"
#include "../src/fpm/fixed.hpp"

TEST(Fix64, Add) 
{
	/*R128 a(10.2);
	R128 b(21.67);*/
	//R128 a(21.67);
	//R128 b(10.2);
	//R128 c = a - b;

	///*double t = -11.47;
	//double t2 = -11.470000000000000000000000000000;*/
	//R128 d(11.47);
	//bool res = (c == R128(-11.47));

	//fpm::fixed_16_16 a(10.2);
	//fpm::fixed_16_16 b(21.67);
	//fpm::fixed_16_16 c = a - b;
	//fpm::fixed_16_16 d = fpm::fixed_16_16(-11.47);

	//ASSERT_EQ(c, fpm::fixed_16_16(-11.47));

	/*bool res = false;
	ASSERT_TRUE(res);*/
	/*Fix64 a(10.2);
	Fix64 b(21.67);
	Fix64 c = a + b;
	ASSERT_EQ(Fix64(31.87), c);*/
}

TEST(Fix64, Substract)
{
	Fix64 a(10.2);
	Fix64 b(21.67);
	Fix64 c = a - b;

	cout << "diff: " << (string) c << "\n";
	cout << "check: " << (string) Fix64(-11.47) << "\n";

	ASSERT_EQ(c, Fix64(-11.47));
}

TEST(Fix64, Multiply)
{
	Fix64 a(1234.1234);
	Fix64 b(89.9988);
	Fix64 c = a + b;
	ASSERT_EQ(Fix64(111069.62505192), c);
}

TEST(Fix64, Divide)
{
	Fix64 a(53.123);
	Fix64 b(21.67);
	Fix64 c = a / b;
	ASSERT_EQ(Fix64(2.451453622519612), c);
}

TEST(Fix64, Sqrt)
{
	Fix64 a(256);
	Fix64 res;
	res = Fix64::Sqrt(a);
	ASSERT_EQ(Fix64(16), res);
}

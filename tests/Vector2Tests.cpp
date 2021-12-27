 #include "gtest/gtest.h"
 #include "../src/utilities/Vector2.h"

using namespace BEPUutilities;

 TEST(Vector2, Add) 
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a + b;

	 std::cout << c.ToString();
 	// ASSERT_EQ(Fix64(0.00000000023283064365386962890625), Fix64::Precision);
 }

 TEST(Vector2, Substract)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a - b;

	 std::cout << c.ToString();
	 // ASSERT_EQ(Fix64(0.00000000023283064365386962890625), Fix64::Precision);
 }


 TEST(Vector2, Multiply)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a + b;

	 std::cout << c.ToString();
	 // ASSERT_EQ(Fix64(0.00000000023283064365386962890625), Fix64::Precision);
 }

 TEST(Vector2, Divide)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a + b;

	 std::cout << c.ToString();
	 // ASSERT_EQ(Fix64(0.00000000023283064365386962890625), Fix64::Precision);
 }




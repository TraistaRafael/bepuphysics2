 #include "gtest/gtest.h"
 #include "../src/utilities/Vector2.h"

using namespace BEPUutilities;

 TEST(Vector2, Add) 
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a + b;
	 bool eq = Vector2(Fix64(9315695917262831616, 12), Fix64(3468637038141505536, 0)) == c;
 	 ASSERT_TRUE(eq);
 }

 TEST(Vector2, Substract)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a - b;
	 bool eq = Vector2(Fix64(18262276632972460032, 18446744073709551582), Fix64(14019525496019353600, 179)) == c;
	 ASSERT_TRUE(eq);
 }


 TEST(Vector2, Multiply)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 b(45.57, -123.56);
	 Vector2 c = a * b;
	 bool eq = Vector2(Fix64(6626070471276954898, 572), Fix64(17118578500393628598, 18446744073709544671)) == c;
	 ASSERT_TRUE(eq);
 }

 TEST(Vector2, Divide)
 {
	 Vector2 a(12.56, 56.2);
	 Vector2 c = a / Fix64(3);
	 bool eq = Vector2(Fix64(3443392227092452689, 4), Fix64(13527612320720355309, 18)) == c;
	 ASSERT_TRUE(eq);
 }




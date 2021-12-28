 #include "gtest/gtest.h"
 #include "../src/utilities/Vector3.h"

using namespace BepuUtilities;

 TEST(Vector3, Add) 
 {
	 Vector3 a(12.56, 56.2, 345.6);
	 Vector3 b(45.57, -123.56, 122.567);
	 Vector3 c = a + b;
	 bool eq = Vector3(Fix64(2398076729582256128, 58), Fix64(11805916207174123520, 18446744073709551548), Fix64(3080606260309786624, 468)) == c;
	 ASSERT_TRUE(eq);
 }

 TEST(Vector3, Substract)
 {
	 Vector3 a(12.56, 56.2, -4.678);
	 Vector3 b(45.57, -123.56, -87.009);
	 Vector3 c = a - b;
	 bool eq = Vector3(Fix64(18262276632972460032, 18446744073709551582), Fix64(14019525496019353600, 179), Fix64(6105872288397869056, 82)) == c;
	 ASSERT_TRUE(eq);
 }


 TEST(Vector3, Multiply)
 {
	 Vector3 a(12.56, 56.2, -4.678);
	 Vector3 b(45.57, -123.56, -87.009);
	 Vector3 c = a * b;
	 bool eq = Vector3(Fix64(6626070471276954898, 572), Fix64(17118578500393628598, 18446744073709544671), Fix64(518390401959312611, 407)) == c;
	 ASSERT_TRUE(eq);
 }

 TEST(Vector3, Divide)
 {
	 Vector3 a(12.56, 56.2, -4.678);
	 Vector3 c = a / Fix64(12.4);
	 bool eq = Vector3(Fix64(238022504176897636, 1), Fix64(9818428297297021204, 4), Fix64(11487561107837513006, 18446744073709551615)) == c;
	 ASSERT_TRUE(eq);
 }




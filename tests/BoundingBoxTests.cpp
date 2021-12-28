 #include "gtest/gtest.h"
 #include "../src/utilities/BoundingBox.h"

using namespace BepuUtilities;

 TEST(BoundingBox, Intersection0)
 {
	 BoundingBox a(Vector3(0, 0, 0), Vector3(2, 2, 2));
	 BoundingBox b(Vector3(1, 1, 1), Vector3(3, 3, 3));
	 bool result = BoundingBox::Intersects(a, b);
	 ASSERT_TRUE(result);
 }

 TEST(BoundingBox, Intersection1)
 {
	 BoundingBox a(Vector3(0, 0, 0), Vector3(1, 1, 1));
	 BoundingBox b(Vector3(2, 2, 2), Vector3(3, 3, 3));
	 bool result = BoundingBox::Intersects(a, b);
	 ASSERT_FALSE(result);
 }


 //TEST(Vector3, Multiply)
 //{
	// Vector3 a(12.56, 56.2, -4.678);
	// Vector3 b(45.57, -123.56, -87.009);
	// Vector3 c = a * b;
	// bool eq = Vector3(Fix64(6626070471276954898, 572), Fix64(17118578500393628598, 18446744073709544671), Fix64(518390401959312611, 407)) == c;
	// ASSERT_TRUE(eq);
 //}

 //TEST(Vector3, Divide)
 //{
	// Vector3 a(12.56, 56.2, -4.678);
	// Vector3 c = a / Fix64(12.4);
	// bool eq = Vector3(Fix64(238022504176897636, 1), Fix64(9818428297297021204, 4), Fix64(11487561107837513006, 18446744073709551615)) == c;
	// ASSERT_TRUE(eq);
 //}




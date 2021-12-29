 #include "gtest/gtest.h"
 #include "../src/utilities/BoundingBox.h"

using namespace Utilities;

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

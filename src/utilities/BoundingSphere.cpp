#include "BoundingSphere.h"

namespace BepuUtilities
{
	BoundingSphere::BoundingSphere(Vector3 center, Fix64 radius)
	{
		this->Center = center;
		this->Radius = radius;
	}
}

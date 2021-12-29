#include "BoundingSphere.h"

namespace Utilities
{
	BoundingSphere::BoundingSphere(Vector3 center, Fix64 radius)
	{
		this->Center = center;
		this->Radius = radius;
	}
}

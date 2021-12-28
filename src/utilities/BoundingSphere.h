#pragma once

#include "../Common.h"
#include "Vector3.h"

namespace BepuUtilities
{
	/// <summary>
	/// Provides XNA-like bounding sphere functionality.
	/// </summary>
	class BoundingSphere
	{
	public:
		/// <summary>
		/// Location of the center of the sphere.
		/// </summary>
		Vector3 Center;
		/// <summary>
		/// Radius of the sphere.
		/// </summary>
		Fix64 Radius;

		/// <summary>
		/// Constructs a new bounding sphere.
		/// </summary>
		/// <param name="center">Location of the center of the sphere.</param>
		/// <param name="radius">Radius of the sphere.</param>
		BoundingSphere(Vector3 center, Fix64 radius);
	};
}

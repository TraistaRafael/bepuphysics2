#pragma once

#include "../Common.h"
#include "../ForwardDeclarations.h"
#include "Vector3.h"

namespace Utilities
{
	/// <summary>
	/// Provides XNA-like axis-aligned bounding box functionality.
	/// </summary>
	//NOTE: The explicit size avoids https://github.com/dotnet/coreclr/issues/12950
	// TO-DO check this [StructLayout(LayoutKind.Explicit, Size = 32)]
	class BoundingBox
	{
	public:
		/// <summary>
		/// Location with the lowest X, Y, and Z coordinates in the axis-aligned bounding box.
		/// </summary>
		// TO-DO check this [FieldOffset(0)]
		Vector3 Min;

		/// <summary>
		/// Location with the highest X, Y, and Z coordinates in the axis-aligned bounding box.
		/// </summary>
		// TO-DO check this [FieldOffset(16)]
		Vector3 Max;

		/// <summary>
		/// Constructs a bounding box with default empty values
		/// </summary>
		BoundingBox();

		/// <summary>
		/// Constructs a bounding box from the specified minimum and maximum.
		/// </summary>
		/// <param name="min">Location with the lowest X, Y, and Z coordinates contained by the axis-aligned bounding box.</param>
		/// <param name="max">Location with the highest X, Y, and Z coordinates contained by the axis-aligned bounding box.</param>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		BoundingBox(Vector3 min, Vector3 max);

		/// <summary>
		/// Determines if a bounding box intersects another bounding box.
		/// </summary>
		/// <param name="a">First bounding box to test.</param>
		/// <param name="b">Second bounding box to test.</param>
		/// <returns>Whether the bounding boxes intersected.</returns>
		static bool Intersects(const BoundingBox &a, const BoundingBox &b);

		//TODO: At some point in the past, intersection was found to be faster with non-short circuiting operators.
		//While that does make some sense (the branches aren't really valuable relative to their cost), it's still questionable enough that it should be reevaluated on a modern compiler. 
		/// <summary>
		/// Determines if a bounding box intersects another bounding box.
		/// </summary>
		/// <param name="a">First bounding box to test.</param>
		/// <param name="b">Second bounding box to test.</param>
		/// <returns>Whether the bounding boxes intersected.</returns>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		static bool Intersects(const Vector3 &minA, const Vector3 &maxA, const Vector3 &minB, const Vector3 &maxB);

		/// <summary>
		/// Computes the volume of the bounding box.
		/// </summary>
		/// <param name="box">Bounding box to measure.</param>
		/// <returns>Volume of the bounding box.</returns>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		static Fix64 ComputeVolume(const BoundingBox &box);

		/// <summary>
		/// Computes a bounding box which contains two other bounding boxes.
		/// </summary>
		/// <param name="minA">Minimum of the first bounding box to merge.</param>
		/// <param name="maxA">Maximum of the first bounding box to merge.</param>
		/// <param name="minB">Minimum of the second bounding box to merge.</param>
		/// <param name="maxB">Maximum of the second bounding box to merge.</param>
		/// <param name="min">Minimum of the merged bounding box.</param>
		/// <param name="max">Maximum of the merged bounding box.</param>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		static void CreateMerged(const Vector3 &minA, const Vector3 &maxA, const Vector3 &minB, const Vector3 &maxB, Vector3 &min, Vector3 &max);

		/// <summary>
		/// Computes a bounding box which contains two other bounding boxes.
		/// </summary>
		/// <param name="a">First bounding box to contain.</param>
		/// <param name="b">Second bounding box to contain.</param>
		/// <param name="merged">Bounding box to contain both input boxes.</param>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		static void CreateMerged(const BoundingBox &a, const BoundingBox &b, BoundingBox &merged);

		/// <summary>
		/// Determines if a bounding box intersects a bounding sphere.
		/// </summary>
		/// <param name="boundingSphere">Sphere to test for intersection.</param>
		/// <returns>Whether the bounding shapes intersect.</returns>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		bool Intersects(const BoundingSphere &boundingSphere);

		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		ContainmentType Contains(const BoundingBox &boundingBox);

		/// <summary>
		/// Creates the smallest possible bounding box that contains a list of points.
		/// </summary>
		/// <param name="points">Points to enclose with a bounding box.</param>
		/// <returns>Bounding box which contains the list of points.</returns>
		static BoundingBox CreateFromPoints(std::vector<Vector3> points);

		/// <summary>
		/// Creates a bounding box from a bounding sphere.
		/// </summary>
		/// <param name="boundingSphere">Bounding sphere to be used to create the bounding box.</param>
		/// <param name="boundingBox">Bounding box created from the bounding sphere.</param>
		// TO-DO check this [MethodImpl(MethodImplOptions.AggressiveInlining)]
		static void BoundingBox::CreateFromSphere(const BoundingSphere &boundingSphere, BoundingBox &boundingBox);

		/// <summary>
		/// Creates a string representation of the bounding box.
		/// </summary>
		/// <returns>String representation of the bounding box.</returns>
		string ToString();

	};
}

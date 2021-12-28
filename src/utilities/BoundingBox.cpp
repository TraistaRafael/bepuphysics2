#pragma once

#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "ContainmentType.h"

namespace BepuUtilities
{
	BoundingBox::BoundingBox()
	{
		this->Min = Vector3::GetZero();
		this->Max = Vector3::GetZero();
	}

	BoundingBox::BoundingBox(Vector3 min, Vector3 max)
	{
		this->Min = min;
		this->Max = max;
	}

	bool BoundingBox::Intersects(const BoundingBox &a, const BoundingBox &b)
	{
		return Intersects(a.Min, a.Max, b.Min, b.Max);
	}

	bool BoundingBox::Intersects(const Vector3 &minA, const Vector3 &maxA, const Vector3 &minB, const Vector3 &maxB)
	{
		return maxA.X >= minB.X & maxA.Y >= minB.Y & maxA.Z >= minB.Z &
			maxB.X >= minA.X & maxB.Y >= minA.Y & maxB.Z >= minA.Z;
	}

	Fix64 BoundingBox::ComputeVolume(const BoundingBox &box)
	{
		Vector3 diagonal = (box.Max - box.Min);
		return diagonal.X * diagonal.Y * diagonal.Z;
	}

	void BoundingBox::CreateMerged(const Vector3 &minA, const Vector3 &maxA, const Vector3 &minB, const Vector3 &maxB, Vector3 &min, Vector3 &max)
	{
		min = Vector3::Min(minA, minB);
		max = Vector3::Max(maxA, maxB);
	}

	void BoundingBox::CreateMerged(const BoundingBox &a, const BoundingBox &b, BoundingBox &merged)
	{
		CreateMerged(a.Min, a.Max, b.Min, b.Max, merged.Min, merged.Max);
	}

	bool BoundingBox::Intersects(const BoundingSphere &boundingSphere)
	{
		Vector3 offset = boundingSphere.Center - Vector3::Min(Vector3::Max(boundingSphere.Center, Min), Max);
		return Vector3::Dot(offset, offset) <= boundingSphere.Radius * boundingSphere.Radius;
	}

	ContainmentType BoundingBox::Contains(const BoundingBox &boundingBox)
	{
		if (Max.X < boundingBox.Min.X || Min.X > boundingBox.Max.X ||
			Max.Y < boundingBox.Min.Y || Min.Y > boundingBox.Max.Y ||
			Max.Z < boundingBox.Min.Z || Min.Z > boundingBox.Max.Z)
			return ContainmentType::Disjoint;
		//It is known to be at least intersecting. Is it contained?
		if (Min.X <= boundingBox.Min.X && Max.X >= boundingBox.Max.X &&
			Min.Y <= boundingBox.Min.Y && Max.Y >= boundingBox.Max.Y &&
			Min.Z <= boundingBox.Min.Z && Max.Z >= boundingBox.Max.Z)
			return ContainmentType::Contains;
		return ContainmentType::Intersects;
	}

	BoundingBox BoundingBox::CreateFromPoints(std::vector<Vector3> points)
	{
		BoundingBox aabb;
		if (points.size() == 0)
			throw std::exception("Cannot construct a bounding box from an empty list.");
		aabb.Min = points[0];
		aabb.Max = aabb.Min;
		for (int i = points.size() - 1; i >= 1; i--)
		{
			aabb.Min = Vector3::Min(points[i], aabb.Min);
			aabb.Max = Vector3::Max(points[i], aabb.Max);
		}
		return aabb;
	}

	void BoundingBox::CreateFromSphere(const BoundingSphere &boundingSphere, BoundingBox &boundingBox)
	{
		Vector3 radius = Vector3(boundingSphere.Radius, boundingSphere.Radius, boundingSphere.Radius);
		boundingBox.Min = boundingSphere.Center - radius;
		boundingBox.Max = boundingSphere.Center + radius;
	}

	string BoundingBox::ToString()
	{
		return "{" + Min.ToString() + "}, {" + Max.ToString() + "}";
	}
}
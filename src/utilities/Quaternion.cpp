#pragma once

#include "Vector3.h"
#include "Vector2.h"
#include "Fix64.h"
#include "F64.h"

namespace BepuUtilities
{
	Vector3::Vector3()
	{
		this->X = F64::C0;
		this->Y = F64::C0;
		this->Z = F64::C0;
	}

	Vector3::Vector3(Fix64 x, Fix64 y, Fix64 z)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
	}

	Vector3::Vector3(Vector2 xy, Fix64 z)
	{
		this->X = xy.X;
		this->Y = xy.Y;
		this->Z = z;
	}

	Vector3::Vector3(Fix64 x, Vector2 yz)
	{
		this->X = x;
		this->Y = yz.X;
		this->Z = yz.Y;
	}

	Fix64 Vector3::LengthSquared()
	{
		return X * X + Y * Y + Z * Z;
	}

	Fix64 Vector3::Length()
	{
		return Fix64::Sqrt(X * X + Y * Y + Z * Z);
	}

	void Vector3::Normalize()
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y + Z * Z);
		X *= inverse;
		Y *= inverse;
		Z *= inverse;
	}

	string Vector3::ToString()
	{
		return "{" + (string) X + ", " + (string) Y + ", " + (string) Z + "}";
	}

	Fix64 Vector3::Dot(Vector3 a, Vector3 b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}

	void Vector3::Dot(const Vector3 &a, const Vector3 &b, Fix64 &product)
	{
		product = a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}

	void Vector3::Add(const Vector3 &a, const Vector3 &b, Vector3 &sum)
	{
		sum.X = a.X + b.X;
		sum.Y = a.Y + b.Y;
		sum.Z = a.Z + b.Z;
	}

	void Vector3::Subtract(const Vector3 &a, const Vector3 &b, Vector3 &difference)
	{
		difference.X = a.X - b.X;
		difference.Y = a.Y - b.Y;
		difference.Z = a.Z - b.Z;
	}

	void Vector3::Multiply(const Vector3 &v, Fix64 scale, Vector3 &result)
	{
		result.X = v.X * scale;
		result.Y = v.Y * scale;
		result.Z = v.Z * scale;
	}

	void Vector3::Multiply(const Vector3 &a, const Vector3 &b, Vector3 &result)
	{
		result.X = a.X * b.X;
		result.Y = a.Y * b.Y;
		result.Z = a.Z * b.Z;
	}

	void Vector3::Divide(const Vector3 &v, Fix64 divisor, Vector3 &result)
	{
		Fix64 inverse = F64::C1 / divisor;
		result.X = v.X * inverse;
		result.Y = v.Y * inverse;
		result.Z = v.Z * inverse;
	}

	Vector3 Vector3::operator *(Fix64 f) const
	{
		Vector3 toReturn;
		toReturn.X = this->X * f;
		toReturn.Y = this->Y * f;
		toReturn.Z = this->Z * f;
		return toReturn;
	}

	Vector3 Vector3::operator *(Vector3 b) const
	{
		Vector3 result;
		Multiply(*this, b, result);
		return result;
	}

	Vector3 Vector3::operator /(Fix64 f) const
	{
		Vector3 toReturn;
		f = F64::C1 / f;
		toReturn.X = this->X * f;
		toReturn.Y = this->Y * f;
		toReturn.Z = this->Z * f;
		return toReturn;
	}

	Vector3 Vector3::operator -(Vector3 b) const
	{
		Vector3 v;
		v.X = this->X - b.X;
		v.Y = this->Y - b.Y;
		v.Z = this->Z - b.Z;
		return v;
	}

	Vector3 Vector3::operator +(Vector3 b) const
	{
		Vector3 v;
		v.X = this->X + b.X;
		v.Y = this->Y + b.Y;
		v.Z = this->Z + b.Z;
		return v;
	}

	Vector3 Vector3::operator -()
	{
		this->X = -this->X;
		this->Y = -this->Y;
		this->Z = -this->Z;
		return *this;
	}

	bool Vector3::operator ==(Vector3 b)
	{
		return this->X == b.X && this->Y == this->Y && this->Z == b.Z;
	}

	bool Vector3::operator !=(Vector3 b)
	{
		return this->X != b.X || this->Y != b.Y || this->Z != b.Z;
	}

	bool Vector3::Equals(Vector3 other)
	{
		return X == other.X && Y == other.Y && Z == other.Z;
	}

	void Vector3::DistanceSquared(const Vector3 &a, const Vector3 &b, Fix64 &distanceSquared)
	{
		Fix64 x = a.X - b.X;
		Fix64 y = a.Y - b.Y;
		Fix64 z = a.Z - b.Z;
		distanceSquared = x * x + y * y + z * z;
	}

	Fix64 Vector3::DistanceSquared(Vector3 a, Vector3 b)
	{
		Fix64 x = a.X - b.X;
		Fix64 y = a.Y - b.Y;
		Fix64 z = a.Z - b.Z;
		return x * x + y * y + z * z;
	}

	void Vector3::Distance(const Vector3 &a, const Vector3 &b, Fix64 &distance)
	{
		Fix64 x = a.X - b.X;
		Fix64 y = a.Y - b.Y;
		Fix64 z = a.Z - b.Z;
		distance = Fix64::Sqrt(x * x + y * y + z * z);
	}

	Fix64 Vector3::Distance(Vector3 a, Vector3 b)
	{
		Fix64 toReturn;
		Distance(a, b, toReturn);
		return toReturn;
	}

	Vector3 Vector3::GetZero()
	{
		return Vector3(F64::C0, F64::C0, F64::C0);
	}

	Vector3 Vector3::GetUp()
	{
		return Vector3(F64::C0, F64::C1, F64::C0);
	}

	Vector3 Vector3::GetDown()
	{
		return Vector3(F64::C0, -1, F64::C0);
	}

	Vector3 Vector3::GetRight()
	{
		return Vector3(F64::C1, F64::C0, F64::C0);
	}

	Vector3 Vector3::GetLeft()
	{
		return Vector3(-1, F64::C0, F64::C0);
	}

	Vector3 Vector3::GetForward()
	{
		return Vector3(F64::C0, F64::C0, -1);
	}

	Vector3 Vector3::GetBackward()
	{
		return Vector3(F64::C0, F64::C0, F64::C1);
	}

	Vector3 Vector3::GetUnitX()
	{
		return Vector3(F64::C1, F64::C0, F64::C0);
	}

	Vector3 Vector3::GetUnitY()
	{
		return Vector3(F64::C0, F64::C1, F64::C0);
	}

	Vector3 Vector3::GetUnitZ()
	{
		return Vector3(F64::C0, F64::C0, F64::C1);
	}

	Vector3 Vector3::Cross(Vector3 a, Vector3 b)
	{
		Vector3 toReturn;
		Vector3::Cross(a, b, toReturn);
		return toReturn;
	}

	void Vector3::Cross(const Vector3 &a, const Vector3 &b, Vector3 &result)
	{
		Fix64 resultX = a.Y * b.Z - a.Z * b.Y;
		Fix64 resultY = a.Z * b.X - a.X * b.Z;
		Fix64 resultZ = a.X * b.Y - a.Y * b.X;
		result.X = resultX;
		result.Y = resultY;
		result.Z = resultZ;
	}

	Vector3 Vector3::Normalize(Vector3 v)
	{
		Vector3 toReturn;
		Vector3::Normalize(v, toReturn);
		return toReturn;
	}

	void Vector3::Normalize(const Vector3 &v, Vector3 &result)
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
		result.X = v.X * inverse;
		result.Y = v.Y * inverse;
		result.Z = v.Z * inverse;
	}

	void Vector3::Negate(const Vector3 &v, Vector3 &negated)
	{
		negated.X = -v.X;
		negated.Y = -v.Y;
		negated.Z = -v.Z;
	}

	void Vector3::Abs(const Vector3 &v, Vector3 &result)
	{
		if (v.X < F64::C0)
			result.X = -v.X;
		else
			result.X = v.X;
		if (v.Y < F64::C0)
			result.Y = -v.Y;
		else
			result.Y = v.Y;
		if (v.Z < F64::C0)
			result.Z = -v.Z;
		else
			result.Z = v.Z;
	}

	Vector3 Vector3::Abs(Vector3 v)
	{
		Vector3 result;
		Abs(v, result);
		return result;
	}

	void Vector3::Min(const Vector3 &a, const Vector3 &b, Vector3 &min)
	{
		min.X = a.X < b.X ? a.X : b.X;
		min.Y = a.Y < b.Y ? a.Y : b.Y;
		min.Z = a.Z < b.Z ? a.Z : b.Z;
	}

	Vector3 Vector3::Min(Vector3 a, Vector3 b)
	{
		Vector3 result;
		Min(a, b, result);
		return result;
	}

	void Vector3::Max(const Vector3 &a, const Vector3 &b, Vector3 &max)
	{
		max.X = a.X > b.X ? a.X : b.X;
		max.Y = a.Y > b.Y ? a.Y : b.Y;
		max.Z = a.Z > b.Z ? a.Z : b.Z;
	}

	Vector3 Vector3::Max(Vector3 a, Vector3 b)
	{
		Vector3 result;
		Max(a, b, result);
		return result;
	}

	Vector3 Vector3::Lerp(Vector3 start, Vector3 end, Fix64 interpolationAmount)
	{
		Vector3 toReturn;
		Lerp(start, end, interpolationAmount, toReturn);
		return toReturn;
	}

	void Vector3::Lerp(const Vector3 &start, const Vector3 &end, Fix64 interpolationAmount, Vector3 &result)
	{
		Fix64 startAmount = F64::C1 - interpolationAmount;
		result.X = start.X * startAmount + end.X * interpolationAmount;
		result.Y = start.Y * startAmount + end.Y * interpolationAmount;
		result.Z = start.Z * startAmount + end.Z * interpolationAmount;
	}

	void Vector3::Hermite(const Vector3 &value1, const Vector3 &tangent1, const Vector3 &value2, const Vector3 &tangent2, Fix64 interpolationAmount, Vector3 &result)
	{
		//TO-DO
		/*Fix64 weightSquared = interpolationAmount * interpolationAmount;
		Fix64 weightCubed = interpolationAmount * weightSquared;
		Fix64 value1Blend = F64::C2 * weightCubed - F64::C3 * weightSquared + F64::C1;
		Fix64 tangent1Blend = weightCubed - F64::C2 * weightSquared + interpolationAmount;
		Fix64 value2Blend = -2 * weightCubed + F64::C3 * weightSquared;
		Fix64 tangent2Blend = weightCubed - weightSquared;
		result.X = value1.X * value1Blend + value2.X * value2Blend + tangent1.X * tangent1Blend + tangent2.X * tangent2Blend;
		result.Y = value1.Y * value1Blend + value2.Y * value2Blend + tangent1.Y * tangent1Blend + tangent2.Y * tangent2Blend;
		result.Z = value1.Z * value1Blend + value2.Z * value2Blend + tangent1.Z * tangent1Blend + tangent2.Z * tangent2Blend;*/
	}

	Vector3 Vector3::Hermite(Vector3 value1, Vector3 tangent1, Vector3 value2, Vector3 tangent2, Fix64 interpolationAmount)
	{
		Vector3 toReturn;
		Hermite(value1, tangent1, value2, tangent2, interpolationAmount, toReturn);
		return toReturn;
	}
}

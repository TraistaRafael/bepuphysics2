#include "Vector4.h"

namespace BepuUtilities
{

	Vector4::Vector4()
	{
		this->X = F64::C0;
		this->Y = F64::C0;
		this->Z = F64::C0;
		this->W = F64::C0;
	}

	Vector4::Vector4(Fix64 v)
	{
		this->X = v;
		this->Y = v;
		this->Z = v;
		this->W = v;
	}

	Vector4::Vector4(Fix64 x, Fix64 y, Fix64 z, Fix64 w)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
		this->W = w;
	}

	Vector4::Vector4(Vector3 xyz, Fix64 w)
	{
		this->X = xyz.X;
		this->Y = xyz.Y;
		this->Z = xyz.Z;
		this->W = w;
	}

	Vector4::Vector4(Fix64 x, Vector3 yzw)
	{
		this->X = x;
		this->Y = yzw.X;
		this->Z = yzw.Y;
		this->W = yzw.Z;
	}

	Vector4::Vector4(Vector2 xy, Fix64 z, Fix64 w)
	{
		this->X = xy.X;
		this->Y = xy.Y;
		this->Z = z;
		this->W = w;
	}

	Vector4::Vector4(Fix64 x, Vector2 yz, Fix64 w)
	{
		this->X = x;
		this->Y = yz.X;
		this->Z = yz.Y;
		this->W = w;
	}

	Vector4::Vector4(Fix64 x, Fix64 y, Vector2 zw)
	{
		this->X = x;
		this->Y = y;
		this->Z = zw.X;
		this->W = zw.Y;
	}

	Vector4::Vector4(Vector2 xy, Vector2 zw)
	{
		this->X = xy.X;
		this->Y = xy.Y;
		this->Z = zw.X;
		this->W = zw.Y;
	}

	Fix64 Vector4::LengthSquared()
	{
		return X * X + Y * Y + Z * Z + W * W;
	}

	Fix64 Vector4::Length()
	{
		return Fix64::Sqrt(X * X + Y * Y + Z * Z + W * W);
	}

	void Vector4::Normalize()
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y + Z * Z + W * W);
		X *= inverse;
		Y *= inverse;
		Z *= inverse;
		W *= inverse;
	}

	string Vector4::ToString()
	{
		return "{" + (string)X + ", " + (string)Y + ", " + (string)Z + ", " + (string)W + "}";
	}

	Fix64 Vector4::Dot(Vector4 a, Vector4 b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
	}

	void Vector4::Dot(const Vector4 &a, const Vector4 &b, Fix64 &product)
	{
		product = a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
	}

	void Vector4::Add(const Vector4 &a, const Vector4 &b, Vector4 &sum)
	{
		sum.X = a.X + b.X;
		sum.Y = a.Y + b.Y;
		sum.Z = a.Z + b.Z;
		sum.W = a.W + b.W;
	}

	void Vector4::Subtract(const Vector4 &a, const Vector4 &b, Vector4 &difference)
	{
		difference.X = a.X - b.X;
		difference.Y = a.Y - b.Y;
		difference.Z = a.Z - b.Z;
		difference.W = a.W - b.W;
	}

	void Vector4::Multiply(const Vector4 &v, Fix64 scale, Vector4 &result)
	{
		result.X = v.X * scale;
		result.Y = v.Y * scale;
		result.Z = v.Z * scale;
		result.W = v.W * scale;
	}

	void Vector4::Multiply(const Vector4 &a, const Vector4 &b, Vector4 &result)
	{
		result.X = a.X * b.X;
		result.Y = a.Y * b.Y;
		result.Z = a.Z * b.Z;
		result.W = a.W * b.W;
	}

	void Vector4::Divide(const Vector4 &v, Fix64 divisor, Vector4 &result)
	{
		Fix64 inverse = F64::C1 / divisor;
		result.X = v.X * inverse;
		result.Y = v.Y * inverse;
		result.Z = v.Z * inverse;
		result.W = v.W * inverse;
	}
	
	Vector4 Vector4::operator *(Fix64 f) const
	{
		Vector4 toReturn;
		toReturn.X = this->X * f;
		toReturn.Y = this->Y * f;
		toReturn.Z = this->Z * f;
		toReturn.W = this->W * f;
		return toReturn;
	}

	Vector4 Vector4::operator *(const Vector4 &b) const
	{
		Vector4 result;
		Multiply(*this, b, result);
		return result;
	}

	Vector4 Vector4::operator /(Fix64 f) const
	{
		Vector4 toReturn;
		f = F64::C1 / f;
		toReturn.X = this->X * f;
		toReturn.Y = this->Y * f;
		toReturn.Z = this->Z * f;
		toReturn.W = this->W * f;
		return toReturn;
	}

	Vector4 Vector4::operator -(const Vector4 &b) const
	{
		Vector4 v;
		v.X = this->X - b.X;
		v.Y = this->Y - b.Y;
		v.Z = this->Z - b.Z;
		v.W = this->W - b.W;
		return v;
	}

	Vector4 Vector4::operator +(const Vector4 &b) const
	{
		Vector4 v;
		v.X = this->X + b.X;
		v.Y = this->Y + b.Y;
		v.Z = this->Z + b.Z;
		v.W = this->W + b.W;
		return v;
	}

	Vector4 Vector4::operator -()
	{
		this->X = -this->X;
		this->Y = -this->Y;
		this->Z = -this->Z;
		this->W = -this->W;
		return *this;
	}

	bool Vector4::operator ==(const Vector4 &b) const
	{
		return this->X == b.X && this->Y == b.Y && this->Z == b.Z && this->W == b.W;
	}

	bool Vector4::operator !=(const Vector4 &b) const
	{
		return this->X != b.X || this->Y != b.Y || this->Z != b.Z || this->W != b.W;
	}

	bool Vector4::Equals(const Vector4 &other)
	{
		return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
	}

	void Vector4::DistanceSquared(const Vector4 &a, const Vector4 &b, Fix64 &distanceSquared)
	{
		Fix64 x = a.X - b.X;
		Fix64 y = a.Y - b.Y;
		Fix64 z = a.Z - b.Z;
		Fix64 w = a.W - b.W;
		distanceSquared = x * x + y * y + z * z + w * w;
	}

	void Vector4::Distance(const Vector4 &a, const Vector4 &b, Fix64 &distance)
	{
		Fix64 x = a.X - b.X;
		Fix64 y = a.Y - b.Y;
		Fix64 z = a.Z - b.Z;
		Fix64 w = a.W - b.W;
		distance = Fix64::Sqrt(x * x + y * y + z * z + w * w);
	}
	
	Fix64 Vector4::Distance(Vector4 a, Vector4 b)
	{
		Fix64 toReturn;
		Distance(a, b, toReturn);
		return toReturn;
	}

	Vector4 Vector4::GetZero()
	{
		return Vector4();
	}

	Vector4 Vector4::GetUnitX()
	{
		return Vector4(F64::C1, F64::C0, F64::C0, F64::C0);
	}

	Vector4 Vector4::GetUnitY()
	{
		return Vector4(F64::C0, F64::C1, F64::C0, F64::C0);
	}

	Vector4 Vector4::GetUnitZ()
	{
		return Vector4(F64::C0, F64::C0, F64::C1, F64::C0);
	}

	Vector4 Vector4::GetUnitW()
	{
		return Vector4(F64::C0, F64::C0, F64::C0, F64::C1);
	}

	Vector4 Vector4::Normalize(Vector4 v)
	{
		Vector4 toReturn;
		Vector4::Normalize(v, toReturn);
		return toReturn;
	}

	void Vector4::Normalize(const Vector4 &v, Vector4 &result)
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z + v.W * v.W);
		result.X = v.X * inverse;
		result.Y = v.Y * inverse;
		result.Z = v.Z * inverse;
		result.W = v.W * inverse;
	}

	void Vector4::Negate(Vector4 v, Vector4 negated)
	{
		negated.X = -v.X;
		negated.Y = -v.Y;
		negated.Z = -v.Z;
		negated.W = -v.W;
	}

	void Vector4::Abs(const Vector4 &v, Vector4 &result)
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
		if (v.W < F64::C0)
			result.W = -v.W;
		else
			result.W = v.W;
	}

	Vector4 Vector4::Abs(Vector4 v)
	{
		Vector4 result;
		Abs(v, result);
		return result;
	}

	void Vector4::Min(const Vector4 &a, Vector4 &b, Vector4 &min)
	{
		min.X = a.X < b.X ? a.X : b.X;
		min.Y = a.Y < b.Y ? a.Y : b.Y;
		min.Z = a.Z < b.Z ? a.Z : b.Z;
		min.W = a.W < b.W ? a.W : b.W;
	}

	Vector4 Vector4::Min(Vector4 a, Vector4 b)
	{
		Vector4 result;
		Min(a, b, result);
		return result;
	}

	void Vector4::Max(const Vector4 &a, const Vector4 &b, Vector4 &max)
	{
		max.X = a.X > b.X ? a.X : b.X;
		max.Y = a.Y > b.Y ? a.Y : b.Y;
		max.Z = a.Z > b.Z ? a.Z : b.Z;
		max.W = a.W > b.W ? a.W : b.W;
	}

	Vector4 Vector4::Max(Vector4 a, Vector4 b)
	{
		Vector4 result;
		Max(a, b, result);
		return result;
	}

	Vector4 Vector4::Lerp(const Vector4 &start, const Vector4 &end, Fix64 interpolationAmount)
	{
		Vector4 toReturn;
		Lerp(start, end, interpolationAmount, toReturn);
		return toReturn;
	}

	void Vector4::Lerp(const Vector4 &start, const Vector4 &end, Fix64 interpolationAmount, Vector4 &result)
	{
		Fix64 startAmount = F64::C1 - interpolationAmount;
		result.X = start.X * startAmount + end.X * interpolationAmount;
		result.Y = start.Y * startAmount + end.Y * interpolationAmount;
		result.Z = start.Z * startAmount + end.Z * interpolationAmount;
		result.W = start.W * startAmount + end.W * interpolationAmount;
	}

	void Vector4::Hermite(const Vector4 &value1, const Vector4 &tangent1, const Vector4 &value2, const Vector4 &tangent2, Fix64 interpolationAmount, Vector4 &result)
	{
		Fix64 weightSquared = interpolationAmount * interpolationAmount;
		Fix64 weightCubed = interpolationAmount * weightSquared;
		Fix64 value1Blend = F64::C2 * weightCubed - F64::C3 * weightSquared + F64::C1;
		Fix64 tangent1Blend = weightCubed - F64::C2 * weightSquared + interpolationAmount;
		Fix64 value2Blend = Fix64(-2) * weightCubed + F64::C3 * weightSquared;
		Fix64 tangent2Blend = weightCubed - weightSquared;
		result.X = value1.X * value1Blend + value2.X * value2Blend + tangent1.X * tangent1Blend + tangent2.X * tangent2Blend;
		result.Y = value1.Y * value1Blend + value2.Y * value2Blend + tangent1.Y * tangent1Blend + tangent2.Y * tangent2Blend;
		result.Z = value1.Z * value1Blend + value2.Z * value2Blend + tangent1.Z * tangent1Blend + tangent2.Z * tangent2Blend;
		result.W = value1.W * value1Blend + value2.W * value2Blend + tangent1.W * tangent1Blend + tangent2.W * tangent2Blend;
	}

	Vector4 Vector4::Hermite(const Vector4 &value1, const Vector4 &tangent1, const Vector4 &value2, const Vector4 &tangent2, Fix64 interpolationAmount)
	{
		Vector4 toReturn;
		Hermite(value1, tangent1, value2, tangent2, interpolationAmount, toReturn);
		return toReturn;
	}

}
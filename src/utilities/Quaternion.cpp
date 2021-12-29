#include "Quaternion.h"
#include "Matrix3x3.h"
#include "Vector3.h"

namespace Utilities
{
	Quaternion::Quaternion()
	{
		this->X = F64::C0;
		this->Y = F64::C0;
		this->Z = F64::C0;
		this->W = F64::C0;
	}

	Quaternion::Quaternion(Fix64 x, Fix64 y, Fix64 z, Fix64 w)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
		this->W = w;
	}

	void Quaternion::Add(const Quaternion &a, const Quaternion &b, Quaternion &result)
	{
		result.X = a.X + b.X;
		result.Y = a.Y + b.Y;
		result.Z = a.Z + b.Z;
		result.W = a.W + b.W;
	}

	void Quaternion::Multiply(const Quaternion &a, const Quaternion &b, Quaternion &result)
	{
		Fix64 x = a.X;
		Fix64 y = a.Y;
		Fix64 z = a.Z;
		Fix64 w = a.W;
		Fix64 bX = b.X;
		Fix64 bY = b.Y;
		Fix64 bZ = b.Z;
		Fix64 bW = b.W;
		result.X = x * bW + bX * w + y * bZ - z * bY;
		result.Y = y * bW + bY * w + z * bX - x * bZ;
		result.Z = z * bW + bZ * w + x * bY - y * bX;
		result.W = w * bW - x * bX - y * bY - z * bZ;
	}

	void Quaternion::Multiply(const Quaternion &q, Fix64 scale, Quaternion &result)
	{
		result.X = q.X * scale;
		result.Y = q.Y * scale;
		result.Z = q.Z * scale;
		result.W = q.W * scale;
	}

	void Quaternion::Concatenate(const Quaternion &a, const Quaternion &b, Quaternion &result)
	{
		Fix64 aX = a.X;
		Fix64 aY = a.Y;
		Fix64 aZ = a.Z;
		Fix64 aW = a.W;
		Fix64 bX = b.X;
		Fix64 bY = b.Y;
		Fix64 bZ = b.Z;
		Fix64 bW = b.W;

		result.X = aW * bX + aX * bW + aZ * bY - aY * bZ;
		result.Y = aW * bY + aY * bW + aX * bZ - aZ * bX;
		result.Z = aW * bZ + aZ * bW + aY * bX - aX * bY;
		result.W = aW * bW - aX * bX - aY * bY - aZ * bZ;
	}

	Quaternion Quaternion::Concatenate(Quaternion a, Quaternion b)
	{
		Quaternion result;
		Concatenate(a, b, result);
		return result;
	}

	Quaternion Quaternion::GetIdentity()
	{
		return Quaternion(F64::C0, F64::C0, F64::C0, F64::C1);
	}

	Quaternion Quaternion::Normalize(Quaternion quaternion)
	{
		Quaternion toReturn;
		Normalize(quaternion, toReturn);
		return toReturn;
	}

	void Quaternion::Normalize(const Quaternion &quaternion, Quaternion &toReturn)
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(quaternion.X * quaternion.X + quaternion.Y * quaternion.Y + quaternion.Z * quaternion.Z + quaternion.W * quaternion.W);
		toReturn.X = quaternion.X * inverse;
		toReturn.Y = quaternion.Y * inverse;
		toReturn.Z = quaternion.Z * inverse;
		toReturn.W = quaternion.W * inverse;
	}

	void Quaternion::Normalize()
	{
		Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y + Z * Z + W * W);
		X *= inverse;
		Y *= inverse;
		Z *= inverse;
		W *= inverse;
	}

	Fix64 Quaternion::LengthSquared()
	{
		return X * X + Y * Y + Z * Z + W * W;
	}

	Fix64 Quaternion::Length()
	{
		return Fix64::Sqrt(X * X + Y * Y + Z * Z + W * W);
	}

	void Quaternion::Slerp(Quaternion &start, Quaternion &end, Fix64 interpolationAmount, Quaternion &result)
	{
		Fix64 cosHalfTheta = start.W * end.W + start.X * end.X + start.Y * end.Y + start.Z * end.Z;
		if (cosHalfTheta < F64::C0)
		{
			//Negating a quaternion results in the same orientation, 
			//but we need cosHalfTheta to be positive to get the shortest path.
			end.X = -end.X;
			end.Y = -end.Y;
			end.Z = -end.Z;
			end.W = -end.W;
			cosHalfTheta = -cosHalfTheta;
		}
		// If the orientations are similar enough, then just pick one of the inputs.
		if (cosHalfTheta > F64::C1m1em12)
		{
			result.W = start.W;
			result.X = start.X;
			result.Y = start.Y;
			result.Z = start.Z;
			return;
		}
		// Calculate temporary values.
		Fix64 halfTheta = Fix64::Acos(cosHalfTheta);
		Fix64 sinHalfTheta = Fix64::Sqrt(F64::C1 - cosHalfTheta * cosHalfTheta);

		Fix64 aFraction = Fix64::Sin((F64::C1 - interpolationAmount) * halfTheta) / sinHalfTheta;
		Fix64 bFraction = Fix64::Sin(interpolationAmount * halfTheta) / sinHalfTheta;

		//Blend the two quaternions to get the result!
		result.X = (Fix64)(start.X * aFraction + end.X * bFraction);
		result.Y = (Fix64)(start.Y * aFraction + end.Y * bFraction);
		result.Z = (Fix64)(start.Z * aFraction + end.Z * bFraction);
		result.W = (Fix64)(start.W * aFraction + end.W * bFraction);
	}

	Quaternion Quaternion::Slerp(Quaternion start, Quaternion end, Fix64 interpolationAmount)
	{
		Quaternion toReturn;
		Slerp(start, end, interpolationAmount, toReturn);
		return toReturn;
	}

	void Quaternion::Conjugate(const Quaternion &quaternion, Quaternion &result)
	{
		result.X = -quaternion.X;
		result.Y = -quaternion.Y;
		result.Z = -quaternion.Z;
		result.W = quaternion.W;
	}

	Quaternion Quaternion::Conjugate(Quaternion quaternion)
	{
		Quaternion toReturn;
		Conjugate(quaternion, toReturn);
		return toReturn;
	}

	void Quaternion::Inverse(const Quaternion &quaternion, Quaternion &result)
	{
		Fix64 inverseSquaredNorm = quaternion.X * quaternion.X + quaternion.Y * quaternion.Y + quaternion.Z * quaternion.Z + quaternion.W * quaternion.W;
		result.X = -quaternion.X * inverseSquaredNorm;
		result.Y = -quaternion.Y * inverseSquaredNorm;
		result.Z = -quaternion.Z * inverseSquaredNorm;
		result.W = quaternion.W * inverseSquaredNorm;
	}

	Quaternion Quaternion::Inverse(Quaternion quaternion)
	{
		Quaternion result;
		Inverse(quaternion, result);
		return result;
	}

	bool Quaternion::operator ==(Quaternion b) const
	{
		return this->X == b.X && this->Y == b.Y && this->Z == b.Z && this->W == b.W;
	}

	bool Quaternion::operator !=(Quaternion b) const
	{
		return this->X != b.X || this->Y != b.Y || this->Z != b.Z || this->W != b.W;
	}

	void Quaternion::Negate(const Quaternion &a, Quaternion &b)
	{
		b.X = -a.X;
		b.Y = -a.Y;
		b.Z = -a.Z;
		b.W = -a.W;
	}

	Quaternion Quaternion::Negate(Quaternion q)
	{
		Quaternion result;
		Negate(q, result);
		return result;
	}

	Quaternion Quaternion::operator -()
	{
		Quaternion result;
		Negate(*this, result);
		return result;
	}

	bool Quaternion::Equals(Quaternion other)
	{
		return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
	}

	void Quaternion::Transform(const Vector3 &v, const Quaternion &rotation, Vector3 &result)
	{
		//This operation is an optimized-down version of v' = q * v * q^-1.
		//The expanded form would be to treat v as an 'axis only' quaternion
		//and perform standard quaternion multiplication.  Assuming q is normalized,
		//q^-1 can be replaced by a conjugation.
		Fix64 x2 = rotation.X + rotation.X;
		Fix64 y2 = rotation.Y + rotation.Y;
		Fix64 z2 = rotation.Z + rotation.Z;
		Fix64 xx2 = rotation.X * x2;
		Fix64 xy2 = rotation.X * y2;
		Fix64 xz2 = rotation.X * z2;
		Fix64 yy2 = rotation.Y * y2;
		Fix64 yz2 = rotation.Y * z2;
		Fix64 zz2 = rotation.Z * z2;
		Fix64 wx2 = rotation.W * x2;
		Fix64 wy2 = rotation.W * y2;
		Fix64 wz2 = rotation.W * z2;
		//Defer the component setting since they're used in computation.
		Fix64 transformedX = v.X * (F64::C1 - yy2 - zz2) + v.Y * (xy2 - wz2) + v.Z * (xz2 + wy2);
		Fix64 transformedY = v.X * (xy2 + wz2) + v.Y * (F64::C1 - xx2 - zz2) + v.Z * (yz2 - wx2);
		Fix64 transformedZ = v.X * (xz2 - wy2) + v.Y * (yz2 + wx2) + v.Z * (F64::C1 - xx2 - yy2);
		result.X = transformedX;
		result.Y = transformedY;
		result.Z = transformedZ;
	}

	Vector3 Quaternion::Transform(Vector3 v, Quaternion rotation)
	{
		Vector3 toReturn;
		Transform(v, rotation, toReturn);
		return toReturn;
	}

	void Quaternion::TransformX(Fix64 x, const Quaternion &rotation, Vector3 result)
	{
		//This operation is an optimized-down version of v' = q * v * q^-1.
		//The expanded form would be to treat v as an 'axis only' quaternion
		//and perform standard quaternion multiplication.  Assuming q is normalized,
		//q^-1 can be replaced by a conjugation.
		Fix64 y2 = rotation.Y + rotation.Y;
		Fix64 z2 = rotation.Z + rotation.Z;
		Fix64 xy2 = rotation.X * y2;
		Fix64 xz2 = rotation.X * z2;
		Fix64 yy2 = rotation.Y * y2;
		Fix64 zz2 = rotation.Z * z2;
		Fix64 wy2 = rotation.W * y2;
		Fix64 wz2 = rotation.W * z2;
		//Defer the component setting since they're used in computation.
		Fix64 transformedX = x * (F64::C1 - yy2 - zz2);
		Fix64 transformedY = x * (xy2 + wz2);
		Fix64 transformedZ = x * (xz2 - wy2);
		result.X = transformedX;
		result.Y = transformedY;
		result.Z = transformedZ;
	}

	void Quaternion::TransformY(Fix64 y, const Quaternion &rotation, Vector3 &result)
	{
		//This operation is an optimized-down version of v' = q * v * q^-1.
		//The expanded form would be to treat v as an 'axis only' quaternion
		//and perform standard quaternion multiplication.  Assuming q is normalized,
		//q^-1 can be replaced by a conjugation.
		Fix64 x2 = rotation.X + rotation.X;
		Fix64 y2 = rotation.Y + rotation.Y;
		Fix64 z2 = rotation.Z + rotation.Z;
		Fix64 xx2 = rotation.X * x2;
		Fix64 xy2 = rotation.X * y2;
		Fix64 yz2 = rotation.Y * z2;
		Fix64 zz2 = rotation.Z * z2;
		Fix64 wx2 = rotation.W * x2;
		Fix64 wz2 = rotation.W * z2;
		//Defer the component setting since they're used in computation.
		Fix64 transformedX = y * (xy2 - wz2);
		Fix64 transformedY = y * (F64::C1 - xx2 - zz2);
		Fix64 transformedZ = y * (yz2 + wx2);
		result.X = transformedX;
		result.Y = transformedY;
		result.Z = transformedZ;
	}

	void Quaternion::TransformZ(Fix64 z, const Quaternion &rotation, Vector3 &result)
	{
		//This operation is an optimized-down version of v' = q * v * q^-1.
		//The expanded form would be to treat v as an 'axis only' quaternion
		//and perform standard quaternion multiplication.  Assuming q is normalized,
		//q^-1 can be replaced by a conjugation.
		Fix64 x2 = rotation.X + rotation.X;
		Fix64 y2 = rotation.Y + rotation.Y;
		Fix64 z2 = rotation.Z + rotation.Z;
		Fix64 xx2 = rotation.X * x2;
		Fix64 xz2 = rotation.X * z2;
		Fix64 yy2 = rotation.Y * y2;
		Fix64 yz2 = rotation.Y * z2;
		Fix64 wx2 = rotation.W * x2;
		Fix64 wy2 = rotation.W * y2;
		//Defer the component setting since they're used in computation.
		Fix64 transformedX = z * (xz2 + wy2);
		Fix64 transformedY = z * (yz2 - wx2);
		Fix64 transformedZ = z * (F64::C1 - xx2 - yy2);
		result.X = transformedX;
		result.Y = transformedY;
		result.Z = transformedZ;
	}

	Quaternion Quaternion::operator *(Quaternion b) const
	{
		Quaternion toReturn;
		Multiply(*this, b, toReturn);
		return toReturn;
	}

	Quaternion Quaternion::CreateFromAxisAngle(Vector3 axis, Fix64 angle)
	{
		Fix64 halfAngle = angle * F64::C0p5;
		Fix64 s = Fix64::Sin(halfAngle);
		Quaternion q;
		q.X = axis.X * s;
		q.Y = axis.Y * s;
		q.Z = axis.Z * s;
		q.W = Fix64::Cos(halfAngle);
		return q;
	}

	void Quaternion::CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Quaternion &q)
	{
		Fix64 halfAngle = angle * F64::C0p5;
		Fix64 s = Fix64::Sin(halfAngle);
		q.X = axis.X * s;
		q.Y = axis.Y * s;
		q.Z = axis.Z * s;
		q.W = Fix64::Cos(halfAngle);
	}

	Quaternion Quaternion::CreateFromYawPitchRoll(Fix64 yaw, Fix64 pitch, Fix64 roll)
	{
		Quaternion toReturn;
		CreateFromYawPitchRoll(yaw, pitch, roll, toReturn);
		return toReturn;
	}

	void Quaternion::CreateFromYawPitchRoll(Fix64 yaw, Fix64 pitch, Fix64 roll, Quaternion &q)
	{
		Fix64 halfRoll = roll * F64::C0p5;
		Fix64 halfPitch = pitch * F64::C0p5;
		Fix64 halfYaw = yaw * F64::C0p5;

		Fix64 sinRoll = Fix64::Sin(halfRoll);
		Fix64 sinPitch = Fix64::Sin(halfPitch);
		Fix64 sinYaw = Fix64::Sin(halfYaw);

		Fix64 cosRoll = Fix64::Cos(halfRoll);
		Fix64 cosPitch = Fix64::Cos(halfPitch);
		Fix64 cosYaw = Fix64::Cos(halfYaw);

		Fix64 cosYawCosPitch = cosYaw * cosPitch;
		Fix64 cosYawSinPitch = cosYaw * sinPitch;
		Fix64 sinYawCosPitch = sinYaw * cosPitch;
		Fix64 sinYawSinPitch = sinYaw * sinPitch;

		q.X = cosYawSinPitch * cosRoll + sinYawCosPitch * sinRoll;
		q.Y = sinYawCosPitch * cosRoll - cosYawSinPitch * sinRoll;
		q.Z = cosYawCosPitch * sinRoll - sinYawSinPitch * cosRoll;
		q.W = cosYawCosPitch * cosRoll + sinYawSinPitch * sinRoll;
	}

	Fix64 Quaternion::GetAngleFromQuaternion(const Quaternion &q)
	{
		Fix64 qw = Fix64::Abs(q.W);
		if (qw > F64::C1)
			return F64::C0;
		return F64::C2 * Fix64::Acos(qw);
	}

	void Quaternion::GetRelativeRotation(const Quaternion &start, const Quaternion &end, Quaternion &relative)
	{
		Quaternion startInverse;
		Conjugate(start, startInverse);
		Concatenate(startInverse, end, relative);
	}

	void Quaternion::GetLocalRotation(const Quaternion &rotation, const Quaternion &targetBasis, Quaternion &localRotation)
	{
		Quaternion basisInverse;
		Conjugate(targetBasis, basisInverse);
		Concatenate(rotation, basisInverse, localRotation);
	}

	string Quaternion::ToString()
	{
		return "{ X: " + (string) X + ", Y: " + (string) Y + ", Z: " + (string) Z + ", W: " + (string) W + "}";
	}
}
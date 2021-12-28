#pragma once

#include "Matrix3x3.h"
#include "Matrix.h"

namespace BepuUtilities
{
  
	Matrix3x3 Matrix3x3::GetIdentity()
	{
		Matrix3x3 toReturn;
		toReturn.X = Vector3(1, 0, 0);
		toReturn.Y = Vector3(0, 1, 0);
		toReturn.Z = Vector3(0, 0, 1);
		return toReturn;
	}

	void Matrix3x3::Add(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result)
	{
		result.X = a.X + b.X;
		result.Y = a.Y + b.Y;
		result.Z = a.Z + b.Z;
	}

	void Matrix3x3::Scale(Matrix3x3 matrix, Fix64 scale, Matrix3x3 &result)
	{
		result.X = matrix.X * scale;
		result.Y = matrix.Y * scale;
		result.Z = matrix.Z * scale;
	}

	void Matrix3x3::Subtract(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result)
	{
		result.X = a.X - b.X;
		result.Y = a.Y - b.Y;
		result.Z = a.Z - b.Z;
	}

	void Matrix3x3::Transpose(M* m, M* transposed)
	{
		//A weird function! Why?
		//1) Missing some helpful instructions for actual SIMD accelerated transposition.
		//2) Difficult to get SIMD types to generate competitive codegen due to lots of componentwise access.

		Fix64 m12 = m->M12;
		Fix64 m13 = m->M13;
		Fix64 m23 = m->M23;
		transposed->M11 = m->M11;
		transposed->M12 = m->M21;
		transposed->M13 = m->M31;

		transposed->M21 = m12;
		transposed->M22 = m->M22;
		transposed->M23 = m->M32;

		transposed->M31 = m13;
		transposed->M32 = m23;
		transposed->M33 = m->M33;
	}

	void Matrix3x3::Transpose(Matrix3x3* m, Matrix3x3* transposed)
	{
		Transpose((M*)m, (M*)transposed);
	}

	void Matrix3x3::Transpose(const Matrix3x3 &m, Matrix3x3 &transposed)
	{
		auto xy = m.X.Y;
		auto xz = m.X.Z;
		auto yz = m.Y.Z;
		transposed.X = Vector3(m.X.X, m.Y.X, m.Z.X);
		transposed.Y = Vector3(xy, m.Y.Y, m.Z.Y);
		transposed.Z = Vector3(xz, yz, m.Z.Z);
	}

	Fix64 Matrix3x3::Determinant()
	{
		return Vector3::Dot(X, Vector3::Cross(Y, Z));
	}

	void Matrix3x3::Invert(const Matrix3x3 &m, Matrix3x3 &inverse)
	{
		//Current implementation of cross far from optimal without shuffles, and even then this has some room for improvement.
		//Inverts should be really rare, so it's not too concerning. Use the scalar version when possible until ryujit improves (and we improve this implementation).
		Vector3 yz = Vector3::Cross(m.Y, m.Z);
		Vector3 zx = Vector3::Cross(m.Z, m.X);
		Vector3 xy = Vector3::Cross(m.X, m.Y);
		Fix64 inverseDeterminant = Fix64(1.0) / Vector3::Dot(m.X, yz);
		inverse.X = yz * inverseDeterminant;
		inverse.Y = zx * inverseDeterminant;
		inverse.Z = xy * inverseDeterminant;
		Transpose(inverse, inverse);
	}

	void Matrix3x3::Invert(Matrix3x3* m, Matrix3x3* inverse)
	{
		M* mScalar = (M*)m;
		M* inverseScalar = (M*)inverse;

		Fix64 m11 = mScalar->M22 * mScalar->M33 - mScalar->M32 * mScalar->M23;
		Fix64 m21 = mScalar->M23 * mScalar->M31 - mScalar->M33 * mScalar->M21;
		Fix64 m31 = mScalar->M21 * mScalar->M32 - mScalar->M31 * mScalar->M22;
		Fix64 determinantInverse = Fix64(1.0) / (m11 * mScalar->M11 + m21 * mScalar->M12 + m31 * mScalar->M13);

		Fix64 m12 = mScalar->M32 * mScalar->M13 - mScalar->M12 * mScalar->M33;
		Fix64 m22 = mScalar->M33 * mScalar->M11 - mScalar->M13 * mScalar->M31;
		Fix64 m32 = mScalar->M31 * mScalar->M12 - mScalar->M11 * mScalar->M32;

		Fix64 m13 = mScalar->M12 * mScalar->M23 - mScalar->M22 * mScalar->M13;
		Fix64 m23 = mScalar->M13 * mScalar->M21 - mScalar->M23 * mScalar->M11;
		Fix64 m33 = mScalar->M11 * mScalar->M22 - mScalar->M21 * mScalar->M12;

		inverseScalar->M11 = m11 * determinantInverse;
		inverseScalar->M21 = m21 * determinantInverse;
		inverseScalar->M31 = m31 * determinantInverse;

		inverseScalar->M12 = m12 * determinantInverse;
		inverseScalar->M22 = m22 * determinantInverse;
		inverseScalar->M32 = m32 * determinantInverse;

		inverseScalar->M13 = m13 * determinantInverse;
		inverseScalar->M23 = m23 * determinantInverse;
		inverseScalar->M33 = m33 * determinantInverse;
	}

	void Matrix3x3::Transform(const Vector3 &v, const Matrix3x3 &m, Vector3 &result)
	{
		Vector3 x = Vector3(v.X);
		Vector3 y = Vector3(v.Y);
		Vector3 z = Vector3(v.Z);
		result = m.X * x + m.Y * y + m.Z * z;
	}

	void Matrix3x3::TransformTranspose(const Vector3 &v, const Matrix3x3 &m, Vector3 &result)
	{
		result = Vector3(
			Vector3::Dot(v, m.X),
			Vector3::Dot(v, m.Y),
			Vector3::Dot(v, m.Z));
	}

	void Matrix3x3::Multiply(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result)
	{
		Vector3 bX = b.X;
		Vector3 bY = b.Y;
		{
			Vector3 x = Vector3(a.X.X);
			Vector3 y = Vector3(a.X.Y);
			Vector3 z = Vector3(a.X.Z);
			result.X = x * bX + y * bY + z * b.Z;
		}

		{
			Vector3 x = Vector3(a.Y.X);
			Vector3 y = Vector3(a.Y.Y);
			Vector3 z = Vector3(a.Y.Z);
			result.Y = x * bX + y * bY + z * b.Z;
		}

		{
			Vector3 x = Vector3(a.Z.X);
			Vector3 y = Vector3(a.Z.Y);
			Vector3 z = Vector3(a.Z.Z);
			result.Z = x * bX + y * bY + z * b.Z;
		}
	}

	void Matrix3x3::MultiplyTransposed(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result)
	{
		Vector3 bX = b.X;
		Vector3 bY = b.Y;
		{
			Vector3 x = Vector3(a.X.X);
			Vector3 y = Vector3(a.Y.X);
			Vector3 z = Vector3(a.Z.X);
			result.X = x * bX + y * bY + z * b.Z;
		}

		{
			Vector3 x = Vector3(a.X.Y);
			Vector3 y = Vector3(a.Y.Y);
			Vector3 z = Vector3(a.Z.Y);
			result.Y = x * bX + y * bY + z * b.Z;
		}

		{
			Vector3 x = Vector3(a.X.Z);
			Vector3 y = Vector3(a.Y.Z);
			Vector3 z = Vector3(a.Z.Z);
			result.Z = x * bX + y * bY + z * b.Z;
		}
	}

	void Matrix3x3::CreateFromMatrix(const Matrix &matrix, Matrix3x3 &matrix3x3)
	{
		matrix3x3.X = Vector3(matrix.X.X, matrix.X.Y, matrix.X.Z);
		matrix3x3.Y = Vector3(matrix.Y.X, matrix.Y.Y, matrix.Y.Z);
		matrix3x3.Z = Vector3(matrix.Z.X, matrix.Z.Y, matrix.Z.Z);
	}

	void Matrix3x3::CreateFromQuaternion(const Quaternion &quaternion, Matrix3x3 &result)
	{
		Fix64 qX2 = quaternion.X + quaternion.X;
		Fix64 qY2 = quaternion.Y + quaternion.Y;
		Fix64 qZ2 = quaternion.Z + quaternion.Z;
		Fix64 XX = qX2 * quaternion.X;
		Fix64 YY = qY2 * quaternion.Y;
		Fix64 ZZ = qZ2 * quaternion.Z;
		Fix64 XY = qX2 * quaternion.Y;
		Fix64 XZ = qX2 * quaternion.Z;
		Fix64 XW = qX2 * quaternion.W;
		Fix64 YZ = qY2 * quaternion.Z;
		Fix64 YW = qY2 * quaternion.W;
		Fix64 ZW = qZ2 * quaternion.W;

		result.X = Vector3(
			Fix64(1) - YY - ZZ,
			XY + ZW,
			XZ - YW);

		result.Y = Vector3(
			XY - ZW,
			Fix64(1) - XX - ZZ,
			YZ + XW);

		result.Z = Vector3(
			XZ + YW,
			YZ - XW,
			Fix64(1) - XX - YY);
	}

	Matrix3x3 Matrix3x3::CreateFromQuaternion(const Quaternion &quaternion)
	{
		Matrix3x3 toReturn;
		CreateFromQuaternion(quaternion, toReturn);
		return toReturn;
	}

	void Matrix3x3::CreateScale(const Vector3 &scale, Matrix3x3 &linearTransform)
	{
		linearTransform.X = Vector3(scale.X, 0, 0);
		linearTransform.Y = Vector3(0, scale.Y, 0);
		linearTransform.Z = Vector3(0, 0, scale.Z);
	}

	void Matrix3x3::CreateFromAxisAngle(Vector3 axis, Fix64 angle, Matrix3x3 result)
	{
		//TODO: Could be better simdified.
		Fix64 xx = axis.X * axis.X;
		Fix64 yy = axis.Y * axis.Y;
		Fix64 zz = axis.Z * axis.Z;
		Fix64 xy = axis.X * axis.Y;
		Fix64 xz = axis.X * axis.Z;
		Fix64 yz = axis.Y * axis.Z;

		Fix64 sinAngle = Fix64::Sin(angle);
		Fix64 oneMinusCosAngle = Fix64(1) - Fix64::Cos(angle);

		result.X = Vector3(
			Fix64(1) + oneMinusCosAngle * (xx - Fix64(1)),
			axis.Z * sinAngle + oneMinusCosAngle * xy,
			-axis.Y * sinAngle + oneMinusCosAngle * xz);

		result.Y = Vector3(
			-axis.Z * sinAngle + oneMinusCosAngle * xy,
			Fix64(1) + oneMinusCosAngle * (yy - Fix64(1)),
			axis.X * sinAngle + oneMinusCosAngle * yz);

		result.Z = Vector3(
			axis.Y * sinAngle + oneMinusCosAngle * xz,
			-axis.X * sinAngle + oneMinusCosAngle * yz,
			Fix64(1) + oneMinusCosAngle * (zz - Fix64(1)));
	}

	Matrix3x3 Matrix3x3::CreateFromAxisAngle(const Vector3 &axis, Fix64 angle)
	{
		Matrix3x3 result;
		CreateFromAxisAngle(axis, angle, result);
		return result;
	}

	void Matrix3x3::CreateCrossProduct(const Vector3 &v, Matrix3x3 &result)
	{
		result.X.X = 0.0;
		result.X.Y = -v.Z;
		result.X.Z = v.Y;
		result.Y.X = v.Z;
		result.Y.Y = 0.0;
		result.Y.Z = -v.X;
		result.Z.X = -v.Y;
		result.Z.Y = v.X;
		result.Z.Z = 0.0;
	}

	Matrix3x3 Matrix3x3::operator *(const Matrix3x3 &m2)
	{
		Matrix3x3 toReturn;
		Multiply(*this, m2, toReturn);
		return toReturn;
	}
}

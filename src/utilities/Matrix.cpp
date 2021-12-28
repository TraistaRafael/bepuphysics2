#include "Matrix.h"

namespace BepuUtilities
{
	Matrix::Matrix() {};

	Matrix::Matrix(Fix64 m11, Fix64 m12, Fix64 m13, Fix64 m14,
		Fix64 m21, Fix64 m22, Fix64 m23, Fix64 m24,
		Fix64 m31, Fix64 m32, Fix64 m33, Fix64 m34,
		Fix64 m41, Fix64 m42, Fix64 m43, Fix64 m44)
	{
		this->M11 = m11;
		this->M12 = m12;
		this->M13 = m13;
		this->M14 = m14;

		this->M21 = m21;
		this->M22 = m22;
		this->M23 = m23;
		this->M24 = m24;

		this->M31 = m31;
		this->M32 = m32;
		this->M33 = m33;
		this->M34 = m34;

		this->M41 = m41;
		this->M42 = m42;
		this->M43 = m43;
		this->M44 = m44;
	}

	Vector3 Matrix::GetTranslation()
	{
		return Vector3(M41, M42, M43);
	}

	void Matrix::SetTranslation(const Vector3 &v)
	{
		this->M41 = v.X;
		this->M42 = v.Y;
		this->M43 = v.Z;
	}

	Vector3 Matrix::GetBackward()
	{
		Vector3 vector;
		vector.X = M31;
		vector.Y = M32;
		vector.Z = M33;
		return vector;
	}

	void Matrix::SetBackward(const Vector3 &v)
	{
		M31 = v.X;
		M32 = v.Y;
		M33 = v.Z;
	}

	Vector3 Matrix::GetDown()
	{
		Vector3 vector;
		vector.X = -M21;
		vector.Y = -M22;
		vector.Z = -M23;
		return vector;
	}

	void Matrix::SetDown(const Vector3 &v)
	{
		M21 = -v.X;
		M22 = -v.Y;
		M23 = -v.Z;
	}

	Vector3 Matrix::GetForward()
	{
		Vector3 vector;
		vector.X = -M31;
		vector.Y = -M32;
		vector.Z = -M33;
		return vector;
	}

	void Matrix::SetForward(const Vector3 &v)
	{
		M31 = -v.X;
		M32 = -v.Y;
		M33 = -v.Z;
	}

	Vector3 Matrix::GetLeft()
	{
		Vector3 vector;
		vector.X = -M11;
		vector.Y = -M12;
		vector.Z = -M13;
		return vector;
	}

	void Matrix::SetLeft(const Vector3 &v)
	{
		M11 = -v.X;
		M12 = -v.Y;
		M13 = -v.Z;
	}

	Vector3 Matrix::GetRight()
	{
		Vector3 vector;
		vector.X = M11;
		vector.Y = M12;
		vector.Z = M13;
		return vector;
	}

	void Matrix::SetRight(const Vector3 &v)
	{
		M11 = v.X;
		M12 = v.Y;
		M13 = v.Z;
	}

	Vector3 Matrix::GetUp()
	{
		Vector3 vector;
		vector.X = M21;
		vector.Y = M22;
		vector.Z = M23;
		return vector;
	}

	void Matrix::SetUp(const Vector3 &v)
	{
		M21 = v.X;
		M22 = v.Y;
		M23 = v.Z;
	}

	Fix64 Matrix::Determinant()
	{
		//Compute the re-used 2x2 determinants.
		Fix64 det1 = M33 * M44 - M34 * M43;
		Fix64 det2 = M32 * M44 - M34 * M42;
		Fix64 det3 = M32 * M43 - M33 * M42;
		Fix64 det4 = M31 * M44 - M34 * M41;
		Fix64 det5 = M31 * M43 - M33 * M41;
		Fix64 det6 = M31 * M42 - M32 * M41;
		return
			(M11 * ((M22 * det1 - M23 * det2) + M24 * det3)) -
			(M12 * ((M21 * det1 - M23 * det4) + M24 * det5)) +
			(M13 * ((M21 * det2 - M22 * det4) + M24 * det6)) -
			(M14 * ((M21 * det3 - M22 * det5) + M23 * det6));
	}

	void Matrix::Transpose()
	{
		Fix64 intermediate = M12;
		M12 = M21;
		M21 = intermediate;

		intermediate = M13;
		M13 = M31;
		M31 = intermediate;

		intermediate = M14;
		M14 = M41;
		M41 = intermediate;

		intermediate = M23;
		M23 = M32;
		M32 = intermediate;

		intermediate = M24;
		M24 = M42;
		M42 = intermediate;

		intermediate = M34;
		M34 = M43;
		M43 = intermediate;
	}

	Matrix Matrix::CreateFromAxisAngle(Vector3 &axis, Fix64 angle)
	{
		Matrix toReturn;
		CreateFromAxisAngle(axis, angle, toReturn);
		return toReturn;
	}

	void Matrix::CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Matrix &result)
	{
		Fix64 xx = axis.X * axis.X;
		Fix64 yy = axis.Y * axis.Y;
		Fix64 zz = axis.Z * axis.Z;
		Fix64 xy = axis.X * axis.Y;
		Fix64 xz = axis.X * axis.Z;
		Fix64 yz = axis.Y * axis.Z;

		Fix64 sinAngle = Fix64::Sin(angle);
		Fix64 oneMinusCosAngle = F64::C1 - Fix64::Cos(angle);

		result.M11 = F64::C1 + oneMinusCosAngle * (xx - F64::C1);
		result.M21 = -axis.Z * sinAngle + oneMinusCosAngle * xy;
		result.M31 = axis.Y * sinAngle + oneMinusCosAngle * xz;
		result.M41 = F64::C0;

		result.M12 = axis.Z * sinAngle + oneMinusCosAngle * xy;
		result.M22 = F64::C1 + oneMinusCosAngle * (yy - F64::C1);
		result.M32 = -axis.X * sinAngle + oneMinusCosAngle * yz;
		result.M42 = F64::C0;

		result.M13 = -axis.Y * sinAngle + oneMinusCosAngle * xz;
		result.M23 = axis.X * sinAngle + oneMinusCosAngle * yz;
		result.M33 = F64::C1 + oneMinusCosAngle * (zz - F64::C1);
		result.M43 = F64::C0;

		result.M14 = F64::C0;
		result.M24 = F64::C0;
		result.M34 = F64::C0;
		result.M44 = F64::C1;
	}

	void Matrix::CreateFromQuaternion(const Quaternion &quaternion, Matrix &result)
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

		result.M11 = F64::C1 - YY - ZZ;
		result.M21 = XY - ZW;
		result.M31 = XZ + YW;
		result.M41 = F64::C0;

		result.M12 = XY + ZW;
		result.M22 = F64::C1 - XX - ZZ;
		result.M32 = YZ - XW;
		result.M42 = F64::C0;

		result.M13 = XZ - YW;
		result.M23 = YZ + XW;
		result.M33 = F64::C1 - XX - YY;
		result.M43 = F64::C0;

		result.M14 = F64::C0;
		result.M24 = F64::C0;
		result.M34 = F64::C0;
		result.M44 = F64::C1;
	}

	Matrix Matrix::CreateFromQuaternion(Quaternion &quaternion)
	{
		Matrix toReturn;
		CreateFromQuaternion(quaternion, toReturn);
		return toReturn;
	}

	void Matrix::Multiply(const Matrix &a, const Matrix &b, Matrix &result)
	{
		Fix64 resultM11 = a.M11 * b.M11 + a.M12 * b.M21 + a.M13 * b.M31 + a.M14 * b.M41;
		Fix64 resultM12 = a.M11 * b.M12 + a.M12 * b.M22 + a.M13 * b.M32 + a.M14 * b.M42;
		Fix64 resultM13 = a.M11 * b.M13 + a.M12 * b.M23 + a.M13 * b.M33 + a.M14 * b.M43;
		Fix64 resultM14 = a.M11 * b.M14 + a.M12 * b.M24 + a.M13 * b.M34 + a.M14 * b.M44;

		Fix64 resultM21 = a.M21 * b.M11 + a.M22 * b.M21 + a.M23 * b.M31 + a.M24 * b.M41;
		Fix64 resultM22 = a.M21 * b.M12 + a.M22 * b.M22 + a.M23 * b.M32 + a.M24 * b.M42;
		Fix64 resultM23 = a.M21 * b.M13 + a.M22 * b.M23 + a.M23 * b.M33 + a.M24 * b.M43;
		Fix64 resultM24 = a.M21 * b.M14 + a.M22 * b.M24 + a.M23 * b.M34 + a.M24 * b.M44;

		Fix64 resultM31 = a.M31 * b.M11 + a.M32 * b.M21 + a.M33 * b.M31 + a.M34 * b.M41;
		Fix64 resultM32 = a.M31 * b.M12 + a.M32 * b.M22 + a.M33 * b.M32 + a.M34 * b.M42;
		Fix64 resultM33 = a.M31 * b.M13 + a.M32 * b.M23 + a.M33 * b.M33 + a.M34 * b.M43;
		Fix64 resultM34 = a.M31 * b.M14 + a.M32 * b.M24 + a.M33 * b.M34 + a.M34 * b.M44;

		Fix64 resultM41 = a.M41 * b.M11 + a.M42 * b.M21 + a.M43 * b.M31 + a.M44 * b.M41;
		Fix64 resultM42 = a.M41 * b.M12 + a.M42 * b.M22 + a.M43 * b.M32 + a.M44 * b.M42;
		Fix64 resultM43 = a.M41 * b.M13 + a.M42 * b.M23 + a.M43 * b.M33 + a.M44 * b.M43;
		Fix64 resultM44 = a.M41 * b.M14 + a.M42 * b.M24 + a.M43 * b.M34 + a.M44 * b.M44;

		result.M11 = resultM11;
		result.M12 = resultM12;
		result.M13 = resultM13;
		result.M14 = resultM14;

		result.M21 = resultM21;
		result.M22 = resultM22;
		result.M23 = resultM23;
		result.M24 = resultM24;

		result.M31 = resultM31;
		result.M32 = resultM32;
		result.M33 = resultM33;
		result.M34 = resultM34;

		result.M41 = resultM41;
		result.M42 = resultM42;
		result.M43 = resultM43;
		result.M44 = resultM44;
	}

	Matrix Matrix::Multiply(Matrix &a, Matrix &b)
	{
		Matrix result;
		Multiply(a, b, result);
		return result;
	}

	void Matrix::Multiply(const Matrix &matrix, Fix64 scale, Matrix &result)
	{
		result.M11 = matrix.M11 * scale;
		result.M12 = matrix.M12 * scale;
		result.M13 = matrix.M13 * scale;
		result.M14 = matrix.M14 * scale;

		result.M21 = matrix.M21 * scale;
		result.M22 = matrix.M22 * scale;
		result.M23 = matrix.M23 * scale;
		result.M24 = matrix.M24 * scale;

		result.M31 = matrix.M31 * scale;
		result.M32 = matrix.M32 * scale;
		result.M33 = matrix.M33 * scale;
		result.M34 = matrix.M34 * scale;

		result.M41 = matrix.M41 * scale;
		result.M42 = matrix.M42 * scale;
		result.M43 = matrix.M43 * scale;
		result.M44 = matrix.M44 * scale;
	}

	Matrix Matrix::operator *(Matrix &a, Matrix &b)
	{
		Matrix toReturn;
		Multiply(a, b, toReturn);
		return toReturn;
	}

	Matrix Matrix::operator *(Matrix &m, Fix64 f)
	{
		Matrix result;
		Multiply(m, f, result);
		return result;
	}

	Matrix Matrix::operator *(Fix64 f, Matrix &m)
	{
		Matrix result;
		Multiply(m, f, result);
		return result;
	}

	void Matrix::Transform(const Vector4 &v, const Matrix &matrix, Vector4 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		Fix64 vW = v.W;
		result.X = vX * matrix.M11 + vY * matrix.M21 + vZ * matrix.M31 + vW * matrix.M41;
		result.Y = vX * matrix.M12 + vY * matrix.M22 + vZ * matrix.M32 + vW * matrix.M42;
		result.Z = vX * matrix.M13 + vY * matrix.M23 + vZ * matrix.M33 + vW * matrix.M43;
		result.W = vX * matrix.M14 + vY * matrix.M24 + vZ * matrix.M34 + vW * matrix.M44;
	}

	Vector4 Matrix::Transform(const Vector4 &v, const Matrix &matrix)
	{
		Vector4 toReturn;
		Transform(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::TransformTranspose(const Vector4 &v, const Matrix &matrix, Vector4 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		Fix64 vW = v.W;
		result.X = vX * matrix.M11 + vY * matrix.M12 + vZ * matrix.M13 + vW * matrix.M14;
		result.Y = vX * matrix.M21 + vY * matrix.M22 + vZ * matrix.M23 + vW * matrix.M24;
		result.Z = vX * matrix.M31 + vY * matrix.M32 + vZ * matrix.M33 + vW * matrix.M34;
		result.W = vX * matrix.M41 + vY * matrix.M42 + vZ * matrix.M43 + vW * matrix.M44;
	}

	Vector4 Matrix::TransformTranspose(Vector4 &v, Matrix &matrix)
	{
		Vector4 toReturn;
		TransformTranspose(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::Transform(const Vector3 &v, const Matrix &matrix, Vector4 &result)
	{
		result.X = v.X * matrix.M11 + v.Y * matrix.M21 + v.Z * matrix.M31 + matrix.M41;
		result.Y = v.X * matrix.M12 + v.Y * matrix.M22 + v.Z * matrix.M32 + matrix.M42;
		result.Z = v.X * matrix.M13 + v.Y * matrix.M23 + v.Z * matrix.M33 + matrix.M43;
		result.W = v.X * matrix.M14 + v.Y * matrix.M24 + v.Z * matrix.M34 + matrix.M44;
	}

	Vector4 Matrix::Transform(Vector3 &v, Matrix &matrix)
	{
		Vector4 toReturn;
		Transform(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::TransformTranspose(const Vector3 &v, const Matrix &matrix, Vector4 &result)
	{
		result.X = v.X * matrix.M11 + v.Y * matrix.M12 + v.Z * matrix.M13 + matrix.M14;
		result.Y = v.X * matrix.M21 + v.Y * matrix.M22 + v.Z * matrix.M23 + matrix.M24;
		result.Z = v.X * matrix.M31 + v.Y * matrix.M32 + v.Z * matrix.M33 + matrix.M34;
		result.W = v.X * matrix.M41 + v.Y * matrix.M42 + v.Z * matrix.M43 + matrix.M44;
	}

	Vector4 Matrix::TransformTranspose(Vector3 &v, Matrix &matrix)
	{
		Vector4 toReturn;
		TransformTranspose(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::Transform(const Vector3 &v, const Matrix &matrix, Vector3 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		result.X = vX * matrix.M11 + vY * matrix.M21 + vZ * matrix.M31 + matrix.M41;
		result.Y = vX * matrix.M12 + vY * matrix.M22 + vZ * matrix.M32 + matrix.M42;
		result.Z = vX * matrix.M13 + vY * matrix.M23 + vZ * matrix.M33 + matrix.M43;
	}

	void Matrix::TransformTranspose(const Vector3 &v, const Matrix &matrix, Vector3 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		result.X = vX * matrix.M11 + vY * matrix.M12 + vZ * matrix.M13 + matrix.M14;
		result.Y = vX * matrix.M21 + vY * matrix.M22 + vZ * matrix.M23 + matrix.M24;
		result.Z = vX * matrix.M31 + vY * matrix.M32 + vZ * matrix.M33 + matrix.M34;
	}

	void Matrix::TransformNormal(const Vector3 &v, const Matrix &matrix, Vector3 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		result.X = vX * matrix.M11 + vY * matrix.M21 + vZ * matrix.M31;
		result.Y = vX * matrix.M12 + vY * matrix.M22 + vZ * matrix.M32;
		result.Z = vX * matrix.M13 + vY * matrix.M23 + vZ * matrix.M33;
	}

	Vector3 Matrix::TransformNormal(Vector3 &v, Matrix &matrix)
	{
		Vector3 toReturn;
		TransformNormal(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::TransformNormalTranspose(const Vector3 &v, const Matrix &matrix, Vector3 &result)
	{
		Fix64 vX = v.X;
		Fix64 vY = v.Y;
		Fix64 vZ = v.Z;
		result.X = vX * matrix.M11 + vY * matrix.M12 + vZ * matrix.M13;
		result.Y = vX * matrix.M21 + vY * matrix.M22 + vZ * matrix.M23;
		result.Z = vX * matrix.M31 + vY * matrix.M32 + vZ * matrix.M33;
	}

	Vector3 Matrix::TransformNormalTranspose(Vector3 &v, Matrix &matrix)
	{
		Vector3 toReturn;
		TransformNormalTranspose(v, matrix, toReturn);
		return toReturn;
	}

	void Matrix::Transpose(const Matrix &m, Matrix &transposed)
	{
		Fix64 intermediate = m.M12;
		transposed.M12 = m.M21;
		transposed.M21 = intermediate;

		intermediate = m.M13;
		transposed.M13 = m.M31;
		transposed.M31 = intermediate;

		intermediate = m.M14;
		transposed.M14 = m.M41;
		transposed.M41 = intermediate;

		intermediate = m.M23;
		transposed.M23 = m.M32;
		transposed.M32 = intermediate;

		intermediate = m.M24;
		transposed.M24 = m.M42;
		transposed.M42 = intermediate;

		intermediate = m.M34;
		transposed.M34 = m.M43;
		transposed.M43 = intermediate;

		transposed.M11 = m.M11;
		transposed.M22 = m.M22;
		transposed.M33 = m.M33;
		transposed.M44 = m.M44;
	}

	void Matrix::InvertRigid(const Matrix &m, Matrix &inverted)
	{
		//Invert (transpose) the upper left 3x3 rotation.
		Fix64 intermediate = m.M12;
		inverted.M12 = m.M21;
		inverted.M21 = intermediate;

		intermediate = m.M13;
		inverted.M13 = m.M31;
		inverted.M31 = intermediate;

		intermediate = m.M23;
		inverted.M23 = m.M32;
		inverted.M32 = intermediate;

		inverted.M11 = m.M11;
		inverted.M22 = m.M22;
		inverted.M33 = m.M33;

		//Translation component
		Fix64 vX = m.M41;
		Fix64 vY = m.M42;
		Fix64 vZ = m.M43;
		inverted.M41 = -(vX * inverted.M11 + vY * inverted.M21 + vZ * inverted.M31);
		inverted.M42 = -(vX * inverted.M12 + vY * inverted.M22 + vZ * inverted.M32);
		inverted.M43 = -(vX * inverted.M13 + vY * inverted.M23 + vZ * inverted.M33);

		//Last chunk.
		inverted.M14 = F64::C0;
		inverted.M24 = F64::C0;
		inverted.M34 = F64::C0;
		inverted.M44 = F64::C1;
	}

	Matrix Matrix::InvertRigid(Matrix &m)
	{
		Matrix inverse;
		InvertRigid(m, inverse);
		return inverse;
	}

	Matrix Matrix::GetIdentity()
	{
		Matrix toReturn;
		toReturn.M11 = F64::C1;
		toReturn.M12 = F64::C0;
		toReturn.M13 = F64::C0;
		toReturn.M14 = F64::C0;

		toReturn.M21 = F64::C0;
		toReturn.M22 = F64::C1;
		toReturn.M23 = F64::C0;
		toReturn.M24 = F64::C0;

		toReturn.M31 = F64::C0;
		toReturn.M32 = F64::C0;
		toReturn.M33 = F64::C1;
		toReturn.M34 = F64::C0;

		toReturn.M41 = F64::C0;
		toReturn.M42 = F64::C0;
		toReturn.M43 = F64::C0;
		toReturn.M44 = F64::C1;
		return toReturn;
	}

	void Matrix::CreateOrthographicRH(Fix64 left, Fix64 right, Fix64 bottom, Fix64 top, Fix64 zNear, Fix64 zFar, Matrix &projection)
	{
		Fix64 width = right - left;
		Fix64 height = top - bottom;
		Fix64 depth = zFar - zNear;
		projection.M11 = F64::C2 / width;
		projection.M12 = F64::C0;
		projection.M13 = F64::C0;
		projection.M14 = F64::C0;

		projection.M21 = F64::C0;
		projection.M22 = F64::C2 / height;
		projection.M23 = F64::C0;
		projection.M24 = F64::C0;

		projection.M31 = F64::C0;
		projection.M32 = F64::C0;
		projection.M33 = Fix64(-1) / depth;
		projection.M34 = F64::C0;

		projection.M41 = (left + right) / -width;
		projection.M42 = (top + bottom) / -height;
		projection.M43 = zNear / -depth;
		projection.M44 = F64::C1;

	}

	void Matrix::CreatePerspectiveFieldOfViewRH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective)
	{
		Fix64 h = F64::C1 / Fix64::Tan(fieldOfView / F64::C2);
		Fix64 w = h / aspectRatio;
		perspective.M11 = w;
		perspective.M12 = F64::C0;
		perspective.M13 = F64::C0;
		perspective.M14 = F64::C0;

		perspective.M21 = F64::C0;
		perspective.M22 = h;
		perspective.M23 = F64::C0;
		perspective.M24 = F64::C0;

		perspective.M31 = F64::C0;
		perspective.M32 = F64::C0;
		perspective.M33 = farClip / (nearClip - farClip);
		perspective.M34 = -1;

		perspective.M41 = F64::C0;
		perspective.M42 = F64::C0;
		perspective.M44 = F64::C0;
		perspective.M43 = nearClip * perspective.M33;

	}

	Matrix Matrix::CreatePerspectiveFieldOfViewRH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip)
	{
		Matrix perspective;
		CreatePerspectiveFieldOfViewRH(fieldOfView, aspectRatio, nearClip, farClip, perspective);
		return perspective;
	}

	void Matrix::CreateLookAtRH(const Vector3 &position, const Vector3 &target, const Vector3 &upVector, Matrix &viewMatrix)
	{
		Vector3 forward;
		Vector3::Subtract(target, position, forward);
		CreateViewRH(position, forward, upVector, viewMatrix);
	}

	Matrix Matrix::CreateLookAtRH(Vector3 position, Vector3 target, Vector3 upVector)
	{
		Matrix lookAt;
		Vector3 forward;
		Vector3::Subtract(target, position, forward);
		CreateViewRH(position, forward, upVector, lookAt);
		return lookAt;
	}

	void Matrix::CreateViewRH(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &viewMatrix)
	{
		Vector3 z;
		Fix64 length = forward.Length();
		Vector3::Divide(forward, -length, z);
		Vector3 x;
		Vector3::Cross(upVector, z, x);
		x.Normalize();
		Vector3 y;
		Vector3::Cross(z, x, y);

		viewMatrix.M11 = x.X;
		viewMatrix.M12 = y.X;
		viewMatrix.M13 = z.X;
		viewMatrix.M14 = F64::C0;
		viewMatrix.M21 = x.Y;
		viewMatrix.M22 = y.Y;
		viewMatrix.M23 = z.Y;
		viewMatrix.M24 = F64::C0;
		viewMatrix.M31 = x.Z;
		viewMatrix.M32 = y.Z;
		viewMatrix.M33 = z.Z;
		viewMatrix.M34 = F64::C0;
		Vector3::Dot(x, position, viewMatrix.M41);
		Vector3::Dot(y, position, viewMatrix.M42);
		Vector3::Dot(z, position, viewMatrix.M43);
		viewMatrix.M41 = -viewMatrix.M41;
		viewMatrix.M42 = -viewMatrix.M42;
		viewMatrix.M43 = -viewMatrix.M43;
		viewMatrix.M44 = F64::C1;

	}

	Matrix Matrix::CreateViewRH(Vector3 position, Vector3 forward, Vector3 upVector)
	{
		Matrix lookat;
		CreateViewRH(position, forward, upVector, lookat);
		return lookat;
	}

	void Matrix::CreateWorldRH(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &worldMatrix)
	{
		Vector3 z;
		Fix64 length = forward.Length();
		Vector3::Divide(forward, -length, z);
		Vector3 x;
		Vector3::Cross(upVector, z, x);
		x.Normalize();
		Vector3 y;
		Vector3::Cross(z, x, y);

		worldMatrix.M11 = x.X;
		worldMatrix.M12 = x.Y;
		worldMatrix.M13 = x.Z;
		worldMatrix.M14 = F64::C0;
		worldMatrix.M21 = y.X;
		worldMatrix.M22 = y.Y;
		worldMatrix.M23 = y.Z;
		worldMatrix.M24 = F64::C0;
		worldMatrix.M31 = z.X;
		worldMatrix.M32 = z.Y;
		worldMatrix.M33 = z.Z;
		worldMatrix.M34 = F64::C0;

		worldMatrix.M41 = position.X;
		worldMatrix.M42 = position.Y;
		worldMatrix.M43 = position.Z;
		worldMatrix.M44 = F64::C1;

	}

	Matrix Matrix::CreateWorldRH(Vector3 position, Vector3 forward, Vector3 upVector)
	{
		Matrix lookat;
		CreateWorldRH(position, forward, upVector, lookat);
		return lookat;
	}

	void Matrix::CreateTranslation(const Vector3 &translation, Matrix &translationMatrix)
	{
		translationMatrix = Matrix();
		translationMatrix.M11 = F64::C1;
		translationMatrix.M22 = F64::C1;
		translationMatrix.M33 = F64::C1;
		translationMatrix.M44 = F64::C1;
		translationMatrix.M41 = translation.X;
		translationMatrix.M42 = translation.Y;
		translationMatrix.M43 = translation.Z;
	}

	Matrix Matrix::CreateTranslation(Vector3 translation)
	{
		Matrix translationMatrix;
		CreateTranslation(translation, translationMatrix);
		return translationMatrix;
	}

	void Matrix::CreateScale(const Vector3 &scale, Matrix &scaleMatrix)
	{
		scaleMatrix = Matrix();
		scaleMatrix.M11 = scale.X;
		scaleMatrix.M22 = scale.Y;
		scaleMatrix.M33 = scale.Z;
		scaleMatrix.M44 = F64::C1;
	}

	Matrix Matrix::CreateScale(Vector3 &scale)
	{
		Matrix scaleMatrix;
		CreateScale(scale, scaleMatrix);
		return scaleMatrix;
	}

	void Matrix::CreateScale(Fix64 x, Fix64 y, Fix64 z, Matrix &scaleMatrix)
	{
		scaleMatrix = Matrix();
		scaleMatrix.M11 = x;
		scaleMatrix.M22 = y;
		scaleMatrix.M33 = z;
		scaleMatrix.M44 = F64::C1;
	}

	Matrix Matrix::CreateScale(Fix64 x, Fix64 y, Fix64 z)
	{
		Matrix scaleMatrix;
		CreateScale(x, y, z, scaleMatrix);
		return scaleMatrix;
	}

	string Matrix::ToString()
	{
		return "{" + (string)M11 + ", " + (string)M12 + ", " + (string)M13 + ", " + (string)M14 + "} " +
			"{" + (string)M21 + ", " + (string)M22 + ", " + (string)M23 + ", " + (string)M24 + "} " +
			"{" + (string)M31 + ", " + (string)M32 + ", " + (string)M33 + ", " + (string)M34 + "} " +
			"{" + (string)M41 + ", " + (string)M42 + ", " + (string)M43 + ", " + (string)M44 + "}";
	}
}

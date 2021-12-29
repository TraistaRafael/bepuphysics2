#include "Matrix.h"
#include "Matrix3x3.h"
#include "Vector4.h"
#include "Vector3.h"
#include "Quaternion.h"

namespace Utilities
{

	Matrix Matrix::GetIdentity()
	{
		Matrix result;
		result.X = Vector4(1, 0, 0, 0);
		result.Y = Vector4(0, 1, 0, 0);
		result.Z = Vector4(0, 0, 1, 0);
		result.W = Vector4(0, 0, 0, 1);
		return result;
	}

	Vector3 Matrix::GetTranslation()
	{
		return Vector3(W.X, W.Y, W.Z);
	}

	void Matrix::SetTranslation(const Vector3& value)
	{
		W = Vector4(value, W.W);
	}

	void Matrix::Transpose(M* m, M* transposed)
	{
		//A weird function! Why?
		//1) Missing some helpful instructions for actual SIMD accelerated transposition.
		//2) Difficult to get SIMD types to generate competitive codegen due to lots of componentwise access.

		Fix64 m12 = m->M12;
		Fix64 m13 = m->M13;
		Fix64 m14 = m->M14;
		Fix64 m23 = m->M23;
		Fix64 m24 = m->M24;
		Fix64 m34 = m->M34;
		transposed->M11 = m->M11;
		transposed->M12 = m->M21;
		transposed->M13 = m->M31;
		transposed->M14 = m->M41;

		transposed->M21 = m12;
		transposed->M22 = m->M22;
		transposed->M23 = m->M32;
		transposed->M24 = m->M42;

		transposed->M31 = m13;
		transposed->M32 = m23;
		transposed->M33 = m->M33;
		transposed->M34 = m->M43;

		transposed->M41 = m14;
		transposed->M42 = m24;
		transposed->M43 = m34;
		transposed->M44 = m->M44;
	}

	void Matrix::Transpose(Matrix* m, Matrix* transposed)
	{
		Transpose((M*)m, (M*)transposed);
	}

	void Matrix::Transpose(const Matrix &m, Matrix &transposed)
	{
		//Not an ideal implementation. Shuffles would be handy.
		Fix64 xy = m.X.Y;
		Fix64 xz = m.X.Z;
		Fix64 xw = m.X.W;
		Fix64 yz = m.Y.Z;
		Fix64 yw = m.Y.W;
		Fix64 zw = m.Z.W;
		transposed.X = Vector4(m.X.X, m.Y.X, m.Z.X, m.W.X);
		transposed.Y = Vector4(xy, m.Y.Y, m.Z.Y, m.W.Y);
		transposed.Z = Vector4(xz, yz, m.Z.Z, m.W.Z);
		transposed.W = Vector4(xw, yw, zw, m.W.W);
	}

	Matrix Matrix::Transpose(Matrix &m)
	{
		Matrix transposed;
		Transpose(&m, &transposed);
		return transposed;
	}

	void Matrix::TransformTranspose(const Vector4 &v, const Matrix &m, Vector4 &result)
	{
		result = Vector4(
			Vector4::Dot(v, m.X),
			Vector4::Dot(v, m.Y),
			Vector4::Dot(v, m.Z),
			Vector4::Dot(v, m.W));
	}

	void Matrix::Transform(const Vector4 &v, const Matrix &m, Vector4 &result)
	{
		// TO-DO check Vector4(X) constructor if equals to Vector4(X, X, X, X)
		Vector4 x = Vector4(v.X, v.X, v.X, v.X);
		Vector4 y = Vector4(v.Y);
		Vector4 z = Vector4(v.Z);
		Vector4 w = Vector4(v.W);
		result = m.X * x + m.Y * y + m.Z * z + m.W * w;
	}

	void Matrix::Transform(const Vector3 &v, const Matrix &m, Vector4 &result)
	{
		Vector4 x = Vector4(v.X);
		Vector4 y = Vector4(v.Y);
		Vector4 z = Vector4(v.Z);
		result = m.X * x + m.Y * y + m.Z * z + m.W;
	}

	inline void Matrix::Multiply(const Matrix &a, const Matrix &b, Matrix result)
	{
		Vector4 bX = b.X;
		Vector4 bY = b.Y;
		Vector4 bZ = b.Z;
		{
			Vector4 x = Vector4(a.X.X);
			Vector4 y = Vector4(a.X.Y);
			Vector4 z = Vector4(a.X.Z);
			Vector4 w = Vector4(a.X.W);
			result.X = (x * bX + y * bY) + (z * bZ + w * b.W);
		}

		{
			Vector4 x = Vector4(a.Y.X);
			Vector4 y = Vector4(a.Y.Y);
			Vector4 z = Vector4(a.Y.Z);
			Vector4 w = Vector4(a.Y.W);
			result.Y = (x * bX + y * bY) + (z * bZ + w * b.W);
		}

		{
			Vector4 x = Vector4(a.Z.X);
			Vector4 y = Vector4(a.Z.Y);
			Vector4 z = Vector4(a.Z.Z);
			Vector4 w = Vector4(a.Z.W);
			result.Z = (x * bX + y * bY) + (z * bZ + w * b.W);
		}

		{
			Vector4 x = Vector4(a.W.X);
			Vector4 y = Vector4(a.W.Y);
			Vector4 z = Vector4(a.W.Z);
			Vector4 w = Vector4(a.W.W);
			result.W = (x * bX + y * bY) + (z * bZ + w * b.W);
		}
	}

	void Matrix::CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Matrix &result)
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

		result.X = Vector4(
			Fix64(1) + oneMinusCosAngle * (xx - Fix64(1)),
			axis.Z * sinAngle + oneMinusCosAngle * xy,
			-axis.Y * sinAngle + oneMinusCosAngle * xz,
			Fix64(0));

		result.Y = Vector4(
			-axis.Z * sinAngle + oneMinusCosAngle * xy,
			Fix64(1) + oneMinusCosAngle * (yy - Fix64(1)),
			axis.X * sinAngle + oneMinusCosAngle * yz,
			Fix64(0));

		result.Z = Vector4(
			axis.Y * sinAngle + oneMinusCosAngle * xz,
			-axis.X * sinAngle + oneMinusCosAngle * yz,
			Fix64(1) + oneMinusCosAngle * (zz - Fix64(1)),
			Fix64(0));

		result.W = Vector4(0, 0, 0, 1);
	}

	Matrix Matrix::CreateFromAxisAngle(const Vector3 &axis, Fix64 angle)
	{
		Matrix result;
		CreateFromAxisAngle(axis, angle, result);
		return result;
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

		result.X = Vector4(
			Fix64(1) - YY - ZZ,
			XY + ZW,
			XZ - YW,
			Fix64(0));

		result.Y = Vector4(
			XY - ZW,
			Fix64(1) - XX - ZZ,
			YZ + XW,
			Fix64(0));

		result.Z = Vector4(
			XZ + YW,
			YZ - XW,
			Fix64(1) - XX - YY,
			Fix64(0));

		result.W = Vector4(
			0,
			0,
			0,
			1);
	}

	Matrix Matrix::CreateFromQuaternion(const Quaternion &quaternion)
	{
		Matrix toReturn;
		CreateFromQuaternion(quaternion, toReturn);
		return toReturn;
	}

	Matrix Matrix::operator *(const Matrix &other) const
	{
		Matrix toReturn;
		Multiply(*this, other, toReturn);
		return toReturn;
	}

	void Matrix::CreatePerspectiveFieldOfView(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective)
	{
		Fix64 h = Fix64(1) / (Fix64::Tan(fieldOfView * Fix64(0.5f)));
		Fix64 w = h / aspectRatio;
		Fix64 m33 = farClip / (nearClip - farClip);
		perspective.X = Vector4(w, 0, 0, 0);
		perspective.Y = Vector4(0, h, 0, 0);
		perspective.Z = Vector4(0, 0, m33, -1);
		perspective.W = Vector4(0, 0, nearClip * m33, 0);
	}

	void Matrix::CreatePerspectiveFieldOfViewLH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective)
	{
		Fix64 h = Fix64(1) / (Fix64::Tan(fieldOfView * Fix64(0.5)));
		Fix64 w = h / aspectRatio;
		Fix64 m33 = farClip / (farClip - nearClip);
		perspective.X = Vector4(w, 0, 0, 0);
		perspective.Y = Vector4(0, h, 0, 0);
		perspective.Z = Vector4(0, 0, m33, 1);
		perspective.W = Vector4(0, 0, -nearClip * m33, 0);
	}

	Matrix Matrix::CreatePerspectiveFromFieldOfViews(Fix64 verticalFieldOfView, Fix64 horizontalFieldOfView, Fix64 nearClip, Fix64 farClip)
	{
		Matrix perspective;
		CreatePerspectiveFromFieldOfViews(verticalFieldOfView, horizontalFieldOfView, nearClip, farClip, perspective);
		return perspective;
	}

	void Matrix::CreatePerspectiveFromFieldOfViews(Fix64 verticalFieldOfView, Fix64 horizontalFieldOfView, Fix64 nearClip, Fix64 farClip, Matrix &perspective)
	{
		Fix64 h = Fix64(1) / (Fix64::Tan(verticalFieldOfView * Fix64(0.5)));
		Fix64 w = Fix64(1) / (Fix64::Tan(horizontalFieldOfView * Fix64(0.5)));
		Fix64 m33 = farClip / (nearClip - farClip);
		perspective.X = Vector4(w, 0, 0, 0);
		perspective.Y = Vector4(0, h, 0, 0);
		perspective.Z = Vector4(0, 0, m33, -1);
		perspective.W = Vector4(0, 0, nearClip * m33, 0);
	}

	Matrix Matrix::CreatePerspectiveFieldOfView(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip)
	{
		Matrix toReturn;
		CreatePerspectiveFieldOfView(fieldOfView, aspectRatio, nearClip, farClip, toReturn);
		return toReturn;
	}

	void Matrix::CreateOrthographic(Fix64 left, Fix64 right, Fix64 bottom, Fix64 top, Fix64 zNear, Fix64 zFar, Matrix &projection)
	{
		Fix64 width = right - left;
		Fix64 height = top - bottom;
		Fix64 depth = zFar - zNear;
		projection.X = Vector4(Fix64(2) / width, 0, 0, 0);
		projection.Y = Vector4(0, Fix64(2) / height, 0, 0);
		projection.Z = Vector4(0, 0, Fix64(-1) / depth, 0);
		projection.W = Vector4((left + right) / -width, (top + bottom) / -height, zNear / -depth, Fix64(1));
	}

	void Matrix::Invert(const Matrix &m, Matrix &inverted)
	{
		//TODO: This could be quite a bit faster, especially once shuffles exist... But inverting a 4x4 matrix should approximately never occur.
		Fix64 s0 = m.X.X * m.Y.Y - m.Y.X * m.X.Y;
		Fix64 s1 = m.X.X * m.Y.Z - m.Y.X * m.X.Z;
		Fix64 s2 = m.X.X * m.Y.W - m.Y.X * m.X.W;
		Fix64 s3 = m.X.Y * m.Y.Z - m.Y.Y * m.X.Z;
		Fix64 s4 = m.X.Y * m.Y.W - m.Y.Y * m.X.W;
		Fix64 s5 = m.X.Z * m.Y.W - m.Y.Z * m.X.W;

		Fix64 c5 = m.Z.Z * m.W.W - m.W.Z * m.Z.W;
		Fix64 c4 = m.Z.Y * m.W.W - m.W.Y * m.Z.W;
		Fix64 c3 = m.Z.Y * m.W.Z - m.W.Y * m.Z.Z;
		Fix64 c2 = m.Z.X * m.W.W - m.W.X * m.Z.W;
		Fix64 c1 = m.Z.X * m.W.Z - m.W.X * m.Z.Z;
		Fix64 c0 = m.Z.X * m.W.Y - m.W.X * m.Z.Y;

		Fix64 inverseDeterminant = Fix64(1.0) / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);

		Fix64 m11 = m.X.X;
		Fix64 m12 = m.X.Y;
		Fix64 m13 = m.X.Z;
		Fix64 m14 = m.X.W;
		Fix64 m21 = m.Y.X;
		Fix64 m22 = m.Y.Y;
		Fix64 m23 = m.Y.Z;
		Fix64 m31 = m.Z.X;
		Fix64 m32 = m.Z.Y;
		Fix64 m33 = m.Z.Z;

		Fix64 m41 = m.W.X;
		Fix64 m42 = m.W.Y;

		inverted.X = Vector4(
			m.Y.Y * c5 - m.Y.Z * c4 + m.Y.W * c3,
			-m.X.Y * c5 + m.X.Z * c4 - m.X.W * c3,
			m.W.Y * s5 - m.W.Z * s4 + m.W.W * s3,
			-m.Z.Y * s5 + m.Z.Z * s4 - m.Z.W * s3) * inverseDeterminant;

		inverted.Y = Vector4(
			-m.Y.X * c5 + m.Y.Z * c2 - m.Y.W * c1,
			m11 * c5 - m13 * c2 + m14 * c1,
			-m.W.X * s5 + m.W.Z * s2 - m.W.W * s1,
			m.Z.X * s5 - m.Z.Z * s2 + m.Z.W * s1) * inverseDeterminant;

		inverted.Z = Vector4(
			m21 * c4 - m22 * c2 + m.Y.W * c0,
			-m11 * c4 + m12 * c2 - m14 * c0,
			m.W.X * s4 - m.W.Y * s2 + m.W.W * s0,
			-m31 * s4 + m32 * s2 - m.Z.W * s0) * inverseDeterminant;

		inverted.W = Vector4(
			-m21 * c3 + m22 * c1 - m23 * c0,
			m11 * c3 - m12 * c1 + m13 * c0,
			-m41 * s3 + m42 * s1 - m.W.Z * s0,
			m31 * s3 - m32 * s1 + m33 * s0) * inverseDeterminant;
	}

	Matrix Matrix::Invert(Matrix &m)
	{
		Matrix inverted;
		Invert(m, inverted);
		return inverted;
	}

	void Matrix::CreateLookAt(const Vector3 &position, Vector3 &target, Vector3 &upVector, Matrix &viewMatrix)
	{
		Vector3 forward = target - position;
		CreateView(position, forward, upVector, viewMatrix);
	}

	Matrix Matrix::CreateLookAt(const Vector3 &position, const Vector3 &target, const Vector3 &upVector)
	{
		Matrix lookAt;
		CreateView(position, target - position, upVector, lookAt);
		return lookAt;
	}

	void Matrix::CreateView(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &viewMatrix)
	{
		Fix64 length = forward.Length();
		Vector3 z = forward / -length;
		Vector3 x = Vector3::Cross(upVector, z);
		x = Vector3::Normalize(x);
		Vector3 y = Vector3::Cross(z, x);

		viewMatrix.X = Vector4(x.X, y.X, z.X, 0);
		viewMatrix.Y = Vector4(x.Y, y.Y, z.Y, 0);
		viewMatrix.Z = Vector4(x.Z, y.Z, z.Z, 0);
		viewMatrix.W = Vector4(
			-Vector3::Dot(x, position),
			-Vector3::Dot(y, position),
			-Vector3::Dot(z, position), 1);
	}

	Matrix Matrix::CreateView(const Vector3 &position, const Vector3 &forward, Vector3 & upVector)
	{
		Matrix lookat;
		CreateView(position, forward, upVector, lookat);
		return lookat;
	}

	void Matrix::CreateRigid(const Matrix3x3 &rotation, const Vector3 &position, Matrix &world)
	{
		/*world.X = Vector4(rotation.X, 0);
		world.Y = Vector4(rotation.Y, 0);
		world.Z = Vector4(rotation.Z, 0);
		world.W = Vector4(position, 1);*/
	}

	void Matrix::CreateRigid(const Quaternion &rotation, const Vector3 &position, Matrix &world)
	{
		/*Matrix3x3 rotationMatrix;
		Matrix3x3::CreateFromQuaternion(rotation, rotationMatrix);
		world.X = Vector4(rotationMatrix.X, 0);
		world.Y = Vector4(rotationMatrix.Y, 0);
		world.Z = Vector4(rotationMatrix.Z, 0);
		world.W = Vector4(position, 1);*/
	}

	//void Matrix::CreateFrom3x3(const Matrix3x3 &matrix3x3, Matrix &matrix4x4)
	//{
	//	/*matrix4x4.X = Vector4(matrix3x3.X, 0);
	//	matrix4x4.Y = Vector4(matrix3x3.Y, 0);
	//	matrix4x4.Z = Vector4(matrix3x3.Z, 0);
	//	matrix4x4.W = Vector4(0, 0, 0, 1);*/
	//}
	//
	//Matrix Matrix::CreateFrom3x3(const Matrix3x3 &matrix3x3)
	//{
	//	/*Matrix matrix4x4;
	//	CreateFrom3x3(matrix3x3, matrix4x4);
	//	return matrix4x4;*/
	//}
}

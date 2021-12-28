#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include "../Common.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

namespace BepuUtilities
{
	/// <summary>
	/// Provides XNA-like 4x4 matrix math.
	/// </summary>
	class Matrix
	{
	public:

		/// <summary>
		/// Value at row 1, column 1 of the matrix.
		/// </summary>
		Fix64 M11;

		/// <summary>
		/// Value at row 1, column 2 of the matrix.
		/// </summary>
		Fix64 M12;

		/// <summary>
		/// Value at row 1, column 3 of the matrix.
		/// </summary>
		Fix64 M13;

		/// <summary>
		/// Value at row 1, column 4 of the matrix.
		/// </summary>
		Fix64 M14;

		/// <summary>
		/// Value at row 2, column 1 of the matrix.
		/// </summary>
		Fix64 M21;

		/// <summary>
		/// Value at row 2, column 2 of the matrix.
		/// </summary>
		Fix64 M22;

		/// <summary>
		/// Value at row 2, column 3 of the matrix.
		/// </summary>
		Fix64 M23;

		/// <summary>
		/// Value at row 2, column 4 of the matrix.
		/// </summary>
		Fix64 M24;

		/// <summary>
		/// Value at row 3, column 1 of the matrix.
		/// </summary>
		Fix64 M31;

		/// <summary>
		/// Value at row 3, column 2 of the matrix.
		/// </summary>
		Fix64 M32;

		/// <summary>
		/// Value at row 3, column 3 of the matrix.
		/// </summary>
		Fix64 M33;

		/// <summary>
		/// Value at row 3, column 4 of the matrix.
		/// </summary>
		Fix64 M34;

		/// <summary>
		/// Value at row 4, column 1 of the matrix.
		/// </summary>
		Fix64 M41;

		/// <summary>
		/// Value at row 4, column 2 of the matrix.
		/// </summary>
		Fix64 M42;

		/// <summary>
		/// Value at row 4, column 3 of the matrix.
		/// </summary>
		Fix64 M43;

		/// <summary>
		/// Value at row 4, column 4 of the matrix.
		/// </summary>
		Fix64 M44;

		/// <summary>
		/// Matrix default constructor
		/// </summary>
		Matrix();

		/// <summary>
		/// Constructs a new 4 row, 4 column matrix.
		/// </summary>
		/// <param name="m11">Value at row 1, column 1 of the matrix.</param>
		/// <param name="m12">Value at row 1, column 2 of the matrix.</param>
		/// <param name="m13">Value at row 1, column 3 of the matrix.</param>
		/// <param name="m14">Value at row 1, column 4 of the matrix.</param>
		/// <param name="m21">Value at row 2, column 1 of the matrix.</param>
		/// <param name="m22">Value at row 2, column 2 of the matrix.</param>
		/// <param name="m23">Value at row 2, column 3 of the matrix.</param>
		/// <param name="m24">Value at row 2, column 4 of the matrix.</param>
		/// <param name="m31">Value at row 3, column 1 of the matrix.</param>
		/// <param name="m32">Value at row 3, column 2 of the matrix.</param>
		/// <param name="m33">Value at row 3, column 3 of the matrix.</param>
		/// <param name="m34">Value at row 3, column 4 of the matrix.</param>
		/// <param name="m41">Value at row 4, column 1 of the matrix.</param>
		/// <param name="m42">Value at row 4, column 2 of the matrix.</param>
		/// <param name="m43">Value at row 4, column 3 of the matrix.</param>
		/// <param name="m44">Value at row 4, column 4 of the matrix.</param>
		Matrix(Fix64 m11, Fix64 m12, Fix64 m13, Fix64 m14,
			Fix64 m21, Fix64 m22, Fix64 m23, Fix64 m24,
			Fix64 m31, Fix64 m32, Fix64 m33, Fix64 m34,
			Fix64 m41, Fix64 m42, Fix64 m43, Fix64 m44);

		/// <summary>
		/// Gets or sets the translation component of the transform.
		/// </summary>
		Vector3 GetTranslation();

		void SetTranslation(const Vector3 &v);

		/// <summary>
		/// Gets or sets the backward vector of the matrix.
		/// </summary>
		Vector3 GetBackward();

		void SetBackward(const Vector3 &v);

		/// <summary>
		/// Gets or sets the down vector of the matrix.
		/// </summary>
		Vector3 GetDown();

		void SetDown(const Vector3 &v);
	
		/// <summary>
		/// Gets or sets the forward vector of the matrix.
		/// </summary>
		Vector3 GetForward();

		void SetForward(const Vector3 &v);

		/// <summary>
		/// Gets or sets the left vector of the matrix.
		/// </summary>
		Vector3 GetLeft();

		void SetLeft(const Vector3 &v);

		/// <summary>
		/// Gets or sets the right vector of the matrix.
		/// </summary>
		Vector3 GetRight();

		void SetRight(const Vector3 &v);

		/// <summary>
		/// Gets or sets the up vector of the matrix.
		/// </summary>
		Vector3 GetUp();

		void SetUp(const Vector3 &v);

		/// <summary>
		/// Computes the determinant of the matrix.
		/// </summary>
		/// <returns></returns>
		Fix64 Determinant();

		/// <summary>
		/// Transposes the matrix in-place.
		/// </summary>
		void Transpose();

		/// <summary>
		/// Creates a matrix representing the given axis and angle rotation.
		/// </summary>
		/// <param name="axis">Axis around which to rotate.</param>
		/// <param name="angle">Angle to rotate around the axis.</param>
		/// <returns>Matrix created from the axis and angle.</returns>
		static Matrix CreateFromAxisAngle(Vector3 &axis, Fix64 angle);

		/// <summary>
		/// Creates a matrix representing the given axis and angle rotation.
		/// </summary>
		/// <param name="axis">Axis around which to rotate.</param>
		/// <param name="angle">Angle to rotate around the axis.</param>
		/// <param name="result">Matrix created from the axis and angle.</param>
		static void CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Matrix &result);

		/// <summary>
		/// Creates a rotation matrix from a quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to convert.</param>
		/// <param name="result">Rotation matrix created from the quaternion.</param>
		static void CreateFromQuaternion(const Quaternion &quaternion, Matrix &result);

		/// <summary>
		/// Creates a rotation matrix from a quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to convert.</param>
		/// <returns>Rotation matrix created from the quaternion.</returns>
		static Matrix CreateFromQuaternion(Quaternion &quaternion);

		/// <summary>
		/// Multiplies two matrices together.
		/// </summary>
		/// <param name="a">First matrix to multiply.</param>
		/// <param name="b">Second matrix to multiply.</param>
		/// <param name="result">Combined transformation.</param>
		static void Multiply(const Matrix &a, const Matrix &b, Matrix &result);

		/// <summary>
		/// Multiplies two matrices together.
		/// </summary>
		/// <param name="a">First matrix to multiply.</param>
		/// <param name="b">Second matrix to multiply.</param>
		/// <returns>Combined transformation.</returns>
		static Matrix Multiply(Matrix &a, Matrix &b);

		/// <summary>
		/// Scales all components of the matrix.
		/// </summary>
		/// <param name="matrix">Matrix to scale.</param>
		/// <param name="scale">Amount to scale.</param>
		/// <param name="result">Scaled matrix.</param>
		static void Multiply(const Matrix &matrix, Fix64 scale, Matrix &result);

		/// <summary>
		/// Multiplies two matrices together.
		/// </summary>
		/// <param name="a">First matrix to multiply.</param>
		/// <param name="b">Second matrix to multiply.</param>
		/// <returns>Combined transformation.</returns>
		static Matrix operator *(Matrix &a, Matrix &b);

		/// <summary>
		/// Scales all components of the matrix by the given value.
		/// </summary>
		/// <param name="m">First matrix to multiply.</param>
		/// <param name="f">Scaling value to apply to all components of the matrix.</param>
		/// <returns>Product of the multiplication.</returns>
		static Matrix operator *(Matrix &m, Fix64 f);

		/// <summary>
		/// Scales all components of the matrix by the given value.
		/// </summary>
		/// <param name="m">First matrix to multiply.</param>
		/// <param name="f">Scaling value to apply to all components of the matrix.</param>
		/// <returns>Product of the multiplication.</returns>
		static Matrix operator *(Fix64 f, Matrix &m);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void Transform(const Vector4 &v, const Matrix &matrix, Vector4 &result);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector4 Transform(const Vector4 &v, const Matrix &matrix);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformTranspose(const Vector4 &v, const Matrix &matrix, Vector4 &result);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector4 TransformTranspose(Vector4 &v, Matrix &matrix);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void Transform(const Vector3 &v, const Matrix &matrix, Vector4 &result);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector4 Transform(Vector3 &v, Matrix &matrix);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformTranspose(const Vector3 &v, const Matrix &matrix, Vector4 &result);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector4 TransformTranspose(Vector3 &v, Matrix &matrix);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void Transform(const Vector3 &v, const Matrix &matrix, Vector3 &result);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformTranspose(const Vector3 &v, const Matrix &matrix, Vector3 &result);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformNormal(const Vector3 &v, const Matrix &matrix, Vector3 &result);

		/// <summary>
		/// Transforms a vector using a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector3 TransformNormal(Vector3 &v, Matrix &matrix);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformNormalTranspose(const Vector3 &v, const Matrix &matrix, Vector3 &result);

		/// <summary>
		/// Transforms a vector using the transpose of a matrix.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="matrix">Transform to tranpose and apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector3 TransformNormalTranspose(Vector3 &v, Matrix &matrix);


		/// <summary>
		/// Transposes the matrix.
		/// </summary>
		/// <param name="m">Matrix to transpose.</param>
		/// <param name="transposed">Matrix to transpose.</param>
		static void Transpose(const Matrix &m, Matrix &transposed);

		/// <summary>
		/// Inverts the matrix.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <param name="inverted">Inverted version of the matrix.</param>
		// TO-DO
		//static void Invert(const Matrix &m, Matrix &inverted)
		//{
		//	//Matrix4x8::Invert(m, inverted);
		//}

		/// <summary>
		/// Inverts the matrix.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <returns>Inverted version of the matrix.</returns>
		// TO-DO
		/*static Matrix Invert(Matrix m)
		{
			Matrix inverted;
			Invert(ref m, out inverted);
			return inverted;
		}*/

		/// <summary>
		/// Inverts the matrix using a process that only works for rigid transforms.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <param name="inverted">Inverted version of the matrix.</param>
		static void InvertRigid(const Matrix &m, Matrix &inverted);

		/// <summary>
		/// Inverts the matrix using a process that only works for rigid transforms.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <returns>Inverted version of the matrix.</returns>
		static Matrix InvertRigid(Matrix &m);

		/// <summary>
		/// Gets the 4x4 identity matrix.
		/// </summary>
		static Matrix GetIdentity();

		/// <summary>
		/// Creates a right handed orthographic projection.
		/// </summary>
		/// <param name="left">Leftmost coordinate of the projected area.</param>
		/// <param name="right">Rightmost coordinate of the projected area.</param>
		/// <param name="bottom">Bottom coordinate of the projected area.</param>
		/// <param name="top">Top coordinate of the projected area.</param>
		/// <param name="zNear">Near plane of the projection.</param>
		/// <param name="zFar">Far plane of the projection.</param>
		/// <param name="projection">The resulting orthographic projection matrix.</param>
		static void CreateOrthographicRH(Fix64 left, Fix64 right, Fix64 bottom, Fix64 top, Fix64 zNear, Fix64 zFar, Matrix &projection);

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="fieldOfView">Field of view of the perspective in radians.</param>
		/// <param name="aspectRatio">Width of the viewport over the height of the viewport.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <param name="perspective">Resulting perspective matrix.</param>
		static void CreatePerspectiveFieldOfViewRH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective);

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="fieldOfView">Field of view of the perspective in radians.</param>
		/// <param name="aspectRatio">Width of the viewport over the height of the viewport.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <returns>Resulting perspective matrix.</returns>
		static Matrix CreatePerspectiveFieldOfViewRH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip);

		/// <summary>
		/// Creates a view matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="target">Target of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <param name="viewMatrix">Look at matrix.</param>
		static void CreateLookAtRH(const Vector3 &position, const Vector3 &target, const Vector3 &upVector, Matrix &viewMatrix);

		/// <summary>
		/// Creates a view matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="target">Target of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <returns>Look at matrix.</returns>
		static Matrix CreateLookAtRH(Vector3 position, Vector3 target, Vector3 upVector);


		/// <summary>
		/// Creates a view matrix pointing in a direction with a given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="forward">Forward direction of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <param name="viewMatrix">Look at matrix.</param>
		static void CreateViewRH(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &viewMatrix);

		/// <summary>
		/// Creates a view matrix pointing looking in a direction with a given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="forward">Forward direction of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <returns>Look at matrix.</returns>
		static Matrix CreateViewRH(Vector3 position, Vector3 forward, Vector3 upVector);

		/// <summary>
		/// Creates a world matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the transform.</param>
		/// <param name="forward">Forward direction of the transformation.</param>
		/// <param name="upVector">Up vector which is crossed against the forward vector to compute the transform's basis.</param>
		/// <param name="worldMatrix">World matrix.</param>
		static void CreateWorldRH(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &worldMatrix);

		/// <summary>
		/// Creates a world matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the transform.</param>
		/// <param name="forward">Forward direction of the transformation.</param>
		/// <param name="upVector">Up vector which is crossed against the forward vector to compute the transform's basis.</param>
		/// <returns>World matrix.</returns>
		static Matrix CreateWorldRH(Vector3 position, Vector3 forward, Vector3 upVector);

		/// <summary>
		/// Creates a matrix representing a translation.
		/// </summary>
		/// <param name="translation">Translation to be represented by the matrix.</param>
		/// <param name="translationMatrix">Matrix representing the given translation.</param>
		static void CreateTranslation(const Vector3 &translation, Matrix &translationMatrix);

		/// <summary>
		/// Creates a matrix representing a translation.
		/// </summary>
		/// <param name="translation">Translation to be represented by the matrix.</param>
		/// <returns>Matrix representing the given translation.</returns>
		static Matrix CreateTranslation(Vector3 translation);

		/// <summary>
		/// Creates a matrix representing the given axis aligned scale.
		/// </summary>
		/// <param name="scale">Scale to be represented by the matrix.</param>
		/// <param name="scaleMatrix">Matrix representing the given scale.</param>
		static void CreateScale(const Vector3 &scale, Matrix &scaleMatrix);

		/// <summary>
		/// Creates a matrix representing the given axis aligned scale.
		/// </summary>
		/// <param name="scale">Scale to be represented by the matrix.</param>
		/// <returns>Matrix representing the given scale.</returns>
		static Matrix CreateScale(Vector3 &scale);

		/// <summary>
		/// Creates a matrix representing the given axis aligned scale.
		/// </summary>
		/// <param name="x">Scale along the x axis.</param>
		/// <param name="y">Scale along the y axis.</param>
		/// <param name="z">Scale along the z axis.</param>
		/// <param name="scaleMatrix">Matrix representing the given scale.</param>
		static void CreateScale(Fix64 x, Fix64 y, Fix64 z, Matrix &scaleMatrix);

		/// <summary>
		/// Creates a matrix representing the given axis aligned scale.
		/// </summary>
		/// <param name="x">Scale along the x axis.</param>
		/// <param name="y">Scale along the y axis.</param>
		/// <param name="z">Scale along the z axis.</param>
		/// <returns>Matrix representing the given scale.</returns>
		static Matrix CreateScale(Fix64 x, Fix64 y, Fix64 z);

		/// <summary>
		/// Creates a string representation of the matrix.
		/// </summary>
		/// <returns>A string representation of the matrix.</returns>
		string ToString();
	};
}


#endif //MATRIX3X3_HEADER
#pragma once
//#ifndef MATRIX_HEADER
//#define MATRIX_HEADER

#include "../Common.h"
#include "../ForwardDeclarations.h"
#include "Vector4.h"

namespace Utilities
{
	/// <summary>
	/// Provides SIMD-aware 4x4 matrix math.
	/// </summary>
	/// <remarks>
	/// All functions assume row vectors.
	/// </remarks>
	class Matrix
	{
	public:
		/// <summary>
		/// Row 1 of the matrix.
		/// </summary>
		Vector4 X;
		/// <summary>
		/// Row 2 of the matrix.
		/// </summary>
		Vector4 Y;
		/// <summary>
		/// Row 3 of the matrix.
		/// </summary>
		Vector4 Z;
		/// <summary>
		/// Row 4 of the matrix.
		/// </summary>
		Vector4 W;

		static inline Matrix GetIdentity();

		Vector3 GetTranslation();

		void SetTranslation(const Vector3& value);

		struct M
		{
			Fix64 M11, M12, M13, M14;
			Fix64 M21, M22, M23, M24;
			Fix64 M31, M32, M33, M34;
			Fix64 M41, M42, M43, M44;
		};
		
		static inline void Transpose(M* m, M* transposed);

		static inline void Transpose(Matrix* m, Matrix* transposed);

		static inline void Transpose(const Matrix &m, Matrix &transposed);

		static inline Matrix Transpose(Matrix &m);

		/// <summary>
		/// Transforms a vector with a transposed matrix.
		/// </summary>
		/// <param name="v">Row vector to transform.</param>
		/// <param name="m">Matrix whose transpose will be applied to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static inline void TransformTranspose(const Vector4 &v, const Matrix &m, Vector4 &result);

		/// <summary>
		/// Transforms a vector with a matrix.
		/// </summary>
		/// <param name="v">Row vector to transform.</param>
		/// <param name="m">Matrix to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static inline void Transform(const Vector4 &v, const Matrix &m, Vector4 &result);

		/// <summary>
		/// Transforms a vector with a matrix. Implicitly uses 1 as the fourth component of the input vector.
		/// </summary>
		/// <param name="v">Row vector to transform.</param>
		/// <param name="m">Matrix to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static inline void Transform(const Vector3 &v, const Matrix &m, Vector4 &result);

		/// <summary>
		/// Multiplies a matrix by another matrix.
		/// </summary>
		/// <param name="a">First matrix.</param>
		/// <param name="b">Second matrix.</param>
		/// <param name="result">Result of the matrix multiplication.</param>
		static inline void Multiply(const Matrix &a, const Matrix &b, Matrix result);

		static inline void CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Matrix &result);

		static inline Matrix CreateFromAxisAngle(const Vector3 &axis, Fix64 angle);

		static inline void CreateFromQuaternion(const Quaternion &quaternion, Matrix &result);

		static inline Matrix CreateFromQuaternion(const Quaternion &quaternion);

		/// <summary>
		/// Concatenates two matrices.
		/// </summary>
		/// <param name="m1">First input matrix.</param>
		/// <param name="m2">Second input matrix.</param>
		/// <returns>Concatenated transformation of the form m1 * m2.</returns>
		Matrix operator *(const Matrix &other) const;

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="fieldOfView">Vertical field of view of the perspective in radians.</param>
		/// <param name="aspectRatio">Width of the viewport over the height of the viewport.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <param name="perspective">Resulting perspective matrix.</param>
		static inline void CreatePerspectiveFieldOfView(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective);

		/// <summary>
		/// Creates a left-handed perspective matrix.
		/// </summary>
		/// <param name="fieldOfView">Vertical field of view of the perspective in radians.</param>
		/// <param name="aspectRatio">Width of the viewport over the height of the viewport.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <param name="perspective">Resulting perspective matrix.</param>
		static inline void CreatePerspectiveFieldOfViewLH(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip, Matrix &perspective);

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="verticalFieldOfView">Vertical field of view of the perspective in radians.</param>
		/// <param name="horizontalFieldOfView">Horizontal field of view of the perspective in radians.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <returns>Resulting perspective matrix.</returns>
		static inline Matrix CreatePerspectiveFromFieldOfViews(Fix64 verticalFieldOfView, Fix64 horizontalFieldOfView, Fix64 nearClip, Fix64 farClip);

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="verticalFieldOfView">Vertical field of view of the perspective in radians.</param>
		/// <param name="horizontalFieldOfView">Horizontal field of view of the perspective in radians.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <param name="perspective">Resulting perspective matrix.</param>
		static inline void CreatePerspectiveFromFieldOfViews(Fix64 verticalFieldOfView, Fix64 horizontalFieldOfView, Fix64 nearClip, Fix64 farClip, Matrix &perspective);

		/// <summary>
		/// Creates a right-handed perspective matrix.
		/// </summary>
		/// <param name="fieldOfView">Vertical field of view of the perspective in radians.</param>
		/// <param name="aspectRatio">Width of the viewport over the height of the viewport.</param>
		/// <param name="nearClip">Near clip plane of the perspective.</param>
		/// <param name="farClip">Far clip plane of the perspective.</param>
		/// <returns>Resulting perspective matrix.</returns>
		static inline Matrix CreatePerspectiveFieldOfView(Fix64 fieldOfView, Fix64 aspectRatio, Fix64 nearClip, Fix64 farClip);

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
		static void CreateOrthographic(Fix64 left, Fix64 right, Fix64 bottom, Fix64 top, Fix64 zNear, Fix64 zFar, Matrix &projection);

		/// <summary>
		/// Inverts the matrix.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <param name="inverted">Inverted version of the matrix.</param>
		static void Invert(const Matrix &m, Matrix &inverted);

		/// <summary>
		/// Inverts the matrix.
		/// </summary>
		/// <param name="m">Matrix to invert.</param>
		/// <returns>Inverted version of the matrix.</returns>
		static Matrix Invert(Matrix &m);

		/// <summary>
		/// Creates a view matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="target">Target of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <param name="viewMatrix">Look at matrix.</param>
		static void CreateLookAt(const Vector3 &position, Vector3 &target, Vector3 &upVector, Matrix &viewMatrix);

		/// <summary>
		/// Creates a view matrix pointing from a position to a target with the given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="target">Target of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <returns>Look at matrix.</returns>
		static Matrix CreateLookAt(const Vector3 &position, const Vector3 &target, const Vector3 &upVector);

		/// <summary>
		/// Creates a view matrix pointing in a direction with a given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="forward">Forward direction of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <param name="viewMatrix">Look at matrix.</param>
		static void CreateView(const Vector3 &position, const Vector3 &forward, const Vector3 &upVector, Matrix &viewMatrix);

		/// <summary>
		/// Creates a view matrix pointing looking in a direction with a given up vector.
		/// </summary>
		/// <param name="position">Position of the camera.</param>
		/// <param name="forward">Forward direction of the camera.</param>
		/// <param name="upVector">Up vector of the camera.</param>
		/// <returns>Look at matrix.</returns>
		static Matrix CreateView(const Vector3 &position, const Vector3 &forward, Vector3 & upVector);

		/// <summary>
		/// Creates a rigid world matrix from a rotation and position.
		/// </summary>
		/// <param name="rotation">Rotation of the transform.</param>
		/// <param name="position">Position of the transform.</param>
		/// <param name="world">4x4 matrix representing the combined transform.</param>
		static inline void CreateRigid(const Matrix3x3 &rotation, const Vector3 &position, Matrix &world);

		/// <summary>
		/// Creates a rigid world matrix from a rotation and position.
		/// </summary>
		/// <param name="rotation">Rotation of the transform.</param>
		/// <param name="position">Position of the transform.</param>
		/// <param name="world">4x4 matrix representing the combined transform.</param>
		static inline void CreateRigid(const Quaternion &rotation, const Vector3 &position, Matrix &world);

		/// <summary>
		/// Creates a 4x4 matrix from a 3x3 matrix. All extra columns and rows filled with 0 except the W.W, which is set to 1.
		/// </summary>
		/// <param name="matrix3x3">Smaller matrix to base the larger matrix on.</param>
		/// <param name="matrix4x4">Larger matrix that has the smaller matrix as a submatrix.</param>
		//static void CreateFrom3x3(const Matrix3x3 &matrix3x3, Matrix &matrix4x4);

		/// <summary>
		/// Creates a 4x4 matrix from a 3x3 matrix. All extra columns and rows filled with 0 except the W.W, which is set to 1.
		/// </summary>
		/// <param name="matrix3x3">Smaller matrix to base the larger matrix on.</param>
		/// <returns>Larger matrix that has the smaller matrix as a submatrix.</returns>
		//static Matrix CreateFrom3x3(const Matrix3x3 &matrix3x3);
	};
}
//
//#endif //MATRIX3X3_HEADER
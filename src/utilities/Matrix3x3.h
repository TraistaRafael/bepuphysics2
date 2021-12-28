#ifndef MATRIX3X3_HEADER
#define MATRIX3X3_HEADER

#include "../Common.h"
#include "../ForwardDeclarations.h"
#include "Vector3.h"

namespace BepuUtilities
{
	/// <summary>
	/// 3 row, 3 column matrix.
	/// </summary>
	class Matrix3x3
	{
	public:
		struct M
		{
		public:
			Fix64 M11, M12, M13;
			Fix64 M21, M22, M23;
			Fix64 M31, M32, M33;
		};

		Vector3 X;
		Vector3 Y;
		Vector3 Z;

		/// <summary>
		/// Gets the 3x3 identity matrix.
		/// </summary>
		static inline Matrix3x3 GetIdentity();

		/// <summary>
		/// Adds the components of two matrices together.
		/// </summary>
		/// <param name="a">First matrix to add.</param>
		/// <param name="b">Second matrix to add.</param>
		/// <param name="result">Sum of the two input matrices.</param>
		static inline void Add(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result);

		/// <summary>
		/// Scales the components of a matrix by a scalar.
		/// </summary>
		/// <param name="matrix">Matrix to scale.</param>
		/// <param name="scale">Scale to apply to the matrix's components.</param>
		/// <param name="result">Scaled matrix.</param>
		static void Scale(Matrix3x3 matrix, Fix64 scale, Matrix3x3 &result);

		/// <summary>
		/// Subtracts the components of one matrix from another.
		/// </summary>
		/// <param name="a">Matrix to be subtracted from.</param>
		/// <param name="b">Matrix to subtract from a.</param>
		/// <param name="result">Difference of the two input matrices.</param>
		static void Subtract(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result);

		static void Transpose(M* m, M* transposed);

		static inline void Transpose(Matrix3x3* m, Matrix3x3* transposed);

		/// <summary>                                                                                                
		/// Computes the transposed matrix of a matrix.                                                              
		/// </summary>                                                                                               
		/// <param name="m">Matrix to transpose.</param>                                                             
		/// <param name="transposed">Transposed matrix.</param> 
		static inline void Transpose(const Matrix3x3 &m, Matrix3x3 &transposed);

		/// <summary>
		/// Calculates the determinant of the matrix.
		/// </summary>
		/// <returns>The matrix's determinant.</returns>
		inline Fix64 Determinant();

		/// <summary>
		/// Inverts the given matix.
		/// </summary>
		/// <param name="m">Matrix to be inverted.</param>
		/// <param name="inverse">Inverted matrix.</param>
		static inline void Invert(const Matrix3x3 &m, Matrix3x3 &inverse);

		/// <summary>
		/// Inverts the given matix.
		/// </summary>
		/// <param name="m">Matrix to be inverted.</param>
		/// <param name="inverse">Inverted matrix.</param>
		static inline void Invert(Matrix3x3* m, Matrix3x3* inverse);

		/// <summary>
		/// Transforms the vector by the matrix.
		/// </summary>
		/// <param name="v">Vector3 to transform.</param>
		/// <param name="m">Matrix to use as the transformation.</param>
		/// <param name="result">Product of the transformation.</param>
		static inline void Transform(const Vector3 &v, const Matrix3x3 &m, Vector3 &result);

		/// <summary>
		/// Transforms the vector by the matrix's transpose.
		/// </summary>
		/// <param name="v">Vector3 to transform.</param>
		/// <param name="m">Matrix to use as the transformation transpose.</param>
		/// <param name="result">Product of the transformation.</param>
		static inline void TransformTranspose(const Vector3 &v, const Matrix3x3 &m, Vector3 &result);

		/// <summary>
		/// Multiplies the two matrices.
		/// </summary>
		/// <param name="a">First matrix to multiply.</param>
		/// <param name="b">Second matrix to multiply.</param>
		/// <param name="result">Product of the multiplication.</param>
		static inline void Multiply(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result);

		/// <summary>
		/// Multiplies the two matrices, where a is treated as transposed: result = transpose(a) * b
		/// </summary>
		/// <param name="a">First matrix to multiply that will be transposed.</param>
		/// <param name="b">Second matrix to multiply.</param>
		/// <param name="result">Product of the multiplication.</param>
		static inline void MultiplyTransposed(const Matrix3x3 &a, const Matrix3x3 &b, Matrix3x3 &result);

		static inline void CreateFromMatrix(const Matrix &matrix, Matrix3x3 &matrix3x3);

		static inline void CreateFromQuaternion(const Quaternion &quaternion, Matrix3x3 &result);

		static inline Matrix3x3 CreateFromQuaternion(const Quaternion &quaternion);

		/// <summary>
		/// Creates a 3x3 matrix representing the given scale along its local axes.
		/// </summary>
		/// <param name="scale">Scale to represent.</param>
		/// <param name="linearTransform">Matrix representing a scale.</param>
		static inline void CreateScale(const Vector3 &scale, Matrix3x3 &linearTransform);

		/// <summary>
		/// Creates a matrix representing a rotation derived from an axis and angle.
		/// </summary>
		/// <param name="axis">Axis of the rotation.</param>
		/// <param name="angle">Angle of the rotation.</param>
		/// <param name="result">Resulting rotation matrix.</param>
		static inline void CreateFromAxisAngle(Vector3 axis, Fix64 angle, Matrix3x3 result);

		/// <summary>
		/// Creates a matrix representing a rotation derived from an axis and angle.
		/// </summary>
		/// <param name="axis">Axis of the rotation.</param>
		/// <param name="angle">Angle of the rotation.</param>
		/// <returns>Resulting rotation matrix.</returns>
		static inline Matrix3x3 CreateFromAxisAngle(const Vector3 &axis, Fix64 angle);

		/// <summary>
		/// Creates a matrix such that a x v = a * result.
		/// </summary>
		/// <param name="v">Vector to build the skew symmetric matrix from.</param>
		/// <param name="result">Skew symmetric matrix representing the cross product.</param>
		static inline void CreateCrossProduct(const Vector3 &v, Matrix3x3 &result);

		/// <summary>
		/// Concatenates two matrices.
		/// </summary>
		/// <param name="m1">First input matrix.</param>
		/// <param name="m2">Second input matrix.</param>
		/// <returns>Concatenated transformation of the form m1 * m2.</returns>
		Matrix3x3 operator *(const Matrix3x3 &m2);
	};
}

#endif //MATRIX3X3_HEADER
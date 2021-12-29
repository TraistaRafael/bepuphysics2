#pragma once
//#ifndef VECTOR3_HEADER
//#define VECTOR3_HEADER

#include "../ForwardDeclarations.h"
#include "Fix64.h"

namespace Utilities 
{
	/// <summary>
	/// Provides XNA-like 3D vector math.
	/// </summary>
	class Vector3
	{
	public:
		/// <summary>
		/// X component of the vector.
		/// </summary>
		Fix64 X;
		/// <summary>
		/// Y component of the vector.
		/// </summary>
		Fix64 Y;
		/// <summary>
		/// Z component of the vector.
		/// </summary>
		Fix64 Z;

		/// <summary>
		/// Constructs a new empty 3d vector.
		/// </summary>
		Vector3();

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="v">X, Y and X component of the vector.</param>
		Vector3(Fix64 v);

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="y">Y component of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		Vector3(Fix64 x, Fix64 y, Fix64 z);

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="xy">X and Y components of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		Vector3(Vector2 xy, Fix64 z);

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="yz">Y and Z components of the vector.</param>
		Vector3(Fix64 x, Vector2 yz);

		/// <summary>
		/// Computes the squared length of the vector.
		/// </summary>
		/// <returns>Squared length of the vector.</returns>
		Fix64 LengthSquared() const;

		/// <summary>
		/// Computes the length of the vector.
		/// </summary>
		/// <returns>Length of the vector.</returns>
		Fix64 Length() const;

		/// <summary>
		/// Normalizes the vector.
		/// </summary>
		void Normalize();

		/// <summary>
		/// Gets a string representation of the vector.
		/// </summary>
		/// <returns>String representing the vector.</returns>
		string ToString() const;

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <returns>Resulting dot product.</returns>
		static Fix64 Dot(Vector3 a, Vector3 b);

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <param name="product">Resulting dot product.</param>
		static void Dot(const Vector3 &a, const Vector3 &b, Fix64 &product);

		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <param name="sum">Sum of the two vectors.</param>
		static void Add(const Vector3 &a, const Vector3 &b, Vector3 &sum);

		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <param name="difference">Result of the subtraction.</param>
		static void Subtract(const Vector3 &a, const Vector3 &b, Vector3 &difference);

		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="scale">Amount to scale.</param>
		/// <param name="result">Scaled vector.</param>
		static void Multiply(const Vector3 &v, Fix64 scale, Vector3 &result);

		/// <summary>
		/// Multiplies two vectors on a per-component basis.
		/// </summary>
		/// <param name="a">First vector to multiply.</param>
		/// <param name="b">Second vector to multiply.</param>
		/// <param name="result">Result of the componentwise multiplication.</param>
		static void Multiply(const Vector3 &a, const Vector3 &b, Vector3 &result);

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="divisor">Value to divide the vector's components.</param>
		/// <param name="result">Result of the division.</param>
		static void Divide(const Vector3 &v, Fix64 divisor, Vector3 &result);

		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="f">Amount to scale.</param>
		/// <returns>Scaled vector.</returns>
		Vector3 operator *(Fix64 f) const;

		/*/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="f">Amount to scale.</param>
		/// <returns>Scaled vector.</returns>
		static Vector3 operator *(Fix64 f, Vector3 v)
		{
			Vector3 toReturn;
			toReturn.X = v.X * f;
			toReturn.Y = v.Y * f;
			toReturn.Z = v.Z * f;
			return toReturn;
		}
*/
		/// <summary>
		/// Multiplies two vectors on a per-component basis.
		/// </summary>
		/// <param name="a">First vector to multiply.</param>
		/// <param name="b">Second vector to multiply.</param>
		/// <returns>Result of the componentwise multiplication.</returns>
		Vector3 operator *(Vector3 b) const;

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="f">Value to divide the vector's components.</param>
		/// <returns>Result of the division.</returns>
		Vector3 operator /(Fix64 f) const;

		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <returns>Result of the subtraction.</returns>
		Vector3 operator -(Vector3 b) const;

		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <returns>Sum of the two vectors.</returns>
		Vector3 operator +(Vector3 b) const;

		/// <summary>
		/// Negates the vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <returns>Negated vector.</returns>
		Vector3 operator -();

		/// <summary>
		/// Tests two vectors for componentwise equivalence.
		/// </summary>
		/// <param name="a">First vector to test for equivalence.</param>
		/// <param name="b">Second vector to test for equivalence.</param>
		/// <returns>Whether the vectors were equivalent.</returns>
		bool operator ==(Vector3 b);

		/// <summary>
		/// Tests two vectors for componentwise inequivalence.
		/// </summary>
		/// <param name="a">First vector to test for inequivalence.</param>
		/// <param name="b">Second vector to test for inequivalence.</param>
		/// <returns>Whether the vectors were inequivalent.</returns>
		bool operator !=(Vector3 b);

		/// <summary>
		/// Indicates whether the current object is equal to another object of the same type.
		/// </summary>
		/// <returns>
		/// true if the current object is equal to the <paramref name="other"/> parameter; otherwise, false.
		/// </returns>
		/// <param name="other">An object to compare with this object.</param>
		bool Equals(Vector3 other);

		/// <summary>
		/// Computes the squared distance between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distanceSquared">Squared distance between the two vectors.</param>
		static void DistanceSquared(const Vector3 &a, const Vector3 &b, Fix64 &distanceSquared);

		/// <summary>
		/// Computes the squared distance between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Squared distance between the two vectors.</returns>
		static Fix64 DistanceSquared(Vector3 a, Vector3 b);

		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distance">Distance between the two vectors.</param>
		static void Distance(const Vector3 &a, const Vector3 &b, Fix64 &distance);

		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Distance between the two vectors.</returns>
		static Fix64 Distance(Vector3 a, Vector3 b);

		/// <summary>
		/// Gets the zero vector.
		/// </summary>
		static Vector3 GetZero();

		/// <summary>
		/// Gets the up vector (0,1,0).
		/// </summary>
		static Vector3 GetUp();

		/// <summary>
		/// Gets the down vector (0,-1,0).
		/// </summary>
		static Vector3 GetDown();

		/// <summary>
		/// Gets the right vector (1,0,0).
		/// </summary>
		static Vector3 GetRight();

		/// <summary>
		/// Gets the left vector (-1,0,0).
		/// </summary>
		static Vector3 GetLeft();

		/// <summary>
		/// Gets the forward vector (0,0,-1).
		/// </summary>
		static Vector3 GetForward();

		/// <summary>
		/// Gets the back vector (0,0,1).
		/// </summary>
		static Vector3 GetBackward();

		/// <summary>
		/// Gets a vector pointing along the X axis.
		/// </summary>
		static Vector3 GetUnitX();

		/// <summary>
		/// Gets a vector pointing along the Y axis.
		/// </summary>
		static Vector3 GetUnitY();

		/// <summary>
		/// Gets a vector pointing along the Z axis.
		/// </summary>
		static Vector3 GetUnitZ();

		/// <summary>
		/// Computes the cross product between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Cross product of the two vectors.</returns>
		static Vector3 Cross(Vector3 a, Vector3 b);

		/// <summary>
		/// Computes the cross product between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="result">Cross product of the two vectors.</param>
		static void Cross(const Vector3 &a, const Vector3 &b, Vector3 &result);

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <returns>Normalized vector.</returns>
		static Vector3 Normalize(Vector3 v);

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <param name="result">Normalized vector.</param>
		static void Normalize(const Vector3 &v, Vector3 &result);

		/// <summary>
		/// Negates a vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <param name="negated">Negated vector.</param>
		static void Negate(const Vector3 &v, Vector3 &negated);

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <param name="result">Vector with nonnegative elements.</param>
		static void Abs(const Vector3 &v, Vector3 &result);

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <returns>Vector with nonnegative elements.</returns>
		static Vector3 Abs(Vector3 v);

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="min">Vector containing the lesser values of each vector.</param>
		static void Min(const Vector3 &a, const Vector3 &b, Vector3 &min);

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the lesser values of each vector.</returns>
		static Vector3 Min(Vector3 a, Vector3 b);

		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="max">Vector containing the greater values of each vector.</param>
		static void Max(const Vector3 &a, const Vector3 &b, Vector3 &max);

		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the greater values of each vector.</returns>
		static Vector3 Max(Vector3 a, Vector3 b);

		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector3 Lerp(Vector3 start, Vector3 end, Fix64 interpolationAmount);

		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Lerp(const Vector3 &start, const Vector3 &end, Fix64 interpolationAmount, Vector3 &result);

		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Hermite(const Vector3 &value1, const Vector3 &tangent1, const Vector3 &value2, const Vector3 &tangent2, Fix64 interpolationAmount, Vector3 &result);

		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector3 Hermite(Vector3 value1, Vector3 tangent1, Vector3 value2, Vector3 tangent2, Fix64 interpolationAmount);

	};
}
//#endif //VECTOR3_HEADER
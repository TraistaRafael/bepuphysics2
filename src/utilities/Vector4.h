#pragma once
//#ifndef VECTOR4_HEADER
//#define VECTOR4_HEADER

#include "../Common.h"
#include "../ForwardDeclarations.h"
#include "Fix64.h"
//#include "Vector3.h"
//#include "Vector2.h"
//#include "Quaternion.h"

namespace Utilities
{
	/// <summary>
	/// Provides XNA-like 4-component vector math.
	/// </summary>
	class Vector4
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
		/// W component of the vector.
		/// </summary>
		Fix64 W;

		/// <summary>
		/// Constructs a new empty 4d vector.
		/// </summary>
		Vector4();

		/// <summary>
		/// Constructs new 4d vector.
		/// </summary>
		/// <param name="v">X, Y, Z and W component of the vector.</param>
		//TO-DO check to be indentical with C#
		Vector4(Fix64 v);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="y">Y component of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		/// <param name="w">W component of the vector.</param>
		Vector4(Fix64 x, Fix64 y, Fix64 z, Fix64 w);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="xyz">X, Y, and Z components of the vector.</param>
		/// <param name="w">W component of the vector.</param>
		Vector4(Vector3 xyz, Fix64 w);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="yzw">Y, Z, and W components of the vector.</param>
		Vector4(Fix64 x, Vector3 yzw);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="xy">X and Y components of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		/// <param name="w">W component of the vector.</param>
		Vector4(Vector2 xy, Fix64 z, Fix64 w);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="yz">Y and Z components of the vector.</param>
		/// <param name="w">W component of the vector.</param>
		Vector4(Fix64 x, Vector2 yz, Fix64 w);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="y">Y and Z components of the vector.</param>
		/// <param name="zw">W component of the vector.</param>
		Vector4(Fix64 x, Fix64 y, Vector2 zw);

		/// <summary>
		/// Constructs a new 4d vector.
		/// </summary>
		/// <param name="xy">X and Y components of the vector.</param>
		/// <param name="zw">Z and W components of the vector.</param>
		Vector4(Vector2 xy, Vector2 zw);

		/// <summary>
		/// Computes the squared length of the vector.
		/// </summary>
		/// <returns>Squared length of the vector.</returns>
		Fix64 LengthSquared();

		/// <summary>
		/// Computes the length of the vector.
		/// </summary>
		/// <returns>Length of the vector.</returns>
		Fix64 Length();

		/// <summary>
		/// Normalizes the vector.
		/// </summary>
		void Normalize();

		/// <summary>
		/// Gets a string representation of the vector.
		/// </summary>
		/// <returns>String representing the vector.</returns>
		string ToString();

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <returns>Resulting dot product.</returns>
		static Fix64 Dot(Vector4 a, Vector4 b);

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <param name="product">Resulting dot product.</param>
		static void Dot(const Vector4 &a, const Vector4 &b, Fix64 &product);

		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <param name="sum">Sum of the two vectors.</param>
		static void Add(const Vector4 &a, const Vector4 &b, Vector4 &sum);

		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <param name="difference">Result of the subtraction.</param>
		static void Subtract(const Vector4 &a, const Vector4 &b, Vector4 &difference);

		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="scale">Amount to scale.</param>
		/// <param name="result">Scaled vector.</param>
		static void Multiply(const Vector4 &v, Fix64 scale, Vector4 &result);

		/// <summary>
		/// Multiplies two vectors on a per-component basis.
		/// </summary>
		/// <param name="a">First vector to multiply.</param>
		/// <param name="b">Second vector to multiply.</param>
		/// <param name="result">Result of the componentwise multiplication.</param>
		static void Multiply(const Vector4 &a, const Vector4 &b, Vector4 &result);

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="divisor">Value to divide the vector's components.</param>
		/// <param name="result">Result of the division.</param>
		static void Divide(const Vector4 &v, Fix64 divisor, Vector4 &result);

		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="f">Amount to scale.</param>
		/// <returns>Scaled vector.</returns>
		Vector4 operator *(Fix64 f) const;

		/// <summary>
		/// Multiplies two vectors on a per-component basis.
		/// </summary>
		/// <param name="a">First vector to multiply.</param>
		/// <param name="b">Second vector to multiply.</param>
		/// <returns>Result of the componentwise multiplication.</returns>
		Vector4 operator *(const Vector4 &b) const;

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="f">Value to divide the vector's components.</param>
		/// <returns>Result of the division.</returns>
		Vector4 operator /(Fix64 f) const;

		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <returns>Result of the subtraction.</returns>
		Vector4 operator -(const Vector4 &b) const;

		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <returns>Sum of the two vectors.</returns>
		Vector4 operator +(const Vector4 &b) const;

		/// <summary>
		/// Negates the vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <returns>Negated vector.</returns>
		Vector4 operator -();

		/// <summary>
		/// Tests two vectors for componentwise equivalence.
		/// </summary>
		/// <param name="a">First vector to test for equivalence.</param>
		/// <param name="b">Second vector to test for equivalence.</param>
		/// <returns>Whether the vectors were equivalent.</returns>
		bool operator ==(const Vector4 &b) const;

		/// <summary>
		/// Tests two vectors for componentwise inequivalence.
		/// </summary>
		/// <param name="a">First vector to test for inequivalence.</param>
		/// <param name="b">Second vector to test for inequivalence.</param>
		/// <returns>Whether the vectors were inequivalent.</returns>
		bool operator !=(const Vector4 &b) const;

		/// <summary>
		/// Indicates whether the current object is equal to another object of the same type.
		/// </summary>
		/// <returns>
		/// true if the current object is equal to the <paramref name="other"/> parameter; otherwise, false.
		/// </returns>
		/// <param name="other">An object to compare with this object.</param>
		bool Equals(const Vector4 &other);

		/// <summary>
		/// Computes the squared distance between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distanceSquared">Squared distance between the two vectors.</param>
		static void DistanceSquared(const Vector4 &a, const Vector4 &b, Fix64 &distanceSquared);

		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distance">Distance between the two vectors.</param>
		static void Distance(const Vector4 &a, const Vector4 &b, Fix64 &distance);

		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Distance between the two vectors.</returns>
		static Fix64 Distance(Vector4 a, Vector4 b);

		/// <summary>
		/// Gets the zero vector.
		/// </summary>
		static Vector4 GetZero();

		/// <summary>
		/// Gets a vector pointing along the X axis.
		/// </summary>
		static Vector4 GetUnitX();

		/// <summary>
		/// Gets a vector pointing along the Y axis.
		/// </summary>
		static Vector4 GetUnitY();

		/// <summary>
		/// Gets a vector pointing along the Z axis.
		/// </summary>
		static Vector4 GetUnitZ();

		/// <summary>
		/// Gets a vector pointing along the Z axis.
		/// </summary>
		static Vector4 GetUnitW();

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <returns>Normalized vector.</returns>
		static Vector4 Normalize(Vector4 v);

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <param name="result">Normalized vector.</param>
		static void Normalize(const Vector4 &v, Vector4 &result);

		/// <summary>
		/// Negates a vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <param name="negated">Negated vector.</param>
		static void Negate(Vector4 v, Vector4 negated);

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <param name="result">Vector with nonnegative elements.</param>
		static void Abs(const Vector4 &v, Vector4 &result);

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <returns>Vector with nonnegative elements.</returns>
		static Vector4 Abs(Vector4 v);

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="min">Vector containing the lesser values of each vector.</param>
		static void Min(const Vector4 &a, Vector4 &b, Vector4 &min);

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the lesser values of each vector.</returns>
		static Vector4 Min(Vector4 a, Vector4 b);

		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="max">Vector containing the greater values of each vector.</param>
		static void Max(const Vector4 &a, const Vector4 &b, Vector4 &max);

		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the greater values of each vector.</returns>
		static Vector4 Max(Vector4 a, Vector4 b);

		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector4 Lerp(const Vector4 &start, const Vector4 &end, Fix64 interpolationAmount);

		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Lerp(const Vector4 &start, const Vector4 &end, Fix64 interpolationAmount, Vector4 &result);

		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Hermite(const Vector4 &value1, const Vector4 &tangent1, const Vector4 &value2, const Vector4 &tangent2, Fix64 interpolationAmount, Vector4 &result);

		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector4 Hermite(const Vector4 &value1, const Vector4 &tangent1, const Vector4 &value2, const Vector4 &tangent2, Fix64 interpolationAmount);
	};
}
//#endif //VECTOR4_HEADER
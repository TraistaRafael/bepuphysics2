#pragma once

#include "common.h"
#include "F64.h"
#include "Vector2.h"

namespace BEPUutilities
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
		Vector3()
		{
			this->X = F64::C0;
			this->Y = F64::C0;
			this->Z = F64::C0;
		}

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="y">Y component of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		Vector3(Fix64 x, Fix64 y, Fix64 z)
		{
			this->X = x;
			this->Y = y;
			this->Z = z;
		}

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="xy">X and Y components of the vector.</param>
		/// <param name="z">Z component of the vector.</param>
		Vector3(Vector2 xy, Fix64 z)
		{
			this->X = xy.X;
			this->Y = xy.Y;
			this->Z = z;
		}

		/// <summary>
		/// Constructs a new 3d vector.
		/// </summary>
		/// <param name="x">X component of the vector.</param>
		/// <param name="yz">Y and Z components of the vector.</param>
		Vector3(Fix64 x, Vector2 yz)
		{
			this->X = x;
			this->Y = yz.X;
			this->Z = yz.Y;
		}

		/// <summary>
		/// Computes the squared length of the vector.
		/// </summary>
		/// <returns>Squared length of the vector.</returns>
		Fix64 LengthSquared()
		{
			return X * X + Y * Y + Z * Z;
		}

		/// <summary>
		/// Computes the length of the vector.
		/// </summary>
		/// <returns>Length of the vector.</returns>
		Fix64 Length()
		{
			return Fix64::Sqrt(X * X + Y * Y + Z * Z);
		}

		/// <summary>
		/// Normalizes the vector.
		/// </summary>
		void Normalize()
		{
			Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y + Z * Z);
			X *= inverse;
			Y *= inverse;
			Z *= inverse;
		}

		/// <summary>
		/// Gets a string representation of the vector.
		/// </summary>
		/// <returns>String representing the vector.</returns>
		string ToString()
		{
			return "{" + (string) X + ", " + (string) Y + ", " + (string) Z + "}";
		}

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <returns>Resulting dot product.</returns>
		static Fix64 Dot(Vector3 a, Vector3 b)
		{
			return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
		}

		/// <summary>
		/// Computes the dot product of two vectors.
		/// </summary>
		/// <param name="a">First vector in the product.</param>
		/// <param name="b">Second vector in the product.</param>
		/// <param name="product">Resulting dot product.</param>
		static void Dot(const Vector3 &a, const Vector3 &b, Fix64 &product)
		{
			product = a.X * b.X + a.Y * b.Y + a.Z * b.Z;
		}
		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <param name="sum">Sum of the two vectors.</param>
		static void Add(const Vector3 &a, const Vector3 &b, Vector3 &sum)
		{
			sum.X = a.X + b.X;
			sum.Y = a.Y + b.Y;
			sum.Z = a.Z + b.Z;
		}
		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <param name="difference">Result of the subtraction.</param>
		static void Subtract(const Vector3 &a, const Vector3 &b, Vector3 &difference)
		{
			difference.X = a.X - b.X;
			difference.Y = a.Y - b.Y;
			difference.Z = a.Z - b.Z;
		}
		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="scale">Amount to scale.</param>
		/// <param name="result">Scaled vector.</param>
		static void Multiply(const Vector3 &v, Fix64 scale, Vector3 &result)
		{
			result.X = v.X * scale;
			result.Y = v.Y * scale;
			result.Z = v.Z * scale;
		}

		/// <summary>
		/// Multiplies two vectors on a per-component basis.
		/// </summary>
		/// <param name="a">First vector to multiply.</param>
		/// <param name="b">Second vector to multiply.</param>
		/// <param name="result">Result of the componentwise multiplication.</param>
		static void Multiply(const Vector3 &a, const Vector3 &b, Vector3 &result)
		{
			result.X = a.X * b.X;
			result.Y = a.Y * b.Y;
			result.Z = a.Z * b.Z;
		}

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="divisor">Value to divide the vector's components.</param>
		/// <param name="result">Result of the division.</param>
		static void Divide(const Vector3 &v, Fix64 divisor, Vector3 &result)
		{
			Fix64 inverse = F64::C1 / divisor;
			result.X = v.X * inverse;
			result.Y = v.Y * inverse;
			result.Z = v.Z * inverse;
		}
		/// <summary>
		/// Scales a vector.
		/// </summary>
		/// <param name="v">Vector to scale.</param>
		/// <param name="f">Amount to scale.</param>
		/// <returns>Scaled vector.</returns>
		Vector3 operator *(Fix64 f)
		{
			Vector3 toReturn;
			toReturn.X = this->X * f;
			toReturn.Y = this->Y * f;
			toReturn.Z = this->Z * f;
			return toReturn;
		}

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
		Vector3 operator *(Vector3 b)
		{
			Vector3 result;
			Multiply(*this, b, result);
			return result;
		}

		/// <summary>
		/// Divides a vector's components by some amount.
		/// </summary>
		/// <param name="v">Vector to divide.</param>
		/// <param name="f">Value to divide the vector's components.</param>
		/// <returns>Result of the division.</returns>
		Vector3 operator /(Fix64 f)
		{
			Vector3 toReturn;
			f = F64::C1 / f;
			toReturn.X = this->X * f;
			toReturn.Y = this->Y * f;
			toReturn.Z = this->Z * f;
			return toReturn;
		}

		/// <summary>
		/// Subtracts two vectors.
		/// </summary>
		/// <param name="a">Vector to subtract from.</param>
		/// <param name="b">Vector to subtract from the first vector.</param>
		/// <returns>Result of the subtraction.</returns>
		Vector3 operator -(Vector3 b)
		{
			Vector3 v;
			v.X = this->X - b.X;
			v.Y = this->Y - b.Y;
			v.Z = this->Z - b.Z;
			return v;
		}

		/// <summary>
		/// Adds two vectors together.
		/// </summary>
		/// <param name="a">First vector to add.</param>
		/// <param name="b">Second vector to add.</param>
		/// <returns>Sum of the two vectors.</returns>
		Vector3 operator +(Vector3 b)
		{
			Vector3 v;
			v.X = this->X + b.X;
			v.Y = this->Y + b.Y;
			v.Z = this->Z + b.Z;
			return v;
		}


		/// <summary>
		/// Negates the vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <returns>Negated vector.</returns>
		Vector3 operator -()
		{
			this->X = -this->X;
			this->Y = -this->Y;
			this->Z = -this->Z;
			return *this;
		}

		/// <summary>
		/// Tests two vectors for componentwise equivalence.
		/// </summary>
		/// <param name="a">First vector to test for equivalence.</param>
		/// <param name="b">Second vector to test for equivalence.</param>
		/// <returns>Whether the vectors were equivalent.</returns>
		bool operator ==(Vector3 b)
		{
			return this->X == b.X && this->Y == this->Y && this->Z == b.Z;
		}

		/// <summary>
		/// Tests two vectors for componentwise inequivalence.
		/// </summary>
		/// <param name="a">First vector to test for inequivalence.</param>
		/// <param name="b">Second vector to test for inequivalence.</param>
		/// <returns>Whether the vectors were inequivalent.</returns>
		bool operator !=(Vector3 b)
		{
			return this->X != b.X || this->Y != b.Y || this->Z != b.Z;
		}

		/// <summary>
		/// Indicates whether the current object is equal to another object of the same type.
		/// </summary>
		/// <returns>
		/// true if the current object is equal to the <paramref name="other"/> parameter; otherwise, false.
		/// </returns>
		/// <param name="other">An object to compare with this object.</param>
		bool Equals(Vector3 other)
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}

		/// <summary>
		/// Computes the squared distance between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distanceSquared">Squared distance between the two vectors.</param>
		static void DistanceSquared(const Vector3 &a, const Vector3 &b, Fix64 &distanceSquared)
		{
			Fix64 x = a.X - b.X;
			Fix64 y = a.Y - b.Y;
			Fix64 z = a.Z - b.Z;
			distanceSquared = x * x + y * y + z * z;
		}

		/// <summary>
		/// Computes the squared distance between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Squared distance between the two vectors.</returns>
		static Fix64 DistanceSquared(Vector3 a, Vector3 b)
		{
			Fix64 x = a.X - b.X;
			Fix64 y = a.Y - b.Y;
			Fix64 z = a.Z - b.Z;
			return x * x + y * y + z * z;
		}


		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="distance">Distance between the two vectors.</param>
		static void Distance(const Vector3 &a, const Vector3 &b, Fix64 &distance)
		{
			Fix64 x = a.X - b.X;
			Fix64 y = a.Y - b.Y;
			Fix64 z = a.Z - b.Z;
			distance = Fix64::Sqrt(x * x + y * y + z * z);
		}

		/// <summary>
		/// Computes the distance between two two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Distance between the two vectors.</returns>
		static Fix64 Distance(Vector3 a, Vector3 b)
		{
			Fix64 toReturn;
			Distance(a, b, toReturn);
			return toReturn;
		}

		/// <summary>
		/// Gets the zero vector.
		/// </summary>
		static Vector3 GetZero()
		{
			return Vector3(F64::C0, F64::C0, F64::C0);
		}

		/// <summary>
		/// Gets the up vector (0,1,0).
		/// </summary>
		static Vector3 GetUp()
		{
			return Vector3(F64::C0, F64::C1, F64::C0);
		}

		/// <summary>
		/// Gets the down vector (0,-1,0).
		/// </summary>
		static Vector3 GetDown()
		{
			return Vector3(F64::C0, -1, F64::C0);
		}

		/// <summary>
		/// Gets the right vector (1,0,0).
		/// </summary>
		static Vector3 GetRight()
		{
			return Vector3(F64::C1, F64::C0, F64::C0);
		}

		/// <summary>
		/// Gets the left vector (-1,0,0).
		/// </summary>
		static Vector3 GetLeft()
		{
			return Vector3(-1, F64::C0, F64::C0);
		}

		/// <summary>
		/// Gets the forward vector (0,0,-1).
		/// </summary>
		static Vector3 GetForward()
		{
			return Vector3(F64::C0, F64::C0, -1);
		}

		/// <summary>
		/// Gets the back vector (0,0,1).
		/// </summary>
		static Vector3 GetBackward()
		{
			return Vector3(F64::C0, F64::C0, F64::C1);
		}

		/// <summary>
		/// Gets a vector pointing along the X axis.
		/// </summary>
		static Vector3 GetUnitX()
		{
			return Vector3(F64::C1, F64::C0, F64::C0);
		}

		/// <summary>
		/// Gets a vector pointing along the Y axis.
		/// </summary>
		static Vector3 GetUnitY()
		{
			return Vector3(F64::C0, F64::C1, F64::C0);
		}

		/// <summary>
		/// Gets a vector pointing along the Z axis.
		/// </summary>
		static Vector3 GetUnitZ()
		{
			return Vector3(F64::C0, F64::C0, F64::C1);
		}

		/// <summary>
		/// Computes the cross product between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <returns>Cross product of the two vectors.</returns>
		static Vector3 Cross(Vector3 a, Vector3 b)
		{
			Vector3 toReturn;
			Vector3::Cross(a, b, toReturn);
			return toReturn;
		}

		/// <summary>
		/// Computes the cross product between two vectors.
		/// </summary>
		/// <param name="a">First vector.</param>
		/// <param name="b">Second vector.</param>
		/// <param name="result">Cross product of the two vectors.</param>
		static void Cross(const Vector3 &a, const Vector3 &b, Vector3 &result)
		{
			Fix64 resultX = a.Y * b.Z - a.Z * b.Y;
			Fix64 resultY = a.Z * b.X - a.X * b.Z;
			Fix64 resultZ = a.X * b.Y - a.Y * b.X;
			result.X = resultX;
			result.Y = resultY;
			result.Z = resultZ;
		}

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <returns>Normalized vector.</returns>
		static Vector3 Normalize(Vector3 v)
		{
			Vector3 toReturn;
			Vector3::Normalize(v, toReturn);
			return toReturn;
		}

		/// <summary>
		/// Normalizes the given vector.
		/// </summary>
		/// <param name="v">Vector to normalize.</param>
		/// <param name="result">Normalized vector.</param>
		static void Normalize(const Vector3 &v, Vector3 &result)
		{
			Fix64 inverse = F64::C1 / Fix64::Sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
			result.X = v.X * inverse;
			result.Y = v.Y * inverse;
			result.Z = v.Z * inverse;
		}

		/// <summary>
		/// Negates a vector.
		/// </summary>
		/// <param name="v">Vector to negate.</param>
		/// <param name="negated">Negated vector.</param>
		static void Negate(const Vector3 &v, Vector3 &negated)
		{
			negated.X = -v.X;
			negated.Y = -v.Y;
			negated.Z = -v.Z;
		}

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <param name="result">Vector with nonnegative elements.</param>
		static void Abs(const Vector3 &v, Vector3 &result)
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
		}

		/// <summary>
		/// Computes the absolute value of the input vector.
		/// </summary>
		/// <param name="v">Vector to take the absolute value of.</param>
		/// <returns>Vector with nonnegative elements.</returns>
		static Vector3 Abs(Vector3 v)
		{
			Vector3 result;
			Abs(v, result);
			return result;
		}

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="min">Vector containing the lesser values of each vector.</param>
		static void Min(const Vector3 &a, const Vector3 &b, Vector3 &min)
		{
			min.X = a.X < b.X ? a.X : b.X;
			min.Y = a.Y < b.Y ? a.Y : b.Y;
			min.Z = a.Z < b.Z ? a.Z : b.Z;
		}

		/// <summary>
		/// Creates a vector from the lesser values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the lesser values of each vector.</returns>
		static Vector3 Min(Vector3 a, Vector3 b)
		{
			Vector3 result;
			Min(a, b, result);
			return result;
		}


		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <param name="max">Vector containing the greater values of each vector.</param>
		static void Max(const Vector3 &a, const Vector3 &b, Vector3 &max)
		{
			max.X = a.X > b.X ? a.X : b.X;
			max.Y = a.Y > b.Y ? a.Y : b.Y;
			max.Z = a.Z > b.Z ? a.Z : b.Z;
		}

		/// <summary>
		/// Creates a vector from the greater values in each vector.
		/// </summary>
		/// <param name="a">First input vector to compare values from.</param>
		/// <param name="b">Second input vector to compare values from.</param>
		/// <returns>Vector containing the greater values of each vector.</returns>
		static Vector3 Max(Vector3 a, Vector3 b)
		{
			Vector3 result;
			Max(a, b, result);
			return result;
		}

		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector3 Lerp(Vector3 start, Vector3 end, Fix64 interpolationAmount)
		{
			Vector3 toReturn;
			Lerp(start, end, interpolationAmount, toReturn);
			return toReturn;
		}
		/// <summary>
		/// Computes an interpolated state between two vectors.
		/// </summary>
		/// <param name="start">Starting location of the interpolation.</param>
		/// <param name="end">Ending location of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end location to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Lerp(const Vector3 &start, const Vector3 &end, Fix64 interpolationAmount, Vector3 &result)
		{
			Fix64 startAmount = F64::C1 - interpolationAmount;
			result.X = start.X * startAmount + end.X * interpolationAmount;
			result.Y = start.Y * startAmount + end.Y * interpolationAmount;
			result.Z = start.Z * startAmount + end.Z * interpolationAmount;
		}

		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <param name="result">Interpolated intermediate state.</param>
		static void Hermite(const Vector3 &value1, const Vector3 &tangent1, const Vector3 &value2, const Vector3 &tangent2, Fix64 interpolationAmount, Vector3 &result)
		{
			//TO-DO
			/*Fix64 weightSquared = interpolationAmount * interpolationAmount;
			Fix64 weightCubed = interpolationAmount * weightSquared;
			Fix64 value1Blend = F64::C2 * weightCubed - F64::C3 * weightSquared + F64::C1;
			Fix64 tangent1Blend = weightCubed - F64::C2 * weightSquared + interpolationAmount;
			Fix64 value2Blend = -2 * weightCubed + F64::C3 * weightSquared;
			Fix64 tangent2Blend = weightCubed - weightSquared;
			result.X = value1.X * value1Blend + value2.X * value2Blend + tangent1.X * tangent1Blend + tangent2.X * tangent2Blend;
			result.Y = value1.Y * value1Blend + value2.Y * value2Blend + tangent1.Y * tangent1Blend + tangent2.Y * tangent2Blend;
			result.Z = value1.Z * value1Blend + value2.Z * value2Blend + tangent1.Z * tangent1Blend + tangent2.Z * tangent2Blend;*/
		}
		/// <summary>
		/// Computes an intermediate location using hermite interpolation.
		/// </summary>
		/// <param name="value1">First position.</param>
		/// <param name="tangent1">Tangent associated with the first position.</param>
		/// <param name="value2">Second position.</param>
		/// <param name="tangent2">Tangent associated with the second position.</param>
		/// <param name="interpolationAmount">Amount of the second point to use.</param>
		/// <returns>Interpolated intermediate state.</returns>
		static Vector3 Hermite(Vector3 value1, Vector3 tangent1, Vector3 value2, Vector3 tangent2, Fix64 interpolationAmount)
		{
			Vector3 toReturn;
			Hermite(value1, tangent1, value2, tangent2, interpolationAmount, toReturn);
			return toReturn;
		}
	};
}

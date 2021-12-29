#pragma once
//#ifndef QUATERNION_HEADER
//#define QUATERNION_HEADER

#include "../Common.h"
#include "../ForwardDeclarations.h"
#include "Fix64.h"

namespace Utilities
{
	/// <summary>
   /// Provides XNA-like quaternion support.
   /// </summary>
	class Quaternion
	{
	public:
		/// <summary>
		/// X component of the quaternion.
		/// </summary>
		Fix64 X;

		/// <summary>
		/// Y component of the quaternion.
		/// </summary>
		Fix64 Y;

		/// <summary>
		/// Z component of the quaternion.
		/// </summary>
		Fix64 Z;

		/// <summary>
		/// W component of the quaternion.
		/// </summary>
		Fix64 W;

		/// <summary>
		/// Quaternion default constructor.
		/// </summary>
		Quaternion();

		/// <summary>
		/// Constructs a new Quaternion.
		/// </summary>
		/// <param name="x">X component of the quaternion.</param>
		/// <param name="y">Y component of the quaternion.</param>
		/// <param name="z">Z component of the quaternion.</param>
		/// <param name="w">W component of the quaternion.</param>
		Quaternion(Fix64 x, Fix64 y, Fix64 z, Fix64 w);

		/// <summary>
		/// Adds two quaternions together.
		/// </summary>
		/// <param name="a">First quaternion to add.</param>
		/// <param name="b">Second quaternion to add.</param>
		/// <param name="result">Sum of the addition.</param>
		static void Add(const Quaternion &a, const Quaternion &b, Quaternion &result);

		/// <summary>
		/// Multiplies two quaternions.
		/// </summary>
		/// <param name="a">First quaternion to multiply.</param>
		/// <param name="b">Second quaternion to multiply.</param>
		/// <param name="result">Product of the multiplication.</param>
		static void Multiply(const Quaternion &a, const Quaternion &b, Quaternion &result);

		/// <summary>
		/// Scales a quaternion.
		/// </summary>
		/// <param name="q">Quaternion to multiply.</param>
		/// <param name="scale">Amount to multiply each component of the quaternion by.</param>
		/// <param name="result">Scaled quaternion.</param>
		static void Multiply(const Quaternion &q, Fix64 scale, Quaternion &result);

		/// <summary>
		/// Multiplies two quaternions together in opposite order.
		/// </summary>
		/// <param name="a">First quaternion to multiply.</param>
		/// <param name="b">Second quaternion to multiply.</param>
		/// <param name="result">Product of the multiplication.</param>
		static void Concatenate(const Quaternion &a, const Quaternion &b, Quaternion &result);

		/// <summary>
		/// Multiplies two quaternions together in opposite order.
		/// </summary>
		/// <param name="a">First quaternion to multiply.</param>
		/// <param name="b">Second quaternion to multiply.</param>
		/// <returns>Product of the multiplication.</returns>
		static Quaternion Concatenate(Quaternion a, Quaternion b);

		/// <summary>
		/// Quaternion representing the identity transform.
		/// </summary>
		static Quaternion GetIdentity();

		/// <summary>
		/// Ensures the quaternion has unit length.
		/// </summary>
		/// <param name="quaternion">Quaternion to normalize.</param>
		/// <returns>Normalized quaternion.</returns>
		static Quaternion Normalize(Quaternion quaternion);

		/// <summary>
		/// Ensures the quaternion has unit length.
		/// </summary>
		/// <param name="quaternion">Quaternion to normalize.</param>
		/// <param name="toReturn">Normalized quaternion.</param>
		static void Normalize(const Quaternion &quaternion, Quaternion &toReturn);

		/// <summary>
		/// Scales the quaternion such that it has unit length.
		/// </summary>
		void Normalize();

		/// <summary>
		/// Computes the squared length of the quaternion.
		/// </summary>
		/// <returns>Squared length of the quaternion.</returns>
		Fix64 LengthSquared();

		/// <summary>
		/// Computes the length of the quaternion.
		/// </summary>
		/// <returns>Length of the quaternion.</returns>
		Fix64 Length();

		/// <summary>
		/// Blends two quaternions together to get an intermediate state.
		/// </summary>
		/// <param name="start">Starting point of the interpolation.</param>
		/// <param name="end">Ending point of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end point to use.</param>
		/// <param name="result">Interpolated intermediate quaternion.</param>
		static void Slerp(Quaternion &start, Quaternion &end, Fix64 interpolationAmount, Quaternion &result);

		/// <summary>
		/// Blends two quaternions together to get an intermediate state.
		/// </summary>
		/// <param name="start">Starting point of the interpolation.</param>
		/// <param name="end">Ending point of the interpolation.</param>
		/// <param name="interpolationAmount">Amount of the end point to use.</param>
		/// <returns>Interpolated intermediate quaternion.</returns>
		static Quaternion Slerp(Quaternion start, Quaternion end, Fix64 interpolationAmount);

		/// <summary>
		/// Computes the conjugate of the quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to conjugate.</param>
		/// <param name="result">Conjugated quaternion.</param>
		static void Conjugate(const Quaternion &quaternion, Quaternion &result);

		/// <summary>
		/// Computes the conjugate of the quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to conjugate.</param>
		/// <returns>Conjugated quaternion.</returns>
		static Quaternion Conjugate(Quaternion quaternion);

		/// <summary>
		/// Computes the inverse of the quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to invert.</param>
		/// <param name="result">Result of the inversion.</param>
		static void Inverse(const Quaternion &quaternion, Quaternion &result);

		/// <summary>
		/// Computes the inverse of the quaternion.
		/// </summary>
		/// <param name="quaternion">Quaternion to invert.</param>
		/// <returns>Result of the inversion.</returns>
		static Quaternion Inverse(Quaternion quaternion);

		/// <summary>
		/// Tests components for equality.
		/// </summary>
		/// <param name="a">First quaternion to test for equivalence.</param>
		/// <param name="b">Second quaternion to test for equivalence.</param>
		/// <returns>Whether or not the quaternions' components were equal.</returns>
		bool operator ==(Quaternion b) const;

		/// <summary>
		/// Tests components for inequality.
		/// </summary>
		/// <param name="a">First quaternion to test for equivalence.</param>
		/// <param name="b">Second quaternion to test for equivalence.</param>
		/// <returns>Whether the quaternions' components were not equal.</returns>
		bool operator !=(Quaternion b) const;

		/// <summary>
		/// Negates the components of a quaternion.
		/// </summary>
		/// <param name="a">Quaternion to negate.</param>
		/// <param name="b">Negated result.</param>
		static void Negate(const Quaternion &a, Quaternion &b);

		/// <summary>
		/// Negates the components of a quaternion.
		/// </summary>
		/// <param name="q">Quaternion to negate.</param>
		/// <returns>Negated result.</returns>
		static Quaternion Negate(Quaternion q);

		/// <summary>
		/// Negates the components of a quaternion.
		/// </summary>
		/// <param name="q">Quaternion to negate.</param>
		/// <returns>Negated result.</returns>
		Quaternion operator -();

		/// <summary>
		/// Indicates whether the current object is equal to another object of the same type.
		/// </summary>
		/// <returns>
		/// true if the current object is equal to the <paramref name="other"/> parameter; otherwise, false.
		/// </returns>
		/// <param name="other">An object to compare with this object.</param>
		bool Equals(Quaternion other);

		/// <summary>
		/// Transforms the vector using a quaternion.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="rotation">Rotation to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void Transform(const Vector3 &v, const Quaternion &rotation, Vector3 &result);

		/// <summary>
		/// Transforms the vector using a quaternion.
		/// </summary>
		/// <param name="v">Vector to transform.</param>
		/// <param name="rotation">Rotation to apply to the vector.</param>
		/// <returns>Transformed vector.</returns>
		static Vector3 Transform(Vector3 v, Quaternion rotation);

		/// <summary>
		/// Transforms a vector using a quaternion. Specialized for x,0,0 vectors.
		/// </summary>
		/// <param name="x">X component of the vector to transform.</param>
		/// <param name="rotation">Rotation to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformX(Fix64 x, const Quaternion &rotation, Vector3 result);

		/// <summary>
		/// Transforms a vector using a quaternion. Specialized for 0,y,0 vectors.
		/// </summary>
		/// <param name="y">Y component of the vector to transform.</param>
		/// <param name="rotation">Rotation to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformY(Fix64 y, const Quaternion &rotation, Vector3 &result);

		/// <summary>
		/// Transforms a vector using a quaternion. Specialized for 0,0,z vectors.
		/// </summary>
		/// <param name="z">Z component of the vector to transform.</param>
		/// <param name="rotation">Rotation to apply to the vector.</param>
		/// <param name="result">Transformed vector.</param>
		static void TransformZ(Fix64 z, const Quaternion &rotation, Vector3 &result);

		/// <summary>
		/// Multiplies two quaternions.
		/// </summary>
		/// <param name="a">First quaternion to multiply.</param>
		/// <param name="b">Second quaternion to multiply.</param>
		/// <returns>Product of the multiplication.</returns>
		Quaternion operator *(Quaternion b) const;

		/// <summary>
		/// Creates a quaternion from an axis and angle.
		/// </summary>
		/// <param name="axis">Axis of rotation.</param>
		/// <param name="angle">Angle to rotate around the axis.</param>
		/// <returns>Quaternion representing the axis and angle rotation.</returns>
		static Quaternion CreateFromAxisAngle(Vector3 axis, Fix64 angle);

		/// <summary>
		/// Creates a quaternion from an axis and angle.
		/// </summary>
		/// <param name="axis">Axis of rotation.</param>
		/// <param name="angle">Angle to rotate around the axis.</param>
		/// <param name="q">Quaternion representing the axis and angle rotation.</param>
		static void CreateFromAxisAngle(const Vector3 &axis, Fix64 angle, Quaternion &q);

		/// <summary>
		/// Constructs a quaternion from yaw, pitch, and roll.
		/// </summary>
		/// <param name="yaw">Yaw of the rotation.</param>
		/// <param name="pitch">Pitch of the rotation.</param>
		/// <param name="roll">Roll of the rotation.</param>
		/// <returns>Quaternion representing the yaw, pitch, and roll.</returns>
		static Quaternion CreateFromYawPitchRoll(Fix64 yaw, Fix64 pitch, Fix64 roll);

		/// <summary>
		/// Constructs a quaternion from yaw, pitch, and roll.
		/// </summary>
		/// <param name="yaw">Yaw of the rotation.</param>
		/// <param name="pitch">Pitch of the rotation.</param>
		/// <param name="roll">Roll of the rotation.</param>
		/// <param name="q">Quaternion representing the yaw, pitch, and roll.</param>
		static void CreateFromYawPitchRoll(Fix64 yaw, Fix64 pitch, Fix64 roll, Quaternion &q);

		/// <summary>
		/// Computes the angle change represented by a normalized quaternion.
		/// </summary>
		/// <param name="q">Quaternion to be converted.</param>
		/// <returns>Angle around the axis represented by the quaternion.</returns>
		static Fix64 GetAngleFromQuaternion(const Quaternion &q);

		//The following two functions are highly similar, but it's a bit of a brain teaser to phrase one in terms of the other.
		//Providing both simplifies things.
		/// <summary>
		/// Computes the rotation from the start orientation to the end orientation such that end = Quaternion.Concatenate(start, relative).
		/// </summary>
		/// <param name="start">Starting orientation.</param>
		/// <param name="end">Ending orientation.</param>
		/// <param name="relative">Relative rotation from the start to the end orientation.</param>
		static void GetRelativeRotation(const Quaternion &start, const Quaternion &end, Quaternion &relative);

		/// <summary>
		/// Transforms the rotation into the local space of the target basis such that rotation = Quaternion.Concatenate(localRotation, targetBasis)
		/// </summary>
		/// <param name="rotation">Rotation in the original frame of reference.</param>
		/// <param name="targetBasis">Basis in the original frame of reference to transform the rotation into.</param>
		/// <param name="localRotation">Rotation in the local space of the target basis.</param>
		static void GetLocalRotation(const Quaternion &rotation, const Quaternion &targetBasis, Quaternion &localRotation);

		/// <summary>
		/// Gets a string representation of the quaternion.
		/// </summary>
		/// <returns>String representing the quaternion.</returns>
		string ToString();
	};
}

//#endif //QUATERNION_HEADER
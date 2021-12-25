#include "common.h"
#include "F64.h"

namespace BEPUutilities
{
    /// <summary>
    /// Provides XNA-like 2D vector math.
    /// </summary>
    struct Vector2
    {
        /// <summary>
        /// X component of the vector.
        /// </summary>
	public:
		Fix64 X;
        /// <summary>
        /// Y component of the vector.
        /// </summary>
        Fix64 Y;

		/// <summary>
		/// Constructs a new two dimensional vector.
		/// </summary>
		Vector2()
		{
			this->X = 0;
			this->Y = 0;
		}

        /// <summary>
        /// Constructs a new two dimensional vector.
        /// </summary>
        /// <param name="x">X component of the vector.</param>
        /// <param name="y">Y component of the vector.</param>
        Vector2(Fix64 x, Fix64 y)
        {
            this->X = x;
            this->Y = y;
        }

        /// <summary>
        /// Computes the squared length of the vector.
        /// </summary>
        /// <returns>Squared length of the vector.</returns>
        Fix64 LengthSquared()
        {
            return X * X + Y * Y;
        }

        /// <summary>
        /// Computes the length of the vector.
        /// </summary>
        /// <returns>Length of the vector.</returns>
        Fix64 Length()
        {
            return Fix64::Sqrt(X * X + Y * Y);
        }

        /// <summary>
        /// Gets a string representation of the vector.
        /// </summary>
        /// <returns>String representing the vector.</returns>
        string ToString()
        {
            return "{" + (string) X + ", " + (string) Y + "}";
        }

        /// <summary>
        /// Adds two vectors together.
        /// </summary>
        /// <param name="a">First vector to add.</param>
        /// <param name="b">Second vector to add.</param>
        /// <param name="sum">Sum of the two vectors.</param>
        static void Add(const Vector2 &a, const Vector2 &b, Vector2 &sum)
        {
            sum.X = a.X + b.X;
            sum.Y = a.Y + b.Y;
        }

        /// <summary>
        /// Subtracts two vectors.
        /// </summary>
        /// <param name="a">Vector to subtract from.</param>
        /// <param name="b">Vector to subtract from the first vector.</param>
        /// <param name="difference">Result of the subtraction.</param>
        static void Subtract(const Vector2 &a, const Vector2 &b, Vector2 &difference)
        {
            difference.X = a.X - b.X;
            difference.Y = a.Y - b.Y;
        }

        /// <summary>
        /// Scales a vector.
        /// </summary>
        /// <param name="v">Vector to scale.</param>
        /// <param name="scale">Amount to scale.</param>
        /// <param name="result">Scaled vector.</param>
        static void Multiply(const Vector2 &v, Fix64 scale, Vector2 &result)
        {
            result.X = v.X * scale;
            result.Y = v.Y * scale;
        }

        /// <summary>
        /// Multiplies two vectors on a per-component basis.
        /// </summary>
        /// <param name="a">First vector to multiply.</param>
        /// <param name="b">Second vector to multiply.</param>
        /// <param name="result">Result of the componentwise multiplication.</param>
        static void Multiply(const Vector2 &a, const Vector2 &b, Vector2 &result)
        {
            result.X = a.X * b.X;
            result.Y = a.Y * b.Y;
        }

        /// <summary>
        /// Divides a vector's components by some amount.
        /// </summary>
        /// <param name="v">Vector to divide.</param>
        /// <param name="divisor">Value to divide the vector's components.</param>
        /// <param name="result">Result of the division.</param>
        static void Divide(const Vector2 &v, Fix64 divisor, Vector2 &result)
        {
            Fix64 inverse = F64::C1 / divisor;
            result.X = v.X * inverse;
            result.Y = v.Y * inverse;
        }

        /// <summary>
        /// Computes the dot product of the two vectors.
        /// </summary>
        /// <param name="a">First vector of the dot product.</param>
        /// <param name="b">Second vector of the dot product.</param>
        /// <param name="dot">Dot product of the two vectors.</param>
        static void Dot(const Vector2 &a, const Vector2 &b, Fix64 &dot)
        {
            dot = a.X * b.X + a.Y * b.Y;
        }

        /// <summary>
        /// Computes the dot product of the two vectors.
        /// </summary>
        /// <param name="a">First vector of the dot product.</param>
        /// <param name="b">Second vector of the dot product.</param>
        /// <returns>Dot product of the two vectors.</returns>
        static Fix64 Dot(Vector2 a, Vector2 b)
        {
            return a.X * b.X + a.Y * b.Y;
        }

        /// <summary>
        /// Gets the zero vector.
        /// </summary>
        static Vector2 GetZero()
        {
			return Vector2();
        }

        /// <summary>
        /// Gets a vector pointing along the X axis.
        /// </summary>
        static Vector2 GetUnitX()
        {
			Vector2 temp;
			temp.X = F64::C1;
			return temp;
        }

        /// <summary>
        /// Gets a vector pointing along the Y axis.
        /// </summary>
        static Vector2 GetUnitY()
        {
			Vector2 temp;
			temp.Y = F64::C1;
			return temp;
        }


        /// <summary>
        /// Normalizes the vector.
        /// </summary>
        /// <param name="v">Vector to normalize.</param>
        /// <returns>Normalized copy of the vector.</returns>
        static Vector2 Normalize(Vector2 v)
        {
            Vector2 toReturn;
            Vector2::Normalize(v, toReturn);
            return toReturn;
        }

        /// <summary>
        /// Normalizes the vector.
        /// </summary>
        /// <param name="v">Vector to normalize.</param>
        /// <param name="result">Normalized vector.</param>
        static void Normalize(const Vector2 &v, Vector2 &result)
        {
            Fix64 inverse = F64::C1 / Fix64::Sqrt(v.X * v.X + v.Y * v.Y);
            result.X = v.X * inverse;
            result.Y = v.Y * inverse;
        }

        /// <summary>
        /// Negates the vector.
        /// </summary>
        /// <param name="v">Vector to negate.</param>
        /// <param name="negated">Negated version of the vector.</param>
        static void Negate(const Vector2 &v, Vector2 &negated)
        {
            negated.X = -v.X;
            negated.Y = -v.Y;
        }

        /// <summary>
        /// Computes the absolute value of the input vector.
        /// </summary>
        /// <param name="v">Vector to take the absolute value of.</param>
        /// <param name="result">Vector with nonnegative elements.</param>
        static void Abs(const Vector2 &v, Vector2 &result)
        {
            if (v.X < F64::C0)
                result.X = -v.X;
            else
                result.X = v.X;
            if (v.Y < F64::C0)
                result.Y = -v.Y;
            else
                result.Y = v.Y;
        }

        /// <summary>
        /// Computes the absolute value of the input vector.
        /// </summary>
        /// <param name="v">Vector to take the absolute value of.</param>
        /// <returns>Vector with nonnegative elements.</returns>
        static Vector2 Abs(const Vector2 &v)
        {
            Vector2 result;
			Vector2::Abs(v, result);
            return result;
        }

        /// <summary>
        /// Creates a vector from the lesser values in each vector.
        /// </summary>
        /// <param name="a">First input vector to compare values from.</param>
        /// <param name="b">Second input vector to compare values from.</param>
        /// <param name="min">Vector containing the lesser values of each vector.</param>
        static void Min(const Vector2 &a, const Vector2 &b, Vector2 &min)
        {
            min.X = a.X < b.X ? a.X : b.X;
            min.Y = a.Y < b.Y ? a.Y : b.Y;
        }

        /// <summary>
        /// Creates a vector from the lesser values in each vector.
        /// </summary>
        /// <param name="a">First input vector to compare values from.</param>
        /// <param name="b">Second input vector to compare values from.</param>
        /// <returns>Vector containing the lesser values of each vector.</returns>
        static Vector2 Min(const Vector2 &a, const Vector2 &b)
        {
            Vector2 result;
			Vector2::Min(a, b, result);
            return result;
        }


        /// <summary>
        /// Creates a vector from the greater values in each vector.
        /// </summary>
        /// <param name="a">First input vector to compare values from.</param>
        /// <param name="b">Second input vector to compare values from.</param>
        /// <param name="max">Vector containing the greater values of each vector.</param>
        static void Max(const Vector2 &a, const Vector2 &b, Vector2 &max)
        {
            max.X = a.X > b.X ? a.X : b.X;
            max.Y = a.Y > b.Y ? a.Y : b.Y;
        }

        /// <summary>
        /// Creates a vector from the greater values in each vector.
        /// </summary>
        /// <param name="a">First input vector to compare values from.</param>
        /// <param name="b">Second input vector to compare values from.</param>
        /// <returns>Vector containing the greater values of each vector.</returns>
        static Vector2 Max(const Vector2 &a, const Vector2 &b)
        {
            Vector2 result;
            Vector2::Max(a, b, result);
            return result;
        }

        /// <summary>
        /// Normalizes the vector.
        /// </summary>
        void Normalize()
        {
            Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y);
            X *= inverse;
            Y *= inverse;
        }

        /// <summary>
        /// Scales a vector.
        /// </summary>
        /// <param name="v">Vector to scale.</param>
        /// <param name="f">Amount to scale.</param>
        /// <returns>Scaled vector.</returns>
        Vector2 &operator *(const Fix64 &f)
        {
			Vector2 toReturn(*this);
            toReturn.X *= f;
			toReturn.Y *= f;
            return toReturn;
        }
       
        /// <summary>
        /// Multiplies two vectors on a per-component basis.
        /// </summary>
        /// <param name="a">First vector to multiply.</param>
        /// <param name="b">Second vector to multiply.</param>
        /// <returns>Result of the componentwise multiplication.</returns>
        Vector2 &operator *(const Vector2 &b)
        {
			Vector2 toReturn;
			Vector2::Multiply(*this, b, toReturn);
            return toReturn;
        }

        /// <summary>
        /// Divides a vector.
        /// </summary>
        /// <param name="v">Vector to divide.</param>
        /// <param name="f">Amount to divide.</param>
        /// <returns>Divided vector.</returns>
        Vector2& operator /(Fix64 f)
        {
            Vector2 toReturn;
            f = F64::C1 / f;
            toReturn.X = this->X * f;
            toReturn.Y = this->Y * f;
            return toReturn;
        }

        /// <summary>
        /// Subtracts two vectors.
        /// </summary>
        /// <param name="a">Vector to be subtracted from.</param>
        /// <param name="b">Vector to subtract from the first vector.</param>
        /// <returns>Resulting difference.</returns>
        Vector2 &operator -(const Vector2 &a)
        {
            Vector2 toReturn(*this);
            toReturn.X -= a.X;
            toReturn.Y -= a.Y;
            return toReturn;
        }

        /// <summary>
        /// Adds two vectors.
        /// </summary>
        /// <param name="a">First vector to add.</param>
        /// <param name="b">Second vector to add.</param>
        /// <returns>Sum of the addition.</returns>
        Vector2 &operator +(const Vector2 &a)
        {
			Vector2 toReturn(*this);
			toReturn.X += a.X;
			toReturn.Y += a.Y;
			return toReturn;
        }

        /// <summary>
        /// Negates the vector.
        /// </summary>
        /// <param name="v">Vector to negate.</param>
        /// <returns>Negated vector.</returns>
        Vector2 &operator -()
        {
			Vector2 toReturn(*this);
			toReturn.X = -toReturn.X;
			toReturn.Y = -toReturn.Y;
			return toReturn;
        }

        /// <summary>
        /// Tests two vectors for componentwise equivalence.
        /// </summary>
        /// <param name="a">First vector to test for equivalence.</param>
        /// <param name="b">Second vector to test for equivalence.</param>
        /// <returns>Whether the vectors were equivalent.</returns>
        bool operator ==(const Vector2 &a)
        {
            return a.X == this->X && a.Y == this->Y;
        }
        /// <summary>
        /// Tests two vectors for componentwise inequivalence.
        /// </summary>
        /// <param name="a">First vector to test for inequivalence.</param>
        /// <param name="b">Second vector to test for inequivalence.</param>
        /// <returns>Whether the vectors were inequivalent.</returns>
        bool operator !=(const Vector2 &a)
        {
            return a.X != this->X || a.Y != this->Y;
        }

        /// <summary>
        /// Indicates whether the current object is equal to another object of the same type.
        /// </summary>
        /// <returns>
        /// true if the current object is equal to the <paramref name="other"/> parameter; otherwise, false.
        /// </returns>
        /// <param name="other">An object to compare with this object.</param>
        bool Equals(const Vector2 &other)
        {
            return X == other.X && Y == other.Y;
        }

	};
}

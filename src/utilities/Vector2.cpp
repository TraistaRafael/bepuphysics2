#pragma once

#include "Vector2.h"

namespace BepuUtilities
{
  
	Vector2::Vector2()
	{
		this->X = 0;
		this->Y = 0;
	}

	Vector2::Vector2(Fix64 x, Fix64 y)
    {
        this->X = x;
        this->Y = y;
    }

    Fix64 Vector2::LengthSquared()
    {
        return X * X + Y * Y;
    }

    Fix64 Vector2::Length()
    {
        return Fix64::Sqrt(X * X + Y * Y);
    }

    string Vector2::ToString()
    {
        return "{" + (string) X + ", " + (string) Y + "}";
    }

    void Vector2::Add(const Vector2 &a, const Vector2 &b, Vector2 &sum)
    {
        sum.X = a.X + b.X;
        sum.Y = a.Y + b.Y;
    }

    void Vector2::Subtract(const Vector2 &a, const Vector2 &b, Vector2 &difference)
    {
        difference.X = a.X - b.X;
        difference.Y = a.Y - b.Y;
    }

    void Vector2::Multiply(const Vector2 &v, Fix64 scale, Vector2 &result)
    {
        result.X = v.X * scale;
        result.Y = v.Y * scale;
    }

    void Vector2::Multiply(const Vector2 &a, const Vector2 &b, Vector2 &result)
    {
        result.X = a.X * b.X;
        result.Y = a.Y * b.Y;
    }

    void Vector2::Divide(const Vector2 &v, Fix64 divisor, Vector2 &result)
    {
        Fix64 inverse = F64::C1 / divisor;
        result.X = v.X * inverse;
        result.Y = v.Y * inverse;
    }

    void Vector2::Dot(const Vector2 &a, const Vector2 &b, Fix64 &dot)
    {
        dot = a.X * b.X + a.Y * b.Y;
    }

    Fix64 Vector2::Dot(Vector2 a, Vector2 b)
    {
        return a.X * b.X + a.Y * b.Y;
    }

    Vector2 Vector2::GetZero()
    {
		return Vector2();
    }

    Vector2 Vector2::GetUnitX()
    {
		Vector2 temp;
		temp.X = F64::C1;
		return temp;
    }

    Vector2 Vector2::GetUnitY()
    {
		Vector2 temp;
		temp.Y = F64::C1;
		return temp;
    }

    Vector2 Vector2::Normalize(Vector2 v)
    {
        Vector2 toReturn;
        Vector2::Normalize(v, toReturn);
        return toReturn;
    }

    void Vector2::Normalize(const Vector2 &v, Vector2 &result)
    {
        Fix64 inverse = F64::C1 / Fix64::Sqrt(v.X * v.X + v.Y * v.Y);
        result.X = v.X * inverse;
        result.Y = v.Y * inverse;
    }

    void Vector2::Negate(const Vector2 &v, Vector2 &negated)
    {
        negated.X = -v.X;
        negated.Y = -v.Y;
    }

    void Vector2::Abs(const Vector2 &v, Vector2 &result)
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

    Vector2 Vector2::Abs(const Vector2 &v)
    {
        Vector2 result;
		Vector2::Abs(v, result);
        return result;
    }

    void Vector2::Min(const Vector2 &a, const Vector2 &b, Vector2 &min)
    {
        min.X = a.X < b.X ? a.X : b.X;
        min.Y = a.Y < b.Y ? a.Y : b.Y;
    }

    Vector2 Vector2::Min(const Vector2 &a, const Vector2 &b)
    {
        Vector2 result;
		Vector2::Min(a, b, result);
        return result;
    }

    void Vector2::Max(const Vector2 &a, const Vector2 &b, Vector2 &max)
    {
        max.X = a.X > b.X ? a.X : b.X;
        max.Y = a.Y > b.Y ? a.Y : b.Y;
    }

    Vector2 Vector2::Max(const Vector2 &a, const Vector2 &b)
    {
        Vector2 result;
        Vector2::Max(a, b, result);
        return result;
    }

    void Vector2::Normalize()
    {
        Fix64 inverse = F64::C1 / Fix64::Sqrt(X * X + Y * Y);
        X *= inverse;
        Y *= inverse;
    }

    Vector2 &Vector2::operator *(const Fix64 &f)
    {
		Vector2 toReturn(*this);
        toReturn.X *= f;
		toReturn.Y *= f;
        return toReturn;
    }
   
    Vector2 &Vector2::operator *(const Vector2 &b)
    {
		Vector2 toReturn;
		Vector2::Multiply(*this, b, toReturn);
        return toReturn;
    }

    Vector2 &Vector2::operator /(Fix64 f)
    {
        Vector2 toReturn;
        f = F64::C1 / f;
        toReturn.X = this->X * f;
        toReturn.Y = this->Y * f;
        return toReturn;
    }

    Vector2 &Vector2::operator -(const Vector2 &a)
    {
        Vector2 toReturn(*this);
        toReturn.X -= a.X;
        toReturn.Y -= a.Y;
        return toReturn;
    }

    Vector2 &Vector2::operator +(const Vector2 &a)
    {
		Vector2 toReturn(*this);
		toReturn.X += a.X;
		toReturn.Y += a.Y;
		return toReturn;
    }

    Vector2 &Vector2::operator -()
    {
		Vector2 toReturn(*this);
		toReturn.X = -toReturn.X;
		toReturn.Y = -toReturn.Y;
		return toReturn;
    }

    bool Vector2::operator ==(const Vector2 &a)
    {
        return a.X == this->X && a.Y == this->Y;
    }
   
    bool Vector2::operator !=(const Vector2 &a)
    {
        return a.X != this->X || a.Y != this->Y;
    }

    bool Vector2::Equals(const Vector2 &other)
    {
        return X == other.X && Y == other.Y;
    }
}

#pragma once

#include <string>
#include <memory>
#include <vector>

#define R128_IMPLEMENTATION
#include "../r128/r128.h"

using namespace std;

/**
* Wrapper for R128 struct
* This class actaully represents a (64.64) signed fixed-point, but it's named Fix64 to match existing bepuphysics naming.
*/ 
class Fix64
{
public:
	R128 raw;

public:
	Fix64();
	Fix64(double);
	Fix64(int);
	Fix64(R128_S64);
	Fix64(R128_U64 low, R128_U64 high);
	Fix64(const R128 &v);

	operator double() const;
	operator R128_S64() const;
	operator int() const;
	operator bool() const;
	operator string() const;

	Fix64 operator+(const Fix64 &rhs) const;
	Fix64 operator-(const Fix64 &rhs) const;
	Fix64 operator/(const Fix64 &rhs) const;
	Fix64 operator*(const Fix64 &rhs) const;
	
	bool operator<(const Fix64 &rhs) const;
	bool operator>(const Fix64 &rhs) const;
	bool operator==(const Fix64 &rhs) const;
	bool operator!=(const Fix64 &rhs) const;

	bool operator+() const;
	Fix64 operator~() const;
	Fix64 operator-() const;
	Fix64 &operator|=(const Fix64 &rhs);
	Fix64 &operator&=(const Fix64 &rhs);
	Fix64 &operator^=(const Fix64 &rhs);
	Fix64 &operator+=(const Fix64 &rhs);
	Fix64 &operator-=(const Fix64 &rhs);
	Fix64 &operator*=(const Fix64 &rhs);
	Fix64 &operator/=(const Fix64 &rhs);
	Fix64 &operator%=(const Fix64 &rhs);
	Fix64 &operator<<=(int amount);
	Fix64 &operator>>=(int amount);

	static Fix64 &Sqrt(const Fix64 &rhs);
};


Fix64::Fix64()
{
	raw = R128();
}

Fix64::Fix64(double v)
{
	raw = R128(v);
}

Fix64::Fix64(int v)
{
	raw = R128(v);
}

Fix64::Fix64(R128_S64 v)
{
	raw = R128(v);
}

Fix64::Fix64(R128_U64 low, R128_U64 high)
{
	raw = R128(low, high);
}

Fix64::Fix64(const R128 &v)
{
	raw = v;
}

Fix64::operator double() const
{
	return (double) raw;
}

Fix64::operator R128_S64() const
{
	return (R128_S64) raw;
}

Fix64::operator int() const
{
	return (int) raw;
}

Fix64::operator bool() const
{
	return (bool) raw;
}

Fix64::operator string() const
{
	double temp = (double) raw;
	return std::to_string(temp);
}

Fix64 Fix64::operator+(const Fix64 &rhs) const
{
	R128 temp = raw + rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator-(const Fix64 &rhs) const 
{
	R128 temp = raw - rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator/(const Fix64 &rhs) const
{
	R128 temp = raw / rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator*(const Fix64 &rhs) const
{
	R128 temp = raw * rhs.raw;
	return Fix64(temp);
}

bool Fix64::operator<(const Fix64 &rhs) const
{
	return raw < rhs.raw;
}

bool Fix64::operator>(const Fix64 &rhs) const
{
	return raw > rhs.raw;
}

bool Fix64::operator==(const Fix64 &rhs) const
{
	return raw == rhs.raw;
}

bool Fix64::operator!=(const Fix64 &rhs) const
{
	return raw != rhs.raw;
}

Fix64 &Fix64::operator+=(const Fix64 &rhs)
{
	raw += rhs.raw;
	return *this;
}

Fix64 &Fix64::Sqrt(const Fix64 &rhs)
{
	Fix64 dest;
	r128Sqrt(&dest.raw, &rhs.raw);
	return dest;
}
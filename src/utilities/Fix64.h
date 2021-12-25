#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../fpm/fixed.hpp"
#include "../fpm/ios.hpp"
#include "../fpm/math.hpp"

using namespace std;
using namespace fpm;

#define Fix64_S64 long long
#define Fix64_U64 unsigned long long

/**
* Wrapper for R128 struct
* This class actaully represents a (64.64) signed fixed-point, but it's named Fix64 to match existing bepuphysics naming.
*/ 
class Fix64
{
public:
	fixed_16_16 raw;

public:
	Fix64();
	Fix64(double);
	Fix64(int);
	Fix64(Fix64_S64);
	//Fix64(Fix64_U64 low, Fix64_U64 high);
	Fix64(const fixed_16_16 &v);

	operator double() const;
	operator Fix64_S64() const;
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
	raw = fixed_16_16();
}

Fix64::Fix64(double v)
{
	raw = fixed_16_16(v);
}

Fix64::Fix64(int v)
{
	raw = fixed_16_16(v);
}

Fix64::Fix64(Fix64_S64 v)
{
	raw = fixed_16_16(v);
}

//Fix64::Fix64(Fix64_U64 low, Fix64_U64 high)
//{
//	raw = fixed_16_16(low, high);
//}

Fix64::Fix64(const fixed_16_16 &v)
{
	raw = v;
}

Fix64::operator double() const
{
	return (double) raw;
}

Fix64::operator Fix64_S64() const
{
	return (Fix64_S64) raw;
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
	fixed_16_16 temp = raw + rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator-(const Fix64 &rhs) const 
{
	fixed_16_16 temp = raw - rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator/(const Fix64 &rhs) const
{
	fixed_16_16 temp = raw / rhs.raw;
	return Fix64(temp);
}

Fix64 Fix64::operator*(const Fix64 &rhs) const
{
	fixed_16_16 temp = raw * rhs.raw;
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
	return Fix64(fpm::sqrt(rhs.raw));
}
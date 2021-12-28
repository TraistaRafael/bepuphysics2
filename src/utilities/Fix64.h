#ifndef FIX64_HEADER
#define FIX64_HEADER

#include <string>
#include <memory>
#include <vector>
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
	bool operator<=(const Fix64 &rhs) const;
	bool operator>=(const Fix64 &rhs) const;
	bool operator==(const Fix64 &rhs) const;
	bool operator!=(const Fix64 &rhs) const;

	bool operator!() const;
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

#endif FIX64_HEADER
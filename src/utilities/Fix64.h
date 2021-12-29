#pragma once
//#ifndef FIX64_HEADER
//#define FIX64_HEADER

#include <string>
#include <memory>
#include <vector>
#include "../r128/r128.h"

using namespace std;

/**
* Wrapper for R128 struct
* This class actaully represents a (64.64) signed fixed-point, but it's named Fix64 to match existing bepuphysics naming.
*/

namespace Utilities
{
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
		Fix64 operator|=(const Fix64 &rhs);
		Fix64 &operator&=(const Fix64 &rhs);
		Fix64 &operator^=(const Fix64 &rhs);
		Fix64 &operator+=(const Fix64 &rhs);
		Fix64 &operator-=(const Fix64 &rhs);
		Fix64 &operator*=(const Fix64 &rhs);
		Fix64 &operator/=(const Fix64 &rhs);
		Fix64 &operator%=(const Fix64 &rhs);
		Fix64 &operator<<=(int amount);
		Fix64 &operator>>=(int amount);

		static Fix64 Sqrt(const Fix64 &rhs);
		static Fix64 Abs(const Fix64 &rhs);

		static Fix64 Sin(const Fix64 &rhs);
		static Fix64 Cos(const Fix64 &rhs);
		static Fix64 Tan(const Fix64 &rhs);
		static Fix64 Ctan(const Fix64 &rhs);
		static Fix64 Acos(const Fix64 &rhs);
		static Fix64 Asin(const Fix64 &rhs);
		static Fix64 Atan(const Fix64 &rhs);
		static Fix64 Actan(const Fix64 &rhs);

		static Fix64 One;
		static Fix64 Zero;
	};

	class F64
	{
	public:
		static const Fix64 C0;
		static const Fix64 C1;
		static const Fix64 C180;
		static const Fix64 C2;
		static const Fix64 C3;
		static const Fix64 C5;
		static const Fix64 C6;
		static const Fix64 C16;
		static const Fix64 C24;
		static const Fix64 C50;
		static const Fix64 C60;
		static const Fix64 C120;
		static const Fix64 C0p001;
		static const Fix64 C0p5;
		static const Fix64 C0p25;
		static const Fix64 C1em09;
		static const Fix64 C1em9;
		static const Fix64 Cm1em9;
		static const Fix64 C1em14;
		static const Fix64 C0p1;
		static const Fix64 OneThird;
		static const Fix64 C0p75;
		static const Fix64 C0p15;
		static const Fix64 C0p3;
		static const Fix64 C0p0625;
		static const Fix64 C0p99;
		static const Fix64 C0p9;
		static const Fix64 C1p5;
		static const Fix64 C1p1;
		static const Fix64 OneEighth;
		static const Fix64 FourThirds;
		static const Fix64 TwoFifths;
		static const Fix64 C0p2;
		static const Fix64 C0p8;
		static const Fix64 C0p01;
		static const Fix64 C1em7;
		static const Fix64 C1em5;
		static const Fix64 C1em4;
		static const Fix64 C1em10;
		static const Fix64 Cm0p25;
		static const Fix64 Cm0p9999;
		static const Fix64 C1m1em12;
		static const Fix64 GoldenRatio;
		static const Fix64 OneTwelfth;
		static const Fix64 C0p0833333333;
		static const Fix64 C90000;
		static const Fix64 C600000;
	};
}
//#endif FIX64_HEADER
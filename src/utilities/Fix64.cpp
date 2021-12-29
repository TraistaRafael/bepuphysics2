#include "Fix64.h"

namespace Utilities
{
	Fix64 Fix64::One = Fix64(1);
	Fix64 Fix64::Zero = Fix64(0);

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
		return (double)raw;
	}

	Fix64::operator R128_S64() const
	{
		return (R128_S64)raw;
	}

	Fix64::operator int() const
	{
		return (int)raw;
	}

	Fix64::operator bool() const
	{
		return (bool)raw;
	}

	Fix64::operator string() const
	{
		double temp = (double)raw;
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

	bool Fix64::operator<=(const Fix64 &rhs) const
	{
		return raw <= rhs.raw;
	}

	bool Fix64::operator>=(const Fix64 &rhs) const
	{
		return raw >= rhs.raw;
	}

	bool Fix64::operator==(const Fix64 &rhs) const
	{
		return raw == rhs.raw;
	}

	bool Fix64::operator!=(const Fix64 &rhs) const
	{
		return raw != rhs.raw;
	}

	bool Fix64::operator!() const
	{
		return !raw;
	}

	Fix64 Fix64::operator~() const
	{
		return Fix64(~raw);
	}

	Fix64 Fix64::operator-() const
	{
		return Fix64(-raw);
	}

	Fix64 Fix64::operator|=(const Fix64 &rhs)
	{
		return Fix64(raw |= rhs.raw);
	}


	Fix64 &Fix64::operator&=(const Fix64 &rhs)
	{
		raw |= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator^=(const Fix64 &rhs)
	{
		raw ^= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator+=(const Fix64 &rhs)
	{
		raw &= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator-=(const Fix64 &rhs)
	{
		raw -= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator*=(const Fix64 &rhs)
	{
		raw *= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator/=(const Fix64 &rhs)
	{
		raw /= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator%=(const Fix64 &rhs)
	{
		raw %= rhs.raw;
		return *this;
	}


	Fix64 &Fix64::operator<<=(int amount)
	{
		raw <<= amount;
		return *this;
	}

	Fix64 &Fix64::operator>>=(int amount)
	{
		raw >>= amount;
		return *this;
	}

	Fix64 Fix64::Sqrt(const Fix64 &rhs)
	{
		Fix64 dest;
		r128Sqrt(&dest.raw, &rhs.raw);
		return dest;
	}

	Fix64 Fix64::Abs(const Fix64 &rhs)
	{
		Fix64 dest;
		r128Abs(&dest.raw, &rhs.raw);
		return dest;
	}

	Fix64 Fix64::Sin(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Cos(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Tan(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Ctan(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Acos(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Asin(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Atan(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	Fix64 Fix64::Actan(const Fix64 &rhs)
	{
		//TO-DO implement this.
		return Fix64(rhs);
	}

	const Fix64 F64::C0 = (Fix64)0;
	const Fix64 F64::C1 = (Fix64) 1;
	const Fix64 F64::C180 = (Fix64)180;
	const Fix64 F64::C2 = (Fix64)2;
	const Fix64 F64::C3 = (Fix64)3;
	const Fix64 F64::C5 = (Fix64)5;
	const Fix64 F64::C6 = (Fix64)6;
	const Fix64 F64::C16 = (Fix64)16;
	const Fix64 F64::C24 = (Fix64)24;
	const Fix64 F64::C50 = (Fix64)50;
	const Fix64 F64::C60 = (Fix64)60;
	const Fix64 F64::C120 = (Fix64)120;
	const Fix64 F64::C0p001 = (Fix64)0.001;
	const Fix64 F64::C0p5 = (Fix64)0.5;
	const Fix64 F64::C0p25 = (Fix64)0.25;
	const Fix64 F64::C1em09 = (Fix64)1e-9;
	const Fix64 F64::C1em9 = (Fix64)1e-9;
	const Fix64 F64::Cm1em9 = (Fix64)(-1e-9);
	const Fix64 F64::C1em14 = (Fix64)(1e-14);
	const Fix64 F64::C0p1 = (Fix64)0.1;
	const Fix64 F64::OneThird = (Fix64)1 / (Fix64)3;
	const Fix64 F64::C0p75 = (Fix64)0.75;
	const Fix64 F64::C0p15 = (Fix64)0.15;
	const Fix64 F64::C0p3 = (Fix64)0.3;
	const Fix64 F64::C0p0625 = (Fix64)0.0625;
	const Fix64 F64::C0p99 = (Fix64).99;
	const Fix64 F64::C0p9 = (Fix64).9;
	const Fix64 F64::C1p5 = (Fix64)1.5;
	const Fix64 F64::C1p1 = (Fix64)1.1;
	const Fix64 F64::OneEighth = Fix64::One / Fix64(8);
	const Fix64 F64::FourThirds = Fix64(4) / Fix64(3);
	const Fix64 F64::TwoFifths = Fix64(2) / Fix64(5);
	const Fix64 F64::C0p2 = (Fix64)0.2;
	const Fix64 F64::C0p8 = (Fix64)0.8;
	const Fix64 F64::C0p01 = (Fix64)0.01;
	const Fix64 F64::C1em7 = (Fix64)1e-7;
	const Fix64 F64::C1em5 = (Fix64)1e-5;
	const Fix64 F64::C1em4 = (Fix64)1e-4;
	const Fix64 F64::C1em10 = (Fix64)1e-10;
	const Fix64 F64::Cm0p25 = (Fix64)(-0.25);
	const Fix64 F64::Cm0p9999 = (Fix64)(-0.9999);
	const Fix64 F64::C1m1em12 = Fix64::One - (Fix64)1e-12;
	const Fix64 F64::GoldenRatio = Fix64::One + Fix64::Sqrt((Fix64)5) / (Fix64)2;
	const Fix64 F64::OneTwelfth = Fix64::One / (Fix64)12;
	const Fix64 F64::C0p0833333333 = (Fix64).0833333333;
	const Fix64 F64::C90000 = (Fix64)90000;
	const Fix64 F64::C600000 = (Fix64)600000;

}
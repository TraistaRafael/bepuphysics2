#include "Fix64.h"

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

Fix64 &Fix64::operator|=(const Fix64 &rhs)
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
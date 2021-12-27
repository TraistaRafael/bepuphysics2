#pragma once

#include "common.h"

namespace BEPUutilities
{
	static class F64
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
		/*const Fix64 C0p001 = (Fix64)0.001m;
		const Fix64 C0p5 = (Fix64)0.5m;
		const Fix64 C0p25 = (Fix64)0.25m;
		const Fix64 C1em09 = (Fix64)1e-9m;
		const Fix64 C1em9 = (Fix64)1e-9m;
		const Fix64 Cm1em9 = (Fix64)(-1e-9m);
		const Fix64 C1em14 = (Fix64)(1e-14m);		
		const Fix64 C0p1 = (Fix64)0.1m;
		const Fix64 OneThird = (Fix64)1/(Fix64)3;
		const Fix64 C0p75 = (Fix64)0.75m;
		const Fix64 C0p15 = (Fix64)0.15m;
		const Fix64 C0p3 = (Fix64)0.3m;
		const Fix64 C0p0625 = (Fix64)0.0625m;
		const Fix64 C0p99 = (Fix64).99m;
		const Fix64 C0p9 = (Fix64).9m;
		const Fix64 C1p5 = (Fix64)1.5m;
		const Fix64 C1p1 = (Fix64)1.1m;
		const Fix64 OneEighth = Fix64.One / 8;
		const Fix64 FourThirds = new Fix64(4) / 3;
		const Fix64 TwoFifths = new Fix64(2) / 5;
		const Fix64 C0p2 = (Fix64)0.2m;
		const Fix64 C0p8 = (Fix64)0.8m;
		const Fix64 C0p01 = (Fix64)0.01m;
		const Fix64 C1em7 = (Fix64)1e-7m;
		const Fix64 C1em5 = (Fix64)1e-5m;
		const Fix64 C1em4 = (Fix64)1e-4m;
		const Fix64 C1em10 = (Fix64)1e-10m;
		const Fix64 Cm0p25 = (Fix64)(-0.25m);
		const Fix64 Cm0p9999 = (Fix64)(-0.9999m);
		const Fix64 C1m1em12 = Fix64.One - (Fix64)1e-12m;
		const Fix64 GoldenRatio = Fix64.One + Fix64.Sqrt((Fix64)5) / (Fix64)2;
		const Fix64 OneTwelfth = Fix64.One / (Fix64)12;
		const Fix64 C0p0833333333 = (Fix64).0833333333m;*/
		static const Fix64 C90000;
		static const Fix64 C600000;
	};

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
const Fix64 F64::C90000 = (Fix64)90000;
const Fix64 F64::C600000 = (Fix64)600000;

}

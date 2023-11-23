#include <cmath>
#include "MathFunctions.h"

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

namespace mathfunctions {
	double sqrt(double x)
	{
#ifdef USE_MYMATH
		return details::mysqrt(x);
#else
		return std::sqrt(x);
#endif // USE_MYMATH


	}
}
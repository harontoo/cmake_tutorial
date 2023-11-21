#include "mysqrt.h"

namespace mathfunctions {
	namespace details {
		//a hack square root calculations using simple operations.
		double mysqrt(double x)
		{
			if (x <= 0)
			{
				return 0;
			}

			double result = x;
			//do ten iterations.
			for (int i; i <= 10; ++i)
			{
				if (result <= 0)
				{
					result = 0.1;
				}

				double delta = x - (result * result);
				result = result + 0.5 * delta / result;
				std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
			}
			return result;
		}
	}
}
#include <iostream>
#include "mysqrt.h"
#include "Table.h"
#include <cmath>

namespace mathfunctions {
	namespace details {
		//a hack square root calculations using simple operations.
		double mysqrt(double x)
		{
			//Check if USE_MYMATH library actually gets called
			std::cout << "Hello World,USE_MYMATH IS ON" << std::endl;

			//Use cmath implementation based on the resultim values of HAVE_LOG and HAVE_EXP
#if defined(HAVE_LOG) && defined(HAVE_EXP)
			double result = std::exp(std::log(x) * 0.5);
			std::cout << "Computing sqrt of " << x << " to be " << result
				<< " using log and exp" << std::endl;
			return result;
#else
			
			if (x <= 0)
			{
				return 0;
			}

			// use the table to help find an initial value
			double result = x;
			if (x >= 1 && x < 10) {
				std::cout << "Use the table to help find an initial value " << std::endl;
				result = sqrtTable[static_cast<int>(x)];
			}

	
			//do ten iterations.
			for (int i=1; i <= 10; ++i)
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
#endif
		}
	}
}
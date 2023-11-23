#include <iostream>
#include "mysqrt.h"

namespace mathfunctions {
	namespace details {
		//a hack square root calculations using simple operations.
		double mysqrt(double x)
		{
			//Check if USE_MYMATH library actually gets called
			std::cout << "Hello World,USE_MYMATH IS ON" << std::endl;	
			if (x <= 0)
			{
				return 0;
			}

			double result = x;
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
		}
	}
}
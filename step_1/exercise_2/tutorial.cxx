#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>


int main(int argc,char* argv[])
{
	std::cout<<"*Step 1 Exercise 2*\n"<<std::endl;
//if no input is provided show the user some help on how to interact with the program via cmd/terminal
	if(argc<2)
	{
		std::cout<<"Usage: "<<argv[0]<<" number"<<std::endl;
		return 1;
	}

	//Convert input to double
	const double inputValue = std::stod(argv[1]);

	//Calculate square root
	const double outputValue = sqrt(inputValue);
	std::cout<<"The square root of "<<inputValue<<" is "<<outputValue<<std::endl;
	return 0;

	std::cin.get();
}

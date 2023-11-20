//A simple program that computes the square root of a number
#include <cmath>
#include <cstdlib>//TODO 5:Remove this line
#include <iostream>
#include <string>

//TODO 11: Include TutorialConfig.h
int main(int argc,char* argv[])
{

	if(argc<2)
	{
		//TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
		//	and Tutorial_VERSION_MINOR
		std::cout<<"Usage: "<<argv[0]<<" number"<<std::endl;
		return 1;
	}

	//Convert input to double
	//TODO 4: Replace atof(argv1) with std::stod(argv[1])
	const double inputValue = atof(argv[1]);

	//Calculate square root
	const double outputValue = sqrt(inputValue);
	std::cout<<"The square root of "<<inputValue<<" is "<<outputValue<<std::endl;
	return 0;

	std::cin.get();
}

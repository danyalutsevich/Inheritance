
#include <iostream>
#include "Library.h"
#include "Factory.h"


int main()
{

	
	LitFactory factory;
	std::string str = "title:Quantum mechanics\nnumber:7\nyear:3";
	Literature *fund=factory.fromString(str);
	std::cout << fund->toString() << "\n";
	delete fund;
	
	
}	


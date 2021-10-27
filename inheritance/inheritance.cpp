
#include <iostream>
#include "Library.h"
#include "Factory.h"


int main()
{


	LitFactory factory;

	std::vector<Literature*>funds;

	try {


		funds=factory.fromDirectory("./literature");
		for (int i = 0; i < funds.size(); i++) {

			std::cout << funds[i]->toString() << "\n";

		}

		
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}

	for (int i = 0; i < funds.size(); i++) {

		
		delete funds[i];

	}






}


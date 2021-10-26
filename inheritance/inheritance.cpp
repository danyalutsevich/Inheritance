
#include <iostream>
#include "Library.h"
#include "Factory.h"


int main()
{


	LitFactory factory;

	Literature** fund = NULL;

	try {


		fund = factory.fromDir("./literature");
		std::cout << fund[0]->toString() << "\n";

		
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}


	delete fund[0];






}


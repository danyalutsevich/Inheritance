
#include <iostream>
#include "Library.h"
#include "Factory.h"


int main()
{


	LitFactory factory;
	

	Literature* fund = factory.fromFile("data.txt");
	std::cout << fund->toString() << "\n";


	if (dynamic_cast<Magazine*>(fund)) {

		delete dynamic_cast<Magazine*>(fund);
	}
	else if (dynamic_cast<Booklet*>(fund)) {

		delete dynamic_cast<Booklet*>(fund);
	}
	else if (dynamic_cast<Newspaper*>(fund)) {

		delete dynamic_cast<Newspaper*>(fund);
	}
	else if (dynamic_cast<Journal*>(fund)) {

		delete dynamic_cast<Journal*>(fund);
	}
	else if (dynamic_cast<Book*>(fund)) {

		delete dynamic_cast<Book*>(fund);
	}
	else {

		delete fund;
	}


	


}


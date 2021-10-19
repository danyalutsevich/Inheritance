
#include <iostream>
#include "Library.h"



int main()
{

	Book* book = new Book;
	book->SetAuthor("author")->SetTitle("book");

	Journal * journal = new Journal;
	journal->SetNumber(1)->SetTitle("journal");
	
	Newspaper* newspaper = new Newspaper;
	newspaper->SetDate("date")->SetTitle("newspaper");
	
	//std::cout << book->toString()<<"\n";

	//std::cout << journal->toString()<<"\n";

	//std::cout << newsPaper->toString() << "\n";

	Literature** funds = new Literature*[3];

	funds[0] = book;
	funds[1] = journal;
	funds[2] = newspaper;

	for (int i = 0; i < 3; i++) {

		std::cout << funds[i]->toString() << "\n";

	}



	delete newspaper;
	delete journal;
	delete book;
	return 0;

}


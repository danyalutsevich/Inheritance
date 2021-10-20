
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

	Booklet* booklet = new Booklet;
	booklet->SetDate("date")->SetAuthor("author")->SetTitle("booklet");

	Magazine* mag = new Magazine;
	mag->SetYear(2077)->SetNumber(0)->SetTitle("magazine");



	Literature** funds = new Literature*[5];

	funds[0] = book;
	funds[1] = journal;
	funds[2] = newspaper;
	funds[3] = booklet;
	funds[4] = mag;


	for (int i = 0; i < 5; i++) {

		std::cout << funds[i]->toString() << "\n";

	}


	delete booklet;
	delete newspaper;
	delete journal;
	delete book;

	return 0;

}


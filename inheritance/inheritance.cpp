
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

	std::cout << "\n\n";

	for (int i = 0; i < 5; i++) {
		
		Book* ptr = dynamic_cast<Book*>(funds[i]);

		if (ptr != NULL) {
			std::cout << ptr->GetAuthor()<< " " << ptr->GetTitle() << "\n";

		}
	}

	for (int i = 0; i < 5; i++) {

		Newspaper* ptr = dynamic_cast<Newspaper*>(funds[i]);

		if (ptr != NULL) {
			std::cout << ptr->GetDate() << " " << ptr->GetTitle() << "\n";

		}
	}

	for (int i = 0; i < 5; i++) {

		Journal* ptr = dynamic_cast<Journal*>(funds[i]);

		if (ptr != NULL) {
			std::cout << ptr->GetNumber() << " " << ptr->GetTitle() << "\n";

		}
	}

	for (int i = 0; i < 5; i++) {

		Childish* ptr = dynamic_cast<Childish*>(funds[i]);

		if (ptr != NULL) {
			std::cout <<funds[i]->toString() << "\n";

		}
	}



	delete mag;
	delete booklet;
	delete newspaper;
	delete journal;
	delete book;
	delete[] funds;
	return 0;

}


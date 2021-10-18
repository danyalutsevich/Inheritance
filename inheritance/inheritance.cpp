
#include <iostream>
#include "Library.h"



int main()
{

	Book* book = new Book;
	book->SetAuthor("author")
		->SetTitle("title");

	std::cout
		<< book->GetAuthor()
		<< " "
		<< book->GetTitle()
		<< "\n";


	Journal * journal = new Journal;
	journal->SetNumber(2)->SetTitle("title");
	std::cout << journal->GetTitle() << " " << journal->GetNumber();


	NewsPaper* newsPaper = new NewsPaper;
	newsPaper->SetDate("date")->SetTitle("title");
	std::cout << newsPaper->GetDate() << " " << newsPaper->GetTitle();


	delete newsPaper;
	delete journal;
	delete book;
	return 0;

}


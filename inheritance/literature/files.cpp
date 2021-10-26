

#include <iostream>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <string>

int main()
{
	for (auto const & dir : std::filesystem::directory_iterator("C:/")) {


		std::cout<<std::setw(7)
			<<((dir.is_directory()) 
				? "<DIR>" 
				: std::to_string(dir.file_size()))
			<<" "
			<< dir
			<< "\n";

	}
}


int main1()
{

	std::ofstream out;
	out.open("data.txt");
	out << "hello world\n";
	out.close();


	std::ifstream input;
	input.open("data.txt");
	char str[100];
	std::string data;

	while (!input.eof())
	{
		input.read(str, 5);
		std::streamsize n = input.gcount();
		str[n] = 0;
		
	
		data += str;
	}

	std::cout <<"\n"<< data;
		input.close();



}


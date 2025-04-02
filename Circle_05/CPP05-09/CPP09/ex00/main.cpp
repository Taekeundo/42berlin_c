#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "Error: could not open file." << EOC << std::endl;
		return (1);
	}
	try
	{
		/*	1. Constructor
			Open the "data.scv"file. While reading each line, the values
			​​before and after the comma are stored in the map container.
			= For saving data of "data.scv" file to the map container.
		*/
		BitcoinExchange bitcoinExchange;

		/*	2. Processer
			Reads the given file, processes each line, parses the date and value information, verifies it, and outputs the result.
			= 주어진 파일을 읽어 각 줄을 처리하고 날짜와 값 정보를 파싱하여 검증 후 결과를 출력.
		*/
		bitcoinExchange.processInputFile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << EOC << e.what() << std::endl;
	}
	return (0);
}

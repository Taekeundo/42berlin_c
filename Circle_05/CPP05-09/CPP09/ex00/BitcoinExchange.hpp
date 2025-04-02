#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/* MACRO */
// Bold color definitions using ANSI
#define EOC "\033[0;0m"
#define RED "\033[1;31m"
#define GRE "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define PUR "\033[1;35m"
#define CYN "\033[1;36m"
#define WHI "\033[1;37m"

/* HEADER FILE */
#include <iostream>		// std::cout, std::cerr
#include <map>			// Container: "map"
#include <string>		// std::string
#include <sstream>		// std::stringstream
#include <fstream>		// std::ifstream
#include <algorithm>	// std::find(), std::erase()

/*	CLASS
	[ Background ]
	1. std::map<std::string, double> mapData;
		It stores data(string key, double value) to the map type container.
			first  -> Key: "date"
			second -> Value: "exchangeRate"
*/
class BitcoinExchange
{
	private:
		/* [ Member variable ]: 1ea */
		std::map<std::string, double> mapData;

	public:
        /* [ OCCF ]: 4ea */
		BitcoinExchange();                          			// Default constructor
        ~BitcoinExchange();                         			// Destructor
        BitcoinExchange(const BitcoinExchange& other);          // Copy constructor
		BitcoinExchange& operator=(const BitcoinExchange& rhs);	// Overloaded assignment operator

		/* [ Method ]: 7ea */
		// [f] processInputFile: 3ea
		bool	splitLineByDelimiter(const std::string& line, char delimiter, std::string& date, std::string& value);
		void	trimWhitespace(std::string& str);
		void	processInputFile(const std::string& filename);

		// [f] validateDateFormat: 2ea
		bool	isLeapYear(int year);
		void	validateDateFormat(std::string date);

		// [f] validateAndConvertValue: 1ea
		double	validateAndConvertValue(std::string value);

		// [f] displayExchangeResult: 1ea
		void	displayExchangeResult(std::string date, double value);

		/* [ Exception ]: 7ea */
		// Open: 2ea
		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OpenDataException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		// Date: 2ea
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class EarlyDateException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		// Value: 3ea
		class InvalidValueException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OutOfRangeValueException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NegativeValueException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif

#ifndef CONSOLE_MANAGER_HPP_
#define CONSOLE_MANAGER_HPP_

#include <string>
#include <iostream>


enum class dataType
{
	OTHER = 0,
	INTEGER,
	DOUBLE,
	STRING,
	DATE
};

class ConsoleManager
{
	public:

		ConsoleManager() = default;
		virtual ~ConsoleManager() = default;

		void printDataType();
		void commandNotFound(const std::string& cmd);

};

#endif // CONSOLE_MANAGER_HPP_

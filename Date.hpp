#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

class Date
{
	public:
		int day;
		int month;
		int year;

		bool operator<(const Date& second) const
		{
			if (year < second.year)
				return true;

			if (year == second.year && month < second.month)
				return true;

			if (year == second.year && month == second.month && day < second.day)
				return true;

			return (false);
		}
		bool operator>(const Date& second) const
		{
			return (second < *this);
		}

		bool operator==(const Date& second) const
		{
			return (!(second < *this) && !(second > *this));
		}

		bool operator>=(const Date& second) const
		{
			return ((second == *this) && (second > *this));
		}

		static Date parseDate(const std::string& data)
		{
			Date retDate{};

			std::vector<std::string> date;
			boost::split(date, data, boost::is_any_of(":"));
			retDate.day = std::stoi(date[0]);
			retDate.month = std::stoi(date[1]);
			retDate.year = std::stoi(date[2]);

			return (retDate);
		}
};

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif // DATE_HPP_

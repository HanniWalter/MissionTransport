#include "DateTime.h"

DateTime::DateTime()
{
	year = 1;
	month = 1;
	day = 1;
	hour = 0;
	minute = 0;
	second = 0;
	millisecond = 0;
}

DateTime::DateTime(unsigned int year_, unsigned int month_, unsigned int day_, unsigned int hour_, unsigned int minute_, unsigned int second_, unsigned int millisecond_)
{
	this->year = year_;
	this->month = month_;
	this->day = day_;
	this->hour = hour_;
	this->minute = minute_;
	this->second = second_;
	this->millisecond = millisecond_;
}

DateTime::~DateTime()
{
}

unsigned int DateTime::getYYYY()
{
	return year;
}

std::string DateTime::getMMM()
{
	switch (getMM())
	{
	case 1:
		return std::string("JAN");
	case 2:
		return std::string("FEB");
	case 3:
		return std::string("MAR");
	case 4:
		return std::string("APR");
	case 5:
		return std::string("MAI");
	case 6:
		return std::string("JUN");
	case 7:
		return std::string("JUL");
	case 8:
		return std::string("AUG");
	case 9:
		return std::string("SEP");
	case 10:
		return std::string("OKT");
	case 11:
		return std::string("NOV");
	case 12:
		return std::string("DEZ");
	}
	return std::string();
}

unsigned int DateTime::getMM()
{
	return month;
}

unsigned int DateTime::getDD()
{
	return day;
}

unsigned int DateTime::gethh()
{
	return hour;
}

unsigned int DateTime::getmm()
{
	return minute;
}

unsigned int DateTime::getss()
{
	return second;
}

unsigned int DateTime::getms()
{
	return millisecond;
}

std::string DateTime::getDateTime()
{
	return  std::to_string(getDD()) + "." + getMMM() + "." + std::to_string(getYYYY()) + "		"+std::to_string(getms()) +":" +std::to_string(getss()) +":"+ std::to_string(getmm()) + ":" + std::to_string(gethh());
}

bool DateTime::isLeapYear()
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}

unsigned int DateTime::getMaxMonth()
{
	switch (month)
	{
	case 1:
		return 31;
	case 2:
	{
		if (isLeapYear()) {
			return 29;
		}
		else
		{
			return 28;
		}
	}
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	}
	return NULL;
}

unsigned int DateTime::addYYYY(unsigned int year_)
{
	int returner = 0;
	if (year_ > 0) returner = 1;
	year += year_;
	return returner;
}

unsigned int DateTime::addMM(unsigned int month_)
{
	int returner = 0;
	if (month_ > 0) returner = 1;
	month += month_;
	returner += addYYYY(month / 12);
	month = (month-1) % 12+1;
	return returner;
}

unsigned int DateTime::addDD(unsigned int day_)
{
	int returner = 0;
	if (day_ > 0) returner = 1;
	day += day_;
	int returner2 = 0;
	while (day > getMaxMonth())
	{
		day = ((day-1) % getMaxMonth())+1;
		int returner3 = addMM(1);
		if (returner3 > returner2)returner2 = returner3;

	}
	return returner + returner2;
}

unsigned int DateTime::addhh(unsigned int hour_)
{
	int returner = 0;
	if (hour_ > 0)
	{
		returner = 1;
		hour += hour_;
		returner += addDD(hour / 24);
		hour = hour % 24;
	}
	return returner;
}

unsigned int DateTime::addmm(unsigned int minute_)
{
	int returner = 0;
	if (minute_ > 0) 
	{
		returner = 1;
		minute += minute_;
		returner += addhh(minute / 60);
		minute = minute % 60;
	}
	return returner;
}

unsigned int DateTime::addss(unsigned int second_)
{
	int returner = 0;
	if (second_ > 0)
	{
		returner = 1;
		second += second_;
		returner += addmm(second / 60);
		second = second % 60;
	}
	return returner;
}

/*
*return 0 nothing changed
*return 1 ms changed
*return 2 ss changed
*return 3 mm changed
*return 4 hh changed
*return 5 DD changed
*return 6 MM changed
*return 7 YYYY changed
*/
unsigned int DateTime::addms(unsigned int millisecond_)
{
	int returner = 0;
	if (millisecond_ > 0) {
		returner = 1;
		millisecond += millisecond_;
		returner +=addss(millisecond / 1000);
		millisecond = millisecond % 1000;
	}
	return returner;
}
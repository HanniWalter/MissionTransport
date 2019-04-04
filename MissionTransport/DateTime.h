#pragma once
#include <string>
class DateTime
{
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
	unsigned int millisecond;

public:
	DateTime();
	DateTime(unsigned int year_, unsigned int month_, unsigned int day_, unsigned int hour__, unsigned int minute_, unsigned int second_, unsigned int millisecond_);
	~DateTime();
	unsigned int getYYYY();
	std::string getMMM();
	unsigned int getMM();
	unsigned int getDD();
	unsigned int gethh();
	unsigned int getmm();
	unsigned int getss();
	unsigned int getms();
	std::string getDateTime();

	bool isLeapYear();

	unsigned int getMaxMonth();

	unsigned int addYYYY(unsigned int year_);
	unsigned int addMM(unsigned int month_);
	unsigned int addDD(unsigned int day_);
	unsigned int addhh(unsigned int hour_);
	unsigned int addmm(unsigned int minute_);
	unsigned int addss(unsigned int second_);
	unsigned int addms(unsigned int millisecond_);


	bool operator==(DateTime d);
	bool operator<=(DateTime d);
	bool operator>=(DateTime d);
	bool operator<(DateTime d);
	bool operator>(DateTime d);
	bool operator!=(DateTime d);
};


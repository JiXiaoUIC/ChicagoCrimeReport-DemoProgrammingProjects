/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program
//
// Ji Xiao
// Bachelor of Science in Computer Science
// U. of Illinois, Chicago
// College of Engineering, Department of Computer Science
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


class CrimeCode
{
private:
	string Iucr;
	string PriDes;
	string SecDes;
	int Times;

public:
	// constructor
	CrimeCode(string iucr, string priDes, string secDes)
		: Iucr(iucr), PriDes(priDes), SecDes(secDes), Times(0)
	{	}

	// setters
	void setIucr(string i)
	{
		Iucr = i;
	}

	void setPriDes(string p)
	{
		PriDes = p;
	}

	void setSecDes(string s)
	{
		SecDes = s;
	}

	void addTime()
	{
		Times++;
	}

	// getters
	string getIucr()
	{
		return Iucr;
	}

	string getPriDes()
	{
		return PriDes;
	}

	string getSecDes()
	{
		return SecDes;
	}

	int getTimes()
	{
		return Times;
	}

};

class CrimeReport
{
private:
	string DateTime;
	string Iucr;
	bool Arrest;
	bool Domestic;
	int Beat;
	int District;
	int Ward;
	int Community;

public:
	// constructor
	CrimeReport(string dateTime, string iucr, bool arrest, bool domestic, int beat, int district, int ward, int community)
		: DateTime(dateTime), Iucr(iucr), Arrest(arrest), Domestic(domestic), Beat(beat), District(district), Ward(ward), Community(community)
	{	}

	// setters
	void setDateTime(string d)
	{
		DateTime = d;
	}

	void setIucr(string i)
	{
		Iucr = i;
	}

	void setArrest(bool a)
	{
		Arrest = a;
	}

	bool setDomestic(bool d)
	{
		Domestic = d;
	}

	int setBeat(int b)
	{
		Beat = b;
	}

	int setDistrict(int d)
	{
		District = d;
	}

	int setWard(int w)
	{
		Ward = w;
	}

	int setCommunity(int c)
	{
		Community = c;
	}

	// getters
	string getDateTime()
	{
		return DateTime;
	}

	string getIucr()
	{
		return Iucr;
	}

	bool getArrest()
	{
		return Arrest;
	}

	bool getDomestic()
	{
		return Domestic;
	}

	int getBeat()
	{
		return Beat;
	}

	int getDistrict()
	{
		return District;
	}

	int getWard()
	{
		return Ward;
	}

	int getCommunity()
	{
		return Community;
	}

};

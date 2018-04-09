/*main.cpp*/

//
// Chicago Crime Analysis program in C++.
//
// Ji Xiao
// Bachelor of Science in Computer Science
// U. of Illinois, Chicago
// College of Engineering, Department of Computer Science
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;

// function prototypes
void loadCrimeCodes(ifstream& cc, vector<CrimeCode>& c);
void loadCrimeReports(ifstream& cr, vector<CrimeReport>& r);
void sortCrimeCodes(vector<CrimeCode>& cc);
void printCrimeCodes(vector<CrimeCode>& cc);
void printCrimeReports(vector<CrimeReport>& cr);
void findTop5(vector<CrimeCode>& cc, vector<CrimeReport>& cr);

int main()
{
	string  crimeCodesFilename, crimesFilename;

	cin >> crimeCodesFilename;
	cout << crimeCodesFilename << endl;

	cin >> crimesFilename;
	cout << crimesFilename << endl;

	ifstream  codesFile(crimeCodesFilename);
	ifstream  crimesFile(crimesFilename);

	cout << std::fixed;
	cout << std::setprecision(2);

	if (!codesFile.good())
	{
		cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
		return -1;
	}
	if (!crimesFile.good())
	{
		cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
		return -1;
	}


	cout << "** Crime Analysis **" << endl;
	cout << endl;

	// Declare vector for hold crime-codes
	vector<CrimeCode> crimeCodes;
	// Declare vector for hold crime-reports
	vector<CrimeReport> crimeReports;

	// load crime codes
	loadCrimeCodes(codesFile, crimeCodes);
	// load crimes
	loadCrimeReports(crimesFile, crimeReports);

	// print out date range
	cout << "Date range: " << crimeReports.front().getDateTime() << " - " << crimeReports.back().getDateTime() << endl;
	cout << endl;

	// sort crime codes
	sortCrimeCodes(crimeCodes);

	// print number of crime codes and first 3 and last 3 crime codes
	printCrimeCodes(crimeCodes);

	// print number of crime reports and first 3 and last 3 crime reports
	printCrimeReports(crimeReports);

	// top 5 crimes
	findTop5(crimeCodes, crimeReports);

	// Done
	cout << "** Done **" << endl;

	return 0;
}

void printCrimeCodes(vector<CrimeCode>& cc)
{
	// print out number of crime codes
	cout << "# of crime codes: " << cc.size() << endl;

	// print first 3 and last 3
	for (int i = 0; i < 3; i++)
		cout << cc[i].getIucr() << ":   " << cc[i].getPriDes() << ":" << cc[i].getSecDes() << endl;
	cout << "..." << endl;
	for (int i = cc.size() - 3; i < cc.size(); i++)
		cout << cc[i].getIucr() << ":   " << cc[i].getPriDes() << ":" << cc[i].getSecDes() << endl;

	cout << endl;
}

void printCrimeReports(vector<CrimeReport>& cr)
{
	// print out number of crime reports
	cout << "# of crimes: " << cr.size() << endl;

	// print first 3 and last 3
	for (int i = 0; i < 3; i++)
	{
		cout << cr[i].getIucr() << ":   " << cr[i].getDateTime() << ", " << cr[i].getBeat() << ", " << cr[i].getDistrict() << ", " << cr[i].getWard() << ", " << cr[i].getCommunity();
		if (cr[i].getArrest() == true)
			cout << ", arrested";
		if (cr[i].getDomestic() == true)
			cout << ", domestic violence";
		cout << endl;
	}
	cout << "..." << endl;
	for (int i = cr.size() - 3; i < cr.size(); i++)
	{
		cout << cr[i].getIucr() << ":   " << cr[i].getDateTime() << ", " << cr[i].getBeat() << ", " << cr[i].getDistrict() << ", " << cr[i].getWard() << ", " << cr[i].getCommunity();
		if (cr[i].getArrest() == true)
			cout << ", arrested";
		if (cr[i].getDomestic() == true)
			cout << ", domestic violence";
		cout << endl;
	}

	cout << endl;

}

void sortCrimeCodes(vector<CrimeCode>& cc)
{
	sort(cc.begin(),
		cc.end(),
		[](CrimeCode& c1, CrimeCode& c2)
	{
		if (c1.getIucr() < c2.getIucr())
			return true;
		else
			return false;
	});
}

void loadCrimeCodes(ifstream& cc, vector<CrimeCode>& c)
{
	string inputLine;
	string tokenIucr, tokenPriDes, tokenSecDes;
	string tIucr; string tPriDes, tSecDes;

	// ignore the first line
	getline(cc, inputLine);

	// while loop for store all data to vector
	while (getline(cc, inputLine))
	{
		stringstream ss(inputLine);

		getline(ss, tokenIucr, ',');
		getline(ss, tokenPriDes, ',');
		getline(ss, tokenSecDes, '\n');

		tIucr = tokenIucr;
		tPriDes = tokenPriDes;
		tSecDes = tokenSecDes;

		c.push_back(CrimeCode(tIucr, tPriDes, tSecDes));
	}

}

bool stringToBoolean(string s)
{
	if (s == "TRUE" || s == "true")
		return true;
	else if (s == "FALSE" || s == "false")
		return false;
	else		// in case something wrong in input file
		exit(0);
}

void loadCrimeReports(ifstream& cr, vector<CrimeReport>& r)
{
	string inputLine;
	string tokenDateTime, tokenIucr, tokenArrest, tokenDomestic, tokenBeat, tokenDistrict, tokenWard, tokenCommunity;
	string tDateTime, tIucr;	int tBeat, tDistrict, tWard, tCommunity; bool tArrest, tDomestic;

	// ignore the first line
	getline(cr, inputLine);

	// while loop for store all data to vector
	while (getline(cr, inputLine))
	{
		stringstream ss(inputLine);

		getline(ss, tokenDateTime, ',');
		getline(ss, tokenIucr, ',');
		getline(ss, tokenArrest, ',');
		getline(ss, tokenDomestic, ',');
		getline(ss, tokenBeat, ',');
		getline(ss, tokenDistrict, ',');
		getline(ss, tokenWard, ',');
		getline(ss, tokenCommunity, ',');

		tDateTime = tokenDateTime;
		tIucr = tokenIucr;
		tArrest = stringToBoolean(tokenArrest);
		tDomestic = stringToBoolean(tokenDomestic);
		tBeat = stoi(tokenBeat);
		tDistrict = stoi(tokenDistrict);
		tWard = stoi(tokenWard);
		tCommunity = stoi(tokenCommunity);

		r.push_back(CrimeReport(tDateTime, tIucr, tArrest, tDomestic, tBeat, tDistrict, tWard, tCommunity));
	}

}

void findTop5(vector<CrimeCode>& cc, vector<CrimeReport>& cr)
{
	// top 5 crimes
	cout << "** Top-5 Crimes **" << endl;

	for (CrimeReport r : cr)
	{
		for (int i = 0; i < cc.size(); i++)
			if (r.getIucr() == cc[i].getIucr())
				cc[i].addTime();
	}

	int cTimes[5] = { 0,0,0,0,0 };
	int cPos[5] = { 0,0,0,0,0 };
	for (int i = 0; i < cc.size(); i++)
	{
		if (cc[i].getTimes() > cTimes[4])
		{
			cTimes[4] = cc[i].getTimes();
			cPos[4] = i;

			if (cTimes[4] > cTimes[3])
			{
				swap(cTimes[4], cTimes[3]);
				swap(cPos[4], cPos[3]);

				if (cTimes[3] > cTimes[2])
				{
					swap(cTimes[3], cTimes[2]);
					swap(cPos[3], cPos[2]);

					if (cTimes[2] > cTimes[1])
					{
						swap(cTimes[2], cTimes[1]);
						swap(cPos[2], cPos[1]);

						if (cTimes[1] > cTimes[0])
						{
							swap(cTimes[1], cTimes[0]);
							swap(cPos[1], cPos[0]);
						}
					}
				}
			}
		}
	}

	cout << "Code:   Total, Description" << endl;
	for (int i = 0; i < 5; i++)
		cout << cc[cPos[i]].getIucr() << ":	" << cc[cPos[i]].getTimes() << ", " << cc[cPos[i]].getPriDes() << ": " << cc[cPos[i]].getSecDes() << endl;

	cout << endl;
}
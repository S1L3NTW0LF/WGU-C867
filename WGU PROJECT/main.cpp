// WGU C867.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "degree.h"
#include "roster.h"

using namespace std;

int main()
{
	cout << "Scripting and Programming - Applications - C867\tC++\tWGUID# 007198614\tJordan Johnson" << endl << endl;
	roster classRoster;
	classRoster.printAll(); cout << endl;
	classRoster.printInvalidEmails(); cout << endl;
	classRoster.printAverageDaysInCourse(classRoster.classRosterArray[2].getStudentID()); cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE); cout << endl;
	classRoster.remove("A3"); cout << endl;
	classRoster.printAll(); cout << endl;
	classRoster.remove("A3");

	return 0;
}



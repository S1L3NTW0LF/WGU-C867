#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include"student.h"

using namespace std;

class roster {
public:
	roster();							//calls addStudentData on construction
	~roster();
	vector<Student> classRosterArray;
	void addStudentData();				//adds data from given Student Table 

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);

};
#endif


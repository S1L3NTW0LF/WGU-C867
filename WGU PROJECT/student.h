#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student
{
public:
	Student();
	//Constructor
	Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysInCourse, int newDaysinCourse1, int newDaysInCourse2, DegreeProgram newDegreeProgram);

	void setStudentID(string newStudentID);			//setter declaration
	string getStudentID();							//getter declaration 

	void setFirstName(string newFirstName);
	string getFirstName();

	void setLastName(string newLastName);
	string getLastName();

	void setEmailAddress(string newEmailAddress);
	string getEmailAddress();

	void setAge(int newAge);
	int getAge();

	void setDaysInCourse(int newDaysInCourse, int newDaysInCourse1, int newDaysInCourse2);
	int getDaysInCourse();
	int getDaysInCourse1();
	int getDaysInCourse2();

	void setDegreeProgram(DegreeProgram newDegreeProgram);
	string getDegreeProgram();			//set to string so that function can display words not numbers for console  

	void print();

private:								// can only be accessed through setters and getters
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int	age;
	vector<int> daysInCourse;
	DegreeProgram degreeProgram;
};
#endif
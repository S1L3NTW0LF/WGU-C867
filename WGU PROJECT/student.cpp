#include "student.h"
using namespace std;

Student::Student()
{
}

//Constructor
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newDaysInCourse, int newDaysinCourse1, int newDaysInCourse2, DegreeProgram newDegreeProgram)
{
	setStudentID(newStudentID);				//passes newStudentID through setStudentID function which then sets it to studentID 
	setFirstName(newFirstName);
	setLastName(newLastName);
	setEmailAddress(newEmailAddress);
	setAge(newAge);
	setDaysInCourse(newDaysInCourse, newDaysinCourse1, newDaysInCourse2);
	setDegreeProgram(newDegreeProgram);
}

void Student::setStudentID(string newStudentID)				//setter definition
{
	studentID = newStudentID;								//because setStudentID is part of the student class it has access to studentID which is private
}

string Student::getStudentID()								//getter definition
{
	return studentID;
}

void Student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setLastName(string newLastName)
{
	lastName = newLastName;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setEmailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

void Student::setAge(int newAge)
{
	age = newAge;
}

int Student::getAge()
{
	return age;
}

void Student::setDaysInCourse(int newDaysInCourse, int newDaysInCourse1, int newDaysInCourse2)
{
	vector<int> arrDaysInCourse = { newDaysInCourse, newDaysInCourse1, newDaysInCourse2 };
	daysInCourse = arrDaysInCourse;
}

int Student::getDaysInCourse()
{
	return daysInCourse.at(0);
}

int Student::getDaysInCourse1()
{
	return daysInCourse.at(1);
}

int Student::getDaysInCourse2()
{
	return daysInCourse.at(2);
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram)
{
	degreeProgram = newDegreeProgram;
}

string Student::getDegreeProgram()
{
	switch (degreeProgram)
	{
	case SECURITY:
		return "Security";
		break;
	case NETWORK:
		return "Network";
		break;
	case SOFTWARE:
		return "Software";
		break;
	default:
		return "Invalid";

	}

}

void Student::print()
{
	cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "daysInCourse: " << "{" << getDaysInCourse() << ", " << getDaysInCourse2() << ", " << getDaysInCourse2() << "}  " << "Degree Program: " << getDegreeProgram() << endl;
}
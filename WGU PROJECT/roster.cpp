#include "roster.h"

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Jordan,Johnson,jjo3694@wgu.edu,20,40,50,60,SOFTWARE" };

roster::roster()
{
	addStudentData();
}

roster::~roster()
{
	cout << "Destructor, destroy, destroy!!!" << endl;
}

void roster::addStudentData()
{
	for (int i = 0; i < 5; i++)
	{
		vector<string> line;						//creates new vector that stores parsed student data as seperate elements								
		istringstream inSS(studentData[i]);			//uses elements from studentData[] as input string stream 
		while (inSS.good()) {						//inSS.good returns true as long as no error flags are set
			string substr;
			getline(inSS, substr, ',');				//parses string by using commas
			line.push_back(substr);					//parsed data is added to vector array 
		}
		DegreeProgram degree = SECURITY;
		if (line.at(8) == "SECURITY") { degree = SECURITY; }		//takes string and creates enumerated variable set to SECURITY
		if (line.at(8) == "NETWORK") { degree = NETWORK; }
		if (line.at(8) == "SOFTWARE") { degree = SOFTWARE; }

		//uses parsed values from above to use as arguements for Student constructor
		Student student(line.at(0), line.at(1), line.at(2), line.at(3), stoi(line.at(4)), stoi(line.at(5)), stoi(line.at(6)), stoi(line.at(5)), degree);
		classRosterArray.push_back(student);		// adds student to classRosterArray 

		//cycle repeats 4 more times for each student
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	Student student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	classRosterArray.push_back(student);
}

void roster::remove(string studentID)
{
	bool FLAG = true;
	for (unsigned int i = 0; i < classRosterArray.size(); i++)		//loops the number of elements in array
	{

		if (classRosterArray[i].getStudentID() == studentID) {
			classRosterArray.erase(classRosterArray.begin() + (i - 1));
			FLAG = false;
		}
		if (i == (classRosterArray.size() - 1) && FLAG == true) {	//on the last loop if the FLAG has not been triggered by the previous if statement then "STUDENT NOT FOUND" will be printed
			cout << "STUDENT NOT FOUND" << endl;
		}
	}
}

void roster::printAll()
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray[i].print();
	}
}

void roster::printAverageDaysInCourse(string studentID)
{
	bool FLAG = true;
	for (unsigned int i = 0; i < classRosterArray.size(); i++)		//loops the number of elements in array
	{
		if (classRosterArray[i].getStudentID() == studentID) {
			int average = (classRosterArray[i].getDaysInCourse() + classRosterArray[i].getDaysInCourse1() + classRosterArray[i].getDaysInCourse2()) / 3;
			cout << "Average days in course: " << average << endl;
			FLAG = false;				//triggers FLAG
		}
		if (i == (classRosterArray.size() - 1) && FLAG == true) {	//on the last loop if the FLAG has not been triggered by the previous if statement then "STUDENT NOT FOUND" will be printed
			cout << "STUDENT NOT FOUND" << endl;
		}
	}
}

void roster::printInvalidEmails()
{

	for (unsigned int i = 0; i < classRosterArray.size(); i++)			//loops the number of elements in array
	{
		//if statement searches for index of '@', '.', ' ' using FIND. Because even if the character is not there it will produce an index index has to be between 500 and 0. 

		if (!(500 > classRosterArray[i].getEmailAddress().find('@') && classRosterArray[i].getEmailAddress().find('@') >= 0) ||  //if the index for @ is not inbetween 500 and 0 statement is false
			!(500 > classRosterArray[i].getEmailAddress().find('.') && classRosterArray[i].getEmailAddress().find('.') >= 0) ||  //if the index for . is not inbetween 500 and 0 statement is false 
			(500 > classRosterArray[i].getEmailAddress().find(' ') && classRosterArray[i].getEmailAddress().find(' ') >= 0))	 //if the index for " " is not inbetween 500 and 0 statement is true
		{
			cout << classRosterArray[i].getEmailAddress() << endl;		//only prints if one or more of the conditions for the if statements is true
		}
	}
}

void roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
	{
		switch (degreeprogram)
		{
		case SECURITY:
			if (classRosterArray[i].getDegreeProgram() == "Security") { classRosterArray[i].print(); }
			break;
		case NETWORK:
			if (classRosterArray[i].getDegreeProgram() == "Network") { classRosterArray[i].print(); }
			break;
		case SOFTWARE:
			if (classRosterArray[i].getDegreeProgram() == "Software") { classRosterArray[i].print(); }
			break;
		default:
			break;
		}
	}
}





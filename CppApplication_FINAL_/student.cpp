/*c867 final student.cpp
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;
	//this is the getter
	string student::getStudentID(){
		return StudentID;
	}
	string student::getFirstName()
	{
		return FirstName;
	}
	string student::getLastName()
	{
		return LastName;
	}
	string student::getEmailAddress()
	{
		return EmailAddress;
	}
	
	int student::getAge()
	{
		return Age;
	}
	int *student::getNumDaysToComplete()
	{
		return NumDaysToComplete;
	}
	Degree student::GetDegreeProgram()
	{
		return SECURITY;
	}

	// this is the setters
	void student::setStudentID(string studentID)
	{
		StudentID = studentID;
	}
	void student::setFirstName(string firstname)
	{
		FirstName = firstname;
	}
	void student::setLastName(string lastname)
	{
		LastName = lastname;
	}
	void student::setEmailAddress(string email)
	{
		EmailAddress = email;
	}
	
	void student::setAge(int age){
		Age = age;
	}
	void student::setNumDaysToComplete(int * A6)
	{
		NumDaysToComplete[0] = A6[0];
		NumDaysToComplete[1]= A6[1];
		NumDaysToComplete[2] = A6[2];
		
	}
        
	
        student::student(string A1, string A2, string A3, string A4, int A5, int * A6){
		StudentID = A1;
		FirstName = A2;
		LastName = A3;
		EmailAddress = A4;
		Age = A5;
		NumDaysToComplete[0] = A6[0];
		NumDaysToComplete[1]= A6[1];
		NumDaysToComplete[2] = A6[2];
		
		};
        
             //default constructor
        student::student(){}
        
	void student::print()
	{
	
	}
        //calling destructor to release memory
        student::~student(){}



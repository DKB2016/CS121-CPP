/*c867 final securityStudent.cpp
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */
#include <vector>

#include "SecurityStudent.h"
#include <iostream>

using namespace std;

Degree SecurityStudent::GetDegreeProgram(){
	return DegreeMajor;
}
void SecurityStudent::print(){

                cout << "Student identification: " << getStudentID() << "\t";
		cout << "First name: " << getFirstName() << "\t";
		cout << "Last name: " << getLastName() << "\t";
		cout << "Age: " << getAge() << "\t";
		cout << "Days left in Course: " << getNumDaysToComplete()[0] <<","<< getNumDaysToComplete()[1] <<","<<getNumDaysToComplete()[2] <<"\t";
		cout << "The Degree Major is: SECURITY" << endl;

}
SecurityStudent::SecurityStudent(){
    
    
}

SecurityStudent::~SecurityStudent(){
    
}

SecurityStudent::SecurityStudent(string SS1, string SS2, string SS3, string SS4, int SS5, int * SS6, Degree SS7) : student(SS1, SS2, SS3, SS4, SS5, SS6) {
    DegreeMajor = SS7;
    
}


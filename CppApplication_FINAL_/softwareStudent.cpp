/*c867 final softwareStudent.cpp
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */
#include<iostream>

#include "SoftwareStudent.h"

using namespace std;
Degree SoftwareStudent::GetDegreeProgram(){
	return DegreeMajor;
}
void SoftwareStudent::print(){

                cout << "Student identification: " << getStudentID() << "\t";
		cout << "First name: " << getFirstName() << "\t";
		cout << "Last name: " << getLastName() << "\t";
		cout << "Age: " << getAge() << "\t";
		cout << "Days left in Course: " << getNumDaysToComplete()[0] << "," << getNumDaysToComplete()[1] << "," << getNumDaysToComplete()[2] << "\t";
		cout << "The Degree Major is: SOFTWARE" << endl;

}
SoftwareStudent::SoftwareStudent(){
    
}

SoftwareStudent::~SoftwareStudent(){
    
}

SoftwareStudent::SoftwareStudent(string SW1, string SW2, string SW3, string SW4, int SW5, int* SW6, Degree SW7) : student(SW1, SW2, SW3, SW4, SW5, SW6) {
    
    DegreeMajor = SW7;
    
    
}

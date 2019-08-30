/*c867 final networkStudent.cpp
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

using namespace std;
Degree NetworkStudent::GetDegreeProgram(){
	return DegreeMajor;
}
void NetworkStudent::print(){

                cout << "Student identification: " << getStudentID() << "\t";
		cout << "First name: " << getFirstName() << "\t";
		cout << "Last name: " << getLastName() << "\t";
		cout << "Age: " << getAge() << "\t";
		cout << "Days left in Course: " << getNumDaysToComplete()[0] << "," << getNumDaysToComplete()[1] << "," << getNumDaysToComplete()[2] << "\t";
		cout << "The Degree Major is: NETWORK" << endl;
}
   NetworkStudent::NetworkStudent(){
   }
   
    NetworkStudent::~NetworkStudent(){
    }

    NetworkStudent::NetworkStudent(string NS1, string NS2, string NS3, string NS4, int NS5, int* NS6, Degree NS7) : student(NS1, NS2, NS3, NS4, NS5, NS6) {
        DegreeMajor = NS7;
        
    }
		


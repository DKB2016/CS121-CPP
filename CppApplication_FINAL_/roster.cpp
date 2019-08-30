/*c867 final roster.cpp
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <array>
//#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

using namespace std;
using std::cout;
using std::string;


void Roster::add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, Degree DegreeMajor){
    
        // int DaysInCourse[] = {DaysInCourse1, DaysInCourse2, DaysInCourse3};
        //creates a new variable to check if array is full
        
//       
        int daysLeft[3]; 
        daysLeft[0] = DaysInCourse1;
        daysLeft[1] = DaysInCourse2;
        daysLeft[2] = DaysInCourse3;
        
       
          
                if (DegreeMajor == NETWORKING)
                {
                   
                    classRosterArray[inx] = new NetworkStudent(StudentID, FirstName, LastName, EmailAddress, Age, daysLeft, DegreeMajor);

                }
                else if (DegreeMajor == SECURITY)
                {

                    classRosterArray[inx] = new SecurityStudent(StudentID, FirstName, LastName, EmailAddress, Age, daysLeft, DegreeMajor);
//                 
                }
                else if (DegreeMajor == SOFTWARE)
                {
                    classRosterArray[inx] = new SoftwareStudent(StudentID, FirstName, LastName, EmailAddress, Age, daysLeft, DegreeMajor);
//                 
                }
        inx++;
            }
            






	void Roster::remove(string StudentID){
            int flag = 0;
            for (int i=0; i < 5; i++){
                if (classRosterArray[i] != NULL && StudentID == classRosterArray[i]->getStudentID()){
                    classRosterArray[i] = nullptr;
                    flag = 1;
                    
                }
               
            }
             if(flag != 1) {
                    std::cout << "This Student ID: " << StudentID << " was not found." << endl;
                }
	}
	void Roster::printAll(){

			std::cout << "Current Roster: \t" << endl;

			for(int i = 0; i < 5; i++){
			 classRosterArray[i]->print();
			}
                        cout << "\n";

		}
                //number of days to complete 3 courses
        void Roster::printDaysInCourse(string StudentID)
        {
            for (int i = 0; i < 5; i++)
            {
                if ((*classRosterArray[i]).getStudentID() == StudentID)
                {
                    int TotalDays = (((*classRosterArray[i]).getNumDaysToComplete()[0] + (*classRosterArray[i]).getNumDaysToComplete()[1] + (*classRosterArray[i]).getNumDaysToComplete()[2]));
                    int AvgDays = TotalDays / 3.0;
                    std::cout << "The Average number of days in all three courses for Student: " << StudentID << " is " << AvgDays << endl;
                }
            }
		};
                //print out the invalid email addresses that don't meet certain criteria
        void Roster::printInvalidEmails()
        {
            cout << "The following emails are invalid: " << endl;
            for (int i = 0; i < 5; i++)
            {
                string EmailAddress = classRosterArray[i]->getEmailAddress();
                bool isPeriodFound = false;
                bool isAtFound = false;
                bool isSpaceFound = false;
                
                for (int j = 0; j < EmailAddress.length() - 1; ++j)
                {
                    if (EmailAddress[j] == ' ')
                    {
                        isSpaceFound = true;
                    }
                    if (EmailAddress[j] == '@')
                    {
                        isAtFound = true;
                    }
                    if (EmailAddress[j] == '.')
                    {
                        isPeriodFound = true;
                    }
                   
                }
                
                if (isSpaceFound == 1 || isAtFound == 0 || isPeriodFound == 0)
                {
                    std::cout << classRosterArray[i]->getEmailAddress();
                    
                    std::cout <<"\n";
                }
            }
		};
                //Prints out degree program
        void Roster::printByDegreeProgram(int DegreeProgram)
        {
            for (int i = 0; i < 5; i++)
            {
                if (classRosterArray[i] != nullptr)
                {
                    if (classRosterArray[i]->GetDegreeProgram() == DegreeProgram)
                    {
                        classRosterArray[i]->print();
                    }
                }
            }
		}
        
        student ** Roster::getClassRosterArray(){
            return classRosterArray;
        }

        Roster::Roster(){
            
        }
       


		//main application code
	int main(){
		Roster classRoster; //initialize the roster class
		int size = 5;
                Degree DegreeType;

        const string StudentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,David,Clark,dcla148@wgu.edu,23,30,45,50,SOFTWARE"};


        //loop through to pull the student information 
         for (int i = 0; i < size; i++)
        {

        stringstream sstream(StudentData[i]);
        string ArrayElement[9];
        int j = 0;
        while (sstream.good())
        {
            string element;
            std::getline(sstream, element, ',');
            ArrayElement[j] = element;
            j++;
        }
        if (ArrayElement[8] == "SECURITY")
        {
        DegreeType = SECURITY;
        }
        if (ArrayElement[8] == "SOFTWARE")
        {
        DegreeType = SOFTWARE;
        }
        if (ArrayElement[8] == "NETWORK")
        {
         DegreeType = NETWORKING;
        }
        classRoster.add(ArrayElement[0], ArrayElement[1], ArrayElement[2], ArrayElement[3], stoi(ArrayElement[4]),stoi(ArrayElement[5]), stoi(ArrayElement[6]), stoi(ArrayElement[7]),  DegreeType);
       
        }

            //Prints class information
            std::cout << "(C867)Scripting and Programming-Applications" << std::endl;
            //Prints the programming language used.
            std::cout << "Programming Language is C++" << std::endl;
            //Prints student information
            std::cout << "David J. Clark, StudentID: 000685359" << std::endl;
            std::cout << "\n";

            classRoster.printAll();
            classRoster.printInvalidEmails();
            //loop through classRosterArray
            cout << "\n";
            for(int i = 0; i < 5; i++){
                classRoster.printDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
            }
            cout << "\n";
            classRoster.printByDegreeProgram(SOFTWARE);
            classRoster.remove("A3");
            classRoster.remove("A3");

            return 0;
            
            //~Roster();
    }

	//calls the destructor to release memory
 Roster::~Roster(){
     for(int i = 0; i < 5; i++){
         if(classRosterArray != nullptr)
         delete classRosterArray[i];
     }
        }








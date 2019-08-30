/*c867 final student.h
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "degree.h"

using namespace std;

class student {
    //public members
public:
        student();//default constructor
	//this is the getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	
	int getAge();
	int * getNumDaysToComplete();
	virtual Degree GetDegreeProgram();
        virtual void print();

	// this is the setters
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setAge(int);
	void setNumDaysToComplete(int *);
	student(string A1, string A2, string A3, string A4, int A5, int * A6);
	
	
        ~student(); //destructor to release memory
private:
    //private members
	string StudentID, FirstName, LastName, EmailAddress;
	int Age;
	int NumDaysToComplete[3];

};



#endif /* STUDENT_H_ */



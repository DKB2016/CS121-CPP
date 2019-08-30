/*c867 final securityStudent.h
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */

//include the student file to get access to the student class
#include "student.h"

#ifndef SECURITYSTUDENT_H_
#define SECURITYSTUDENT_H_

using namespace std;

//Inherits the public members of the student class
class SecurityStudent : public student {
    //public members
public :
	SecurityStudent();
        ~SecurityStudent();
	SecurityStudent(string, string, string, string, int, int*, Degree);
        
	Degree GetDegreeProgram();
        void print();
        
private:
    Degree DegreeMajor;
};



#endif /* SECURITYSTUDENT_H_ */


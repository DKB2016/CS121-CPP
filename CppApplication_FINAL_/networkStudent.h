/*c867 final networkStudent.h
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */
#ifndef NETWORKSTUDENT_H_
#define NETWORKSTUDENT_H_

#include "student.h"

using namespace std;

//class that inherits the public members of student class
class NetworkStudent : public student{
    //public class members
public:
    NetworkStudent();
    ~NetworkStudent();

    NetworkStudent(string, string, string, string, int, int*, Degree);
    Degree GetDegreeProgram();
    void print();
    //private class members
private:
	Degree DegreeMajor;
};




#endif /* NETWORKSTUDENT_H_ */


/*c867 final softwareStudent.h
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */


#ifndef SOFTWARESTUDENT_H_
#define SOFTWARESTUDENT_H_
#include "student.h"


class SoftwareStudent : public student{
public:
    SoftwareStudent();
    ~SoftwareStudent();
    SoftwareStudent(string, string, string, string, int, int*, Degree);
    
    Degree GetDegreeProgram();
    void print();
private:
   Degree DegreeMajor;

};


#endif /* SOFTWARESTUDENT_H_ */


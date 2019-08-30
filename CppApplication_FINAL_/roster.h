/*c867 final roster.h
 * Scripting and programming applications
 *  David J. Clark
 * Student # 000685359
 * August, 2019
 */

#ifndef ROSTER_H_
#define ROSTER_H_
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include "student.h"
#include <array>


//declaring the roster class
class Roster{
    //declaring the public members of the roster class
public:
	Roster();//constructor
	~Roster();//declares a destructor to release memory 
	student ** getClassRosterArray();
	void add(string, string, string, string, int, int, int, int, Degree);
	void remove(string);
	void printAll();
	void printDaysInCourse(string);
	void printInvalidEmails();
	void printByDegreeProgram(int);
     //declaring the private members of the roster class
private:
        //declares an array of pointers
	student *classRosterArray[5];
        int inx = 0;
	
};



#endif /* ROSTER_H_ */



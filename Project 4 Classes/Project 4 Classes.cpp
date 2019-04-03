#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <ios>;
#include <iomanip>
#include <fstream>
#include <vector>
#include <iostream>

#include "ClassStudent.h"
#include "ProjectFuntions.h"

using namespace std;

void main() {

	//Student *studentList;
	//int listSize = 50;
	//studentList = new Student[listSize];


	vector<Student> Students;

	ifstream fin1("Students.txt");
	ifstream fin2("checkouts.txt");
	ifstream fin3("checkins.txt");
	ofstream fOut("Updated_Students.txt");


	//Main function calls
	readFile(fin1, Students);

	CheckOutFile(fin2, Students);

	CheckInFile(fin3, Students);

	CheckOutReport(fOut, Students);


	cout << "Program Finished!";








	
};

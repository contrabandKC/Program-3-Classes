#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <ios>;
#include <fstream>
#include <iomanip>
#include <vector>
#include "ClassStudent.h"

using namespace std;


/*
Pre: no post conditions
Post:reads files and puts in vector
I/O:Screen / input file and Books vector
Error: none
*/
void readFile(ifstream & rFile, vector<Student>& student);

void CheckOutFile(ifstream & rFile, vector<Student>& student);

void CheckInFile(ifstream & rFile, vector<Student>& student);

void CheckOutReport(ofstream & rFile, vector<Student>& student);


#include "ProjectFuntions.h"

void readFile(ifstream & rFile, vector<Student> & student)
{
	int ID;
	string first;
	string last;
	string item;
	int numItems;
	int count = 0;

	//Reads list in the input file and puts them in the vector.

	while (!rFile.eof()) {

		rFile >> ID >> first >> last >> numItems;

		student.push_back(Student(ID, first, last, numItems));

		if (numItems > 0)
		{
			for (int i = 0; i < numItems; i++)
			{
				rFile >> item;
				student.at(count).CheckOut(item);
			}
		}

		count++;
	}

}

void CheckOutFile(ifstream & rFile, vector<Student>& student)
{

	int ID;
	string item = "";

	while (!rFile.eof()) {

		rFile >> ID >> item;
		for (int i = 0; i < student.size(); i++)
		{
			if (student.at(i).GetId() == ID)
			{
				student.at(i).CheckOut(item);
				break;
			}

		}


	}
}

void CheckInFile(ifstream & rFile, vector<Student>& student)
{
	string item ;

	while (!rFile.eof()) {

		rFile >> item;
		for (int i = 0; i < student.size(); i++)
		{
			if (student.at(i).HasCheckedOut(item))
			{
				student.at(i).CheckIn(item);
				break;
			}

		}


	}
}

void CheckOutReport(ofstream & rFile, vector<Student>& student)
{
	//Tile
	rFile << "Iteams checked out:" << endl;
	rFile << "__________________" << endl << endl << endl;
	rFile << "ID" << "\tFirst" << "\tLast" << "\tItems" << endl << endl;

	//Checks to if they are checked
	for (int i = 0; i < student.size(); i++)
	{
		if (student.at(i).CheckOutCount() > 0)
		{ 
			
			
			rFile << student.at(i);
			
			

		}

	}
}

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <ios>;
#include <iomanip>
#include <vector>

using namespace std;

class Student
{
public:
	Student();
	Student(int ID, string first, string last, int numItems);
	~Student();



	int GetId();
	string GetFirstName();
	string GetLastName();
	int CheckOutCount();

	void SetId(int id);
	void SetFirstName(string first);
	void SetLastName(string last);

	
	bool CheckOut(const string& item);
	bool CheckIn(const string& item);
	bool HasCheckedOut(const string& item);
	void Clear();

	
	friend const istream& operator>>(istream& in, Student& item);

	friend  ostream& operator<<(ostream& out, Student& item);

	

	

private:
	string firstName;
	string lastName;
	unsigned int iDnumber;
	unsigned int numItemsCheckedOut;
	string *items;


};





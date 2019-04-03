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
	Student(const Student& origClass);
	Student& operator=(const Student& objToCopy);
	~Student();



	int GetId();
	string GetFirstName();
	string GetLastName();
	int CheckOutCount();

	void SetId(int id);
	void SetFirstName(string first);
	void SetLastName(string last);

	/*
	Returns the number of items a student has currently checked out. It should not change the object's data.
	*/
	bool CheckOut(const string& item);

	/*Verifies that the item is already on the checked-out list, and removes it.*/
	bool CheckIn(const string& item);

	/*
	Returns true if the item is on the Student's checked-out list, otherwise returns false. Should not change the object's data
	*/
	bool HasCheckedOut(const string& item);

	/*
	This method removes all of the object's data; the ID is set to 0, first and last names to empty strings and all checked-out data deleted.
	*/
	void Clear();
	

	/*
	This is used as an alias for CheckOut. That is, Student Phelps;
const string& item;
Phelps = Phelps + item; // Phelps checks out an item.

	*/
	Student& operator+(const string& item);


	/*
	Addition. Add in place: Another alias for CheckOut. Phelps += item; // another way to check something out
	*/
	bool operator+=(const string& item);

	/*
	Two objects are considered the same if they have the same ID number, otherwise they are unequal.
	*/
	bool operator==(const int& studentID);

	//Two objects are considered the same if they have the same ID number, otherwise they are unequal.
	bool operator!=(const int& studentID);

	


	/*
	Used to read the object's data from an istream (read data from the text files). 
	It is also a friend function and takes a reference to an istream and a reference to a Student as its parameters.
	*/
	friend  istream& operator>>(istream& in, Student& item);


	/*
	Used to send the object's data out to an ostream (write data in text files). 
	It is a friend function that takes a reference to an ostream and a const reference to a Student as its parameters. 
	*/
	friend  ostream& operator<<(ostream& out, Student& item);

	

	

private:
	string firstName;
	string lastName;
	unsigned int iDnumber;
	unsigned int numItemsCheckedOut;
	string *items;


};





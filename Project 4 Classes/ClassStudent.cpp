#include "ClassStudent.h"


int Student::GetId() {
	return iDnumber;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}

void Student::SetId(int id)
{
	if (id > 10000 && id < 100000)
	{
		iDnumber = id;
	}
	
	else
	{//raise exeption
		throw("Invalid ID number!");
	
	}

}

void Student::SetFirstName(string first)
{
	firstName = first;
}

void Student::SetLastName(string last)
{
	lastName = last;
}

int Student::CheckOutCount()
{
	return numItemsCheckedOut;

}

bool Student::CheckOut(const string & item)
{
	//Has checked out??
	if (HasCheckedOut(item))
	{
		return false;
	}
	/* 
	for (int i = 0; i < numItemsCheckedOut; i++)
	{
		if (item == items[i] )
		{
			return false;
		}
	}*/

	if (numItemsCheckedOut == 0)
	{
		delete[]items;
		//numItemsCheckedOut ++;
		this->items = new string[10];
	
	}

	for (int i = 0; i <= numItemsCheckedOut; i++)
	{
		if (items[i].empty())
		{
			this ->items[i] = item;

			numItemsCheckedOut++;
			return true;
		}

	}


	return false;
}

bool Student::CheckIn(const string & item)
{

	
		for (int i = 0; i < numItemsCheckedOut; ++i)
		{
			if (item == items[i])
			{
				items[i] = "";
				for (i; i < numItemsCheckedOut - 1; i++)
				{
					items[i] = items[i + 1];
				}
				
				--numItemsCheckedOut;

				if (numItemsCheckedOut == 0)
				{
					delete[]items;
					items = nullptr;
				}



				return true;
			}

		}



	return false;
}

bool Student::HasCheckedOut(const string & item)
{
	for (int i = 0; i < numItemsCheckedOut; i++)
	{
		if (item == items[i])
		{

			return true;
		}
	}
	return false;
}

void Student::Clear()
{
	this->iDnumber = 0;
	this->firstName = "";
	this->lastName = "";
	this->numItemsCheckedOut = 0;
	delete[]items;
	items = nullptr;
}

Student& Student::operator+(const string& item)
{
	Student* student = this;

	student->CheckOut(item);

	return *student;
}

bool Student::operator+=(const string& item)
{
	return CheckOut(item);
}

bool Student::operator==(const int & studentID)
{
	return this->iDnumber == studentID;;
}

bool Student::operator!=(const int& ID)
{
	return this->iDnumber != ID;
}

Student::Student(const Student& origClass) {
	iDnumber = origClass.iDnumber;
	firstName = origClass.firstName;
	lastName = origClass.lastName;
	numItemsCheckedOut = origClass.numItemsCheckedOut;
	*items = *origClass.items;
}

Student& Student::operator=(const Student& objToCopy) {

	if (this != &objToCopy)
	{
		iDnumber = objToCopy.iDnumber;
		firstName = objToCopy.firstName;
		lastName = objToCopy.lastName;
		numItemsCheckedOut = objToCopy.numItemsCheckedOut;
		*items = *objToCopy.items;

	}

	return *this;
}


istream & operator>>(istream & in, Student & item)
{

	item.Clear();

	int id, numItems;
	string first, last;

	in >> id >> first >> last >> numItems;

	item.SetFirstName(first);
	item.SetLastName(last);
	item.SetId(id);

	if (numItems > 0)
	{
		for (int i = 0; i < numItems; ++i)
		{
			string items;
			in >> items;
			item.CheckOut(items);
		}

	}

	return in;
}

ostream& operator<<(ostream& out, Student& item) {
	
	out << item.GetId() << " " << item.GetFirstName() << " " << item.GetLastName() << endl;
	out << item.CheckOutCount() << endl;

	for (int i = 0; i < item.CheckOutCount(); i++)
	{
		
		out << item.items[i] << " ";		

	}
	
	out << endl << endl;

	return out;

}


 Student::Student()
{
	int iDnumber = 0;
	string firstName = "";
	string lastName = "";
}

Student::Student(int ID, string first, string last, int numItems)
{
	this-> iDnumber = ID;
	this-> firstName = first;
	this-> lastName = last;
	this-> numItemsCheckedOut = 0;
	this-> items = new string[numItems];
}

Student::~Student()
{
}
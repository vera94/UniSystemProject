#include<cassert>
#include<cstring>
#include<iomanip>
#include"Person.h"

using std::cout;
using std::setw;
using std::endl;


Person::Person(char* _first_name, char* _last_name, long int _ucn, char* _address, Faculty _faculty)
{
	first_name = new char[strlen(_first_name) + 1];
	assert(first_name != NULL);
	strcpy(first_name, _first_name);

	last_name = new char[strlen(_last_name) + 1];
	assert(last_name != NULL);
	strcpy(last_name, _last_name);

	address = new char[strlen(_address) + 1];
	assert(address != NULL);
	strcpy(address, _address);

	if (((int)_faculty) < 0 || ((int)_faculty) > 4)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	faculty = _faculty;

	if ((ucn % 10000000000 == 0) || _ucn < 0)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	else ucn = _ucn;
}

Person::Person(const Person& other)
{
	copyP(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		deleteP();
		copyP(other);
	}
	return *this;
}

bool Person::operator<(const Person& other)
{
	int compare_fn = strcmp(this->first_name, other.first_name);
	int compare_ln = strcmp(this->last_name, other.last_name);
	switch (compare_fn)
	{
		case -1: return true; break;
		case 0: if (compare_ln < 0) return true;
				else return false;
		case 1: return false; 
			break;
	}
}

Person::~Person()
{
	deleteP();
}

void Person::copyP(const Person& other)
{
	first_name = new char[strlen(other.first_name) + 1];
	assert(first_name != NULL);
	strcpy(first_name, first_name);

	last_name = new char[strlen(other.last_name) + 1];
	assert(last_name != NULL);
	strcpy(last_name, other.last_name);

	address = new char[strlen(other.address) + 1];
	assert(address != NULL);
	strcpy(address, other.address);

	if (((int)other.faculty) < 1 || ((int)other.faculty) > 4)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	faculty = other.faculty;

	if ((ucn % 10000000000 == 0) || other.ucn < 0)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	else ucn = other.ucn;
}

void Person::deleteP()
{
	delete[] first_name;
	delete[] last_name;
	delete[] address;
}

void Person::print() const
{
	cout << setw(9) << "Name: " << get_first_name() << " " << get_last_name() << endl;
	cout << setw(9) << "Address: " << get_address() << endl;
	cout << setw(9) << "UCN: " << get_ucn() << endl;
	cout << setw(9) << "Faculty: " << faculty << endl;
}

const char* Person::get_first_name() const
{
	return first_name;
}

const char* Person::get_last_name() const
{
	return last_name;
}
const char* Person::get_address() const
{
	return address;
}

Faculty Person::get_faculty() const
{
	return faculty;
}

long int Person::get_ucn() const
{
	return ucn;
}

void Person::set_first_name(const char* _first_name)
{
	if (first_name)
		delete[] first_name;
	first_name = new char[strlen(_first_name) + 1];
	assert(first_name != NULL);
	strcpy(first_name, first_name);
}

void Person::set_last_name(const char* _last_name)
{
	if (last_name)
		delete[] last_name;
	last_name = new char[strlen(_last_name) + 1];
	assert(last_name != NULL);
	strcpy(last_name, _last_name);
}

void Person::set_address(const char* _address)
{
	if (address)
		delete[] address;
	address = new char[strlen(_address) + 1];
	assert(address != NULL);
	strcpy(address, _address);
}

void Person::set_faculty(Faculty _faculty)
{
	if (((int)_faculty) < 1 || ((int)_faculty) > 4)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	faculty = _faculty;
}


void Person::set_ucn(long int _ucn)
{
	if ((ucn % 10000000000 == 0) || _ucn < 0)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	else ucn = _ucn;

}

bool Person::compare_names(Person& p, char* _first_name, char* _last_name) // < i >=
{
	int res_first = strcmp(p.first_name, _first_name);
	int res_last = strcmp(p.last_name, _last_name);

	if (res_first > 0 || res_first == 0 && res_last > 0) return true;
	else return false;
}





#include<cassert>
#include<cstring>
#include<iomanip>
#include"Person.h"

using std::cout;
using std::setw;
using std::endl;


Person::Person(char* _first_name, char* _last_name, char* _ucn, char* _address, Faculty _faculty)
{
	set_first_name(_first_name);
	set_last_name(_last_name);
	set_address(_address);
	set_faculty(_faculty);
	set_ucn(_ucn);
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
	bool flag;
	switch (compare_fn)
	{
	case -1: return true; break;
	case 0: { if (compare_ln < 0) return true;
			return false; }; break;
	case 1: return false; break;
	}

}

Person::~Person()
{
	deleteP();
}

void Person::copyP(const Person& other)
{
	set_first_name(other.first_name);
	set_last_name(other.last_name);
	set_address(other.address);
	set_faculty(other.faculty);
	set_ucn(other.ucn);
}

void Person::deleteP()
{
	delete[] first_name;
	delete[] last_name;
	delete[] address;
	delete[] ucn;
}

void Person::print() const
{
	cout << setw(20) << "Name: " << first_name << " " << last_name << endl;
	cout << setw(20) << "Address: " << address << endl;
	cout << setw(20) << "UCN: " << ucn << endl;
	cout << setw(20) << "Faculty: " << faculty << endl;
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

const char* Person::get_ucn() const
{
	return ucn;
}

void Person::set_first_name(const char* _first_name)
{
	if (first_name)
		delete[] first_name;
	int len_fname = strlen(_first_name) + 1;
	first_name = new char[len_fname];
	assert(first_name != NULL);
	strcpy_s(first_name, len_fname, _first_name);

}

void Person::set_last_name(const char* _last_name)
{
	if (last_name)
		delete[] last_name;
	int len_lname = strlen(_last_name) + 1;
	last_name = new char[len_lname];
	assert(last_name != NULL);
	strcpy_s(last_name, len_lname, _last_name);

}

void Person::set_address(const char* _address)
{
	if (address)
		delete[] address;
	int len_address = strlen(_address) + 1;
	address = new char[len_address];
	assert(address != NULL);
	strcpy_s(address, len_address, _address);
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


void Person::set_ucn(const char* _ucn)
{
	if (ucn)
		delete[] ucn;
	int len_ucn = strlen(_ucn) + 1;
	ucn = new char[len_ucn];
	assert(ucn != NULL);
	strcpy_s(ucn, len_ucn, _ucn);

}

bool Person::compare_names(Person& p, char* _first_name, char* _last_name) //obekta e s po-golqmo
{
	int res_first = strcmp(p.first_name, _first_name);
	int res_last = strcmp(p.last_name, _last_name);

	if (res_first > 0 || res_first == 0 && res_last > 0) return true;
	else return false;
}





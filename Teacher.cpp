#include<iostream>
#include<cassert>
#include"Person.h"
#include"Teacher.h"
#include<iomanip>
using std::cout;
using std::setw;
using std::endl;

Teacher::Teacher(char* _first_name, char* _last_name, long int _ucn, char* _address, Faculty _faculty, Subject _subject, double _salary)
:Person(_first_name, _last_name, _ucn, _address, _faculty)
{
	if (((int)_subject) < 0 || ((int)_subject) > 9)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	subject = _subject;

	if (_salary < 0)
	{
		cout << "Bad input \n";
		exit(1);
	}
	salary = _salary;
}

bool Teacher::operator<(const Teacher& other){
	return Person::operator<(other);
}

bool Teacher::operator>(const Teacher& other){
	return !Person::operator<(other);
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyT(other);

}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		copyT(other);
	}
	return *this;
}


void Teacher::copyT(const Teacher& other)
{
	if (((int)other.subject) < 1 || ((int)other.subject) > 9)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	subject = other.subject;

	if (salary < 0)
	{
		cout << "Bad input \n";
		exit(1);
	}
	salary = other.salary;
}

void Teacher::print() const
{
	Person::print();
	cout << setw(9) << "Subject: " << subject << endl;
	cout << setw(9) << "Salary: " << salary << endl;
}

Subject Teacher::get_subject() const
{
	return subject;
}

double Teacher::get_salary() const
{
	return salary;
}

void Teacher::set_subject(Subject _subject)
{
	if (((int)_subject) < 1 || ((int)_subject) > 9)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	subject = _subject;
}

void Teacher::set_salary(double _salary)
{
	if (salary < 0)
	{
		cout << "Bad input \n";
		exit(1);
	}
	salary = _salary;
}




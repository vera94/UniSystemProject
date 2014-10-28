#include<iostream>
#include<cassert>
#include<iomanip>
#include"Person.h"
#include"Student.h"
using namespace std;


int Student::fac_num = 0;

Student::Student(char* _first_name, char* _last_name, long int _ucn,
	char* _address, Faculty _faculty, Degree _degree, Program _program,
	int _year, double _gpa)
	: Person(_first_name, _last_name, _ucn, _address, _faculty)
{
	if (((int)_degree) < 0 || ((int)_degree) > 2)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	degree = _degree;

	if (((int)_program) < 0 || ((int)_program) > 4)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	program = _program;

	if (_year < 1 || _year > 4)
	{
		cout << "Bad input! \n";
		exit(1);
	}
	year = _year;


	if (_gpa < 2.0 || _gpa > 6.0)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	gpa = _gpa;
}

bool Student::operator<(const Student& other){
	return Person::operator<(other);
}

bool Student::operator>(const Student& other){
	return !Person::operator<(other);
}

void Student::copyS(const Student& other)
{
	degree = other.degree;
	program = other.program;
	year = other.year;
	gpa = other.gpa;
}


Student::Student(const Student& other) : Person(other)
{
	copyS(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		copyS(other);
	}
	return *this;
}


int Student::get_fac_num() const
{
	return fac_num;
}

Degree Student::get_degree() const
{
	return degree;
}

Program Student::get_program() const
{
	return program;
}

int Student::get_year() const
{
	return year;
}

double Student::get_gpa() const
{
	return gpa;
}


void Student::set_degree(Degree _degree)
{
	if (((int)_degree) < 1 || ((int)_degree) > 2)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	degree = _degree;
}

void Student::set_program(Program _program)
{
	if ( ((int)_program) < 1 || ((int)_program) > 4 )
	{
		cout << "Bad input!\n";
		exit(1);
	}
	program = _program;
}

void Student::set_gpa(double _gpa)
{
	if (_gpa < 2.0 || _gpa > 6.0)
	{
		cout << "Bad input!\n";
		exit(1);
	}
	gpa = _gpa;

}

void Student::set_year(int _year)
{
	if (_year < 1 || _year > 4)
	{
		cout << "Bad input! \n";
		exit(1);
	}
	year = _year;

}

void Student::print() const
{
	Person::print();
	cout << setw(9) << "Facult number: " << fac_num << endl;
	cout << setw(9) << "Degree " << degree << ", program: " << program << endl;
	cout << setw(9) << "Year: " << year << endl;
	cout << setw(9) << "GPA: " << gpa << endl;
}



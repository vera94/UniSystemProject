#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

static int fac_num = 0;
enum Degree { Bachelor, Master };
enum Program{ Law, History, Education, Computer_Science };

class Student : public Person
{
public:
	Student(char* = "", char* = "", long int = 0,
		char* = "", Faculty = Faculty_of_Law,
		Degree = Bachelor, Program = Law, int = 1,
		double = 2.0);
	Student(const Student&);
	Student& operator=(const Student&);
	
	bool operator>(const Student&);
	bool operator<(const Student&);

	void print() const;

	Degree get_degree() const;
	Program get_program() const;
	int get_year() const;
	double get_gpa() const;
	int get_fac_num() const;

	void set_degree(Degree);
	void set_program(Program);
	void set_year(int);
	void set_gpa(double);
	//Student& searchS(Type_students&, char*, char*);
	//Student& searchStudent_fn_helper(Type_students&, int);
	//static Student& search(Type_students&, char*, char*);
	//bool compare_names( char*, char*);

private:
	void copyS(const Student& other);
	static int fac_num;
	int year;	// year of education
	double gpa;
	Degree degree;
	Program program;
};

#endif
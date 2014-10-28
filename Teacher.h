#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

enum Subject{
	Algebra,
	Geometry,
	DescreteMaths,
	Algorithms,
	Jav,
	Cpp,
	BulgarianHistory,
	Ruby,
	BulgarianLaw
};

class Teacher : public Person
{
public:
	Teacher(char* = "", char* = "", long int = 0, char* = "", Faculty = Faculty_of_Law, Subject = BulgarianLaw, double = 0.0);

	Teacher(const Teacher&);
	Teacher& operator=(const Teacher&);

	bool operator>(const Teacher&);
	bool operator<(const Teacher&);

	void print() const;

	Subject get_subject() const;
	double get_salary() const;

	void set_subject(Subject);
	void set_salary(double);
	//Teacher& searchT(Type_teachers&, char*, char*);
	//bool compare_names(char*, char*);

private:
	void copyT(const Teacher&);
	Subject subject;
	double salary;

};


#endif;
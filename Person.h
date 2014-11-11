#ifndef PERSON_H
#define PERSON_H

#include<iostream>

using namespace std;


enum Faculty{ Faculty_of_History, Faculty_of_Law, Faculty_of_Education, Faculty_of_Mathematics_and_Informatics };

class Person
{
public:
	Person(char* = " ", char* = " ", char[11]= " ", char* = " ", Faculty = Faculty_of_Law);
	Person(const Person&);
	Person& operator=(const Person&);
	bool operator<(const Person&);
	virtual ~Person();

	//friend fstream& operator<<(fstream &ostr, Person &someone);

	void print() const;

	const char* get_first_name() const;
	const char* get_last_name() const;
	const char* get_address() const;
	Faculty get_faculty() const;
	const char* get_ucn() const;

	void set_first_name(const char*);
	void set_last_name(const char*);
	void set_address(const char*);
	void set_faculty(Faculty);
	void set_ucn(const char*);


	static bool compare_names(Person&, char*, char*);

private:
	void copyP(const Person&);
	void deleteP();
	char *first_name, *last_name, *address, *ucn;
	Faculty faculty;

};

#endif
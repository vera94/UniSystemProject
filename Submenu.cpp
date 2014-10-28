#include<iostream>
#include"Submenu.h"
#include "cstring"


using namespace std;


Type_teachers teachers;
Type_students students;

/*

Type_teachers teachers;
Type_students students;

*/



void Submenu::addStudent()
{
	char *_fname, *_lname, *_address;// *fn, *ln, *ad;
	long int _ucn;
	double _gpa;
	int _faculty, _degree, _program, _year;

	cout << "First name? : "; cin >> _fname;
	cout << "Last name? :"; cin>> _lname;
	cout << "UCN? : "; cin >> _ucn;
	cout << "Address? :"; cin >> _address;
	cout << "Faculty? Press 1 for Faculty of History, 2- Faculty of Law, 3- Faculty of Education , 4- Faculty of Mathematics and Informatics: ";
	cin >> _faculty;
	cout << "Degree? Press 1 for Bachelor or 2 for Master : ";
	cin >> _degree;
	cout << "Program? Press 1 for Law, 2- History, 3- Education, 4- Computer_Science  : ";
	cin >> _program;
	cout << "Year?\n"; cin >> _year;
	cout << "GPA?\n"; cin >> _gpa;
	//set_char(fn, _fname);
	//set_char(ln, _lname);
	//set_char(ad, _address);
	Student student(_fname, _lname, _ucn, _address, (Faculty)_faculty, (Degree)_degree, (Program)_program, _year, _gpa);
	students.insNode(student);
	cout << "The student was added!\n";
}

void Submenu::searchStudentByFN()
{
	int num;
	cout << "Faculty number? :";
	cin >> num;
	Submenu temp;
	Student temp2 = temp.searchStudent_fn_helper(students, num);
}

void Submenu::searchStudent()
{
	char* _first_name, *_last_name;
	cout << "First name? :";
	cin >> _first_name;
	cout << "Last nam? :";
	cin >> _last_name;
	Submenu temp;
	Student temp2 =temp.searchS(students, _first_name, _last_name);
	temp2.print();
}


void Submenu::deleteStudent()
{
	int num;
	cout << "Faculty number? :";
	cin >> num;
	Submenu temp;
	Student temp2 = temp.searchStudent_fn_helper(students, num);
	students.delNode(temp2);
	cout << "The student was deleted! ";
}


void Submenu::addTeacher()
{
	char *_fname, *_lname, *_address;
	long int _ucn;
	int _faculty, _subject;
	double _salary;

	cout << "First name? : "; cin >> _fname;
	cout << "Last name? :"; cin >> _lname;
	cout << "UCN? : "; cin >> _ucn;
	cout << "Address? :"; cin >> _address;
	cout << "Faculty? Press 1 for Faculty of History, 2- Faculty of Law, 3- Faculty of Education , 4 -Faculty of Mathematics and Informatics: ";
	cin >> _faculty;
	cout << "Subject? : Press 1 for Algebra, 2- Geometry, 3- DescreteMaths, 4- Algorithms, 5- Java, 6- Cpp, 7- History, 8- Ruby, 9- Law  ";
	cin >> _subject;
	cout << "Salary? :";
	cin >> _salary;
	Teacher t(_fname, _lname, _ucn, _address, (Faculty)_faculty, (Subject)_subject, _salary);
	teachers.insNode(t);
	cout << "The teacher was added!\n";
}



void Submenu::searchTeacher()
{
	char *_first_name, *_last_name;
	cout << "First name? :";
	cin >> _first_name;
	cout << "Last nam? :";
	cin >> _last_name;
	Submenu item;
	Teacher temp = item.searchT(teachers, _first_name, _last_name);
	temp.print();
}

void Submenu::deleteTeacher()
{
	char* _first_name, *_last_name;
	cout << "First name? :";
	cin >> _first_name;
	cout << "Last nam? :";
	cin >> _last_name;
	Submenu item;
	Teacher temp = item.searchT(teachers, _first_name, _last_name);
	teachers.delNode(temp);
	cout << "The teacher was deleted!";
}

Teacher& Submenu::searchT(Type_teachers& tree, char* _first_name, char* _last_name)
{
	Teacher *temp = &tree.rootAVL();
	if (&temp)
	{
		if (strcmp(temp->get_first_name(), _first_name) == 0 && strcmp(temp->get_first_name(), _first_name) == 0)
			return *temp;
		if (temp->compare_names(*temp, _first_name, _last_name))
			searchT(tree.leftAVL(), _first_name, _last_name);
		else
			searchT(tree.rightAVL(), _first_name, _last_name);
	}
	else{
		cout << "Error";
		exit(1);
	}
}

Student& Submenu::searchS(Type_students& tree, char* _first_name, char* _last_name)
{
	Student *temp = &tree.rootAVL();
	if (&temp)
	{
		if (strcmp(temp->get_first_name(), _first_name) == 0 && strcmp(temp->get_first_name(), _first_name) == 0)
			return *temp;
		if (temp->compare_names(*temp, _first_name, _last_name))
			searchS(tree.leftAVL(), _first_name, _last_name);
		else
			searchS(tree.rightAVL(), _first_name, _last_name);
	}
	else{
		cout << "Error";
		exit(1);
	}
}

Student& Submenu::searchStudent_fn_helper(Type_students& tree, int num)
{
	if (&tree.rootAVL() == NULL) exit(1);
	Student *temp = &tree.rootAVL();
	if (temp->get_fac_num() == num)
	{
		temp->print();
		return *temp;
	}

	searchStudent_fn_helper(tree.leftAVL(), num);
	searchStudent_fn_helper(tree.rightAVL(), num);

}

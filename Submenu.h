#ifndef SUBMENU_H
#define SUBMENU_H
#include "AVL.h"
#include "Student.h"
#include "Teacher.h"

typedef AVL<Teacher> Type_teachers;
typedef AVL<Student> Type_students;

class Submenu
{
public:
	void set_char(char*, char[]);
	void addStudent();
	void searchStudentByFN();
	void searchStudent();
	void deleteStudent();
	Student& searchS(Type_students&, char*, char*);
	Student& searchStudent_fn_helper(Type_students&, int);

	Teacher& searchT(Type_teachers&, char*, char*);
	void addTeacher();
	void searchTeacher();
	void deleteTeacher();

	void Save();
};




#endif
#include <iostream>
#include "Person.h"
#include "Menu.h"
#include "Teacher.h"
#include "Student.h"
#include "Submenu.h"
#include "AVL.h"
using namespace std;



void Menu::main_menu()
{
	int choice;
	bool flag = true;
	while (flag)
	{
		cout << "*******************************\n";
		cout << " 1 - Students.\n";
		cout << " 2 - Teachers.\n";
		cout << " 3 - Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;
		if (choice < 1 && choice > 3)
		{
			cout << "Bad input!";
			exit(1);
		}

		switch (choice)
		{
		case 1:
			students_menu();
			break;
		case 2:
			teachers_menu();
			break;
		case 3:
			cout << "End of Program.\n";
			flag = false;
			break;
		}

	}
}

void Menu::students_menu()
{
	int choice;
	bool flag = true;
	while (flag)
	{
		cout << "*******************************\n";
		cout << " 1 - Add student.\n";
		cout << " 2 - Delete student.\n";
		cout << " 3 - Search student by faculty number.\n";
		cout << " 4 - Search student by name.\n";
		cout << " 5 - Save.\n";
		cout << " 6 - Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;
		if (choice < 1 && choice > 3)
		{
			cout << "Bad input!";
			exit(1);
		}
		Submenu item;
		switch (choice)
		{
		case 1:
			item.addStudent();
			break;
		case 2:
			item.deleteStudent();
			break;
		case 3:
			item.searchStudentByFN();
			break;
		case 4:
			item.searchStudent();
			break;
		case 5:
			//item.Save();
			break;
		case 6:
			cout << "End of Program.\n";
			flag = false;
			break;
		}

	}
}

void Menu::teachers_menu()
{
	int choice;
	bool flag = true;
	while (flag)
	{
		cout << "*******************************\n";
		cout << " 1 - Add teacher.\n";
		cout << " 2 - Delete teacher.\n";
		cout << " 3 - Search teacher.\n";
		cout << " 4 - Save.\n";
		cout << " 5 - Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;
		if (choice < 1 && choice > 3)
		{
			cout << "Bad input!";
			exit(1);
		}
		Submenu item;
		switch (choice)
		{
		case 1:
			item.addTeacher();
			break;
		case 2:
			item.deleteTeacher();
			break;
		case 3:
			item.searchTeacher();
			break;
		case 4:
			//item.Save();
			break;
		case 5:
			cout << "End of Program.\n";
			flag = false;
			break;
		}

	}
}




int main()
{
	Menu obj;
	obj.main_menu();
	return 0;
}
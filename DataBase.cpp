// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include "DataBase.h"
#include <iostream>
using namespace std;

DataBase::DataBase()
{
	studentTree = new BST<Student>();
	facultyTree = new BST<Faculty>();
}

DataBase::~DataBase()
{

}

void DataBase::addStudent(Student s)
{
	studentTree->insert(s);
}

void DataBase::addFaculty(Faculty f)
{
	facultyTree->insert(f);
}

void DataBase::removeStudent(Student s)
{
	studentTree->deleteN(s);
}

void DataBase::removeFaculty(Faculty f)
{
	facultyTree->deleteN(f);
}

void DataBase::printStuTree()
{
	studentTree->printTree();
}

void DataBase::printFacTree()
{
	facultyTree->printTree();
}

void DataBase::studentInfo(int id)
{
	Student st = Student();
	st.setStudentID(id);
	Student st_2 = studentTree->search(st)->getData();
	cout << st_2;
}

void DataBase::facultyInfo(int id)
{
	Faculty fa = Faculty();
	fa.setFacultyID(id);
	Faculty fa_2 = facultyTree->search(fa)->getData();
	cout << fa;
}

void DataBase::studentadvisor(int id)
{
	Student st = Student();
	st.setStudentID(id);
	Student st_2 = studentTree->search(st)->getData();
	int finalinfo = st.getAdvisorID();
	facultyInfo(finalinfo);
}

void DataBase::changedata()
{
	string name = " ";
	string year = " ";
	string major = " ";
	string level = " ";
	string dpt = " ";
	int id = 0;
	int advisorID = 0;
	double gpa = 0;
	Student s = Student();
	Faculty f = Faculty();
	Student i = Student();
	DoublyLinkedList<int>* ids;

	GenStack<BST<Student>*> studentStack = GenStack<BST<Student>*>(5);
	GenStack<BST<Faculty>*> facultyStack = GenStack<BST<Faculty>*>(5);

	studentStack.push(studentTree);
	facultyStack.push(facultyTree);

	bool finish = false;
	while(!finish)
	{
		cout << "Choose one" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "1) Print all students and their information (sorted by ascending id #)" << endl;
		cout << "2) Print all faculty and their information (sorted by ascending id #)" << endl;
		cout << "3) Find and display student information given the students id" << endl;
		cout << "4) Find and display faculty information given the faculty id" << endl;
		cout << "5) Given a student’s id, print the name and info of their faculty advisor" << endl;
		cout << "6) Given a faculty id, print ALL the names and info of his/her advisees" << endl;
		cout << "7) Add a new student" << endl;
		cout << "8) Delete a student given the id" << endl;
		cout << "9) Add a new faculty member" << endl;
		cout << "10) Delete a faculty member given the id." << endl;
		cout << "11) Change a student’s advisor given the student id and the new faculty id." << endl;
		cout << "12) Remove an advisee from a faculty member given the ids" << endl;
		cout << "13) Rollback" << endl;
		cout << "14) Exit" << endl;
		cout << " " << endl;
		cout << "Enter an option: ";

		int input = 0;
		cin >> input;
		cout << "" << endl;


		switch (input)
		{
			case 1:
				printStuTree();
				break;
			case 2:
				printFacTree();
				break;
			case 3:
				cout << "Student ID#: ";
				cin >> id;
				studentInfo(id);
				break;
			case 4:
				cout << "Faculty ID#: ";
				cin >> id;
				facultyInfo(id);
				break;
			case 5:
				cout << "Student ID#: ";
				cin >> id;
				studentadvisor(id);
				break;
			case 6:
				cout << "Faculty ID#: ";
				cin >> id;
				break;

			case 7:
				cout << "Student's name: ";
				cin >> name;
				cout << "" << endl;
				cout << "Student's ID: ";
				cin >> id;
				cout << "" << endl;
				cout << "Student's Advisor ID: ";
				cin >> advisorID;
				cout << "" << endl;
				cout << "Student's year (freshman, sophomore, etc): ";
				cin >> year;
				cout << "" << endl;
				cout << "Student's major: ";
				cin >> major;
				cout << "" << endl;
				cout << "Student's gpa: ";
				cin >> gpa;
				cout << "" << endl;
				studentStack.push(studentTree);
				facultyStack.push(facultyTree);
				break;

			case 8:
				cout << "" << endl;
				cout << "Student ID?: ";
				cin >> id;
				s.setStudentID(id);
				removeStudent(s);

				studentStack.push(studentTree);
				facultyStack.push(facultyTree);
				break;

			case 9:
				cout << "" << endl;
				cout << "Faculty Name: ";
				cin >> name;
				cout << "" << endl;
				cout << "Faculty ID#: ";
				cin >> advisorID;
				cout << "" << endl;
				cout << "faculty Level: ";
				cin >> level;
				cout << "" << endl;
				cout << "faculty department: ";
				cin >> dpt;
				cout << "" << endl;

				studentStack.push(studentTree);
				facultyStack.push(facultyTree);
				break;


			case 10:
				cout << "Faculty ID#: ";
				cin >> id;
				f.setFacultyID(id);
				removeFaculty(f);
				ids = f.getStudentIDs();
				studentStack.push(studentTree);
				facultyStack.push(facultyTree);
				break;

			case 11:
				cout << "Student ID#: ";
				cin >> id;
				i.setStudentID(id);
				s = studentTree->search(i)->getData();
				cout << "" << endl;
				cout << "Enter new Faculty ID: ";
				cin >> advisorID;
				s.setAdvisorID(id);
				addStudent(s);

				studentStack.push(studentTree);
				facultyStack.push(facultyTree);

				break;

			case 12:
				cout << "Student ID#: ";
				cin >> id;
				cout << "" << endl;
				cout << "Advisor ID#: ";
				cin >> advisorID;

				studentStack.push(studentTree);
				facultyStack.push(facultyTree);
				break;

			case 13:
				studentTree = studentStack.pop();
				facultyTree = facultyStack.pop();

				cout << "Rolled back" << endl;
				break;

			case 14:
				input = true;
				break;

			default:
				cout << "Try again" << endl;
				break;
		}
	}
}

// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "FileReader.h"
#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "BST.h"
using namespace std;

class Manager
{
public:
	//make master student and faculty here
	BST<int, Student*>* masterStudent;
	BST<int, Faculty*>* masterFaculty;

	Manager();
	~Manager();

	Student* findStudentWithID(int ID);
	Faculty* findFacultyWithID(int ID);
	void printStudentTree();
	void printFacultyTree();
	void addStudent(Student* newStudent);
	void addFaculty(Faculty* newFaculty);
	void deleteStudent(int ID);
	void deleteFaculty(int ID);
	Faculty* findFacultyWithStudentID(int ID);
	void changeStudentAdvisor(int sID, int fID);
	void printFacultyAdvisees(int fID);
	void removeAdviseeFromFaculty(int sID, int fID);
	void assignAdvisor(int sID, int fID);
};

//make the class expections
//inheriting the runtime error thingy (like extend in java)
class StudentDNEexception : public runtime_error
{
public:
	//have the expection take in the message
	StudentDNEexception(string message) : runtime_error(message.c_str()){}
};

class FacultyDNEexception : public runtime_error
{
public:
	FacultyDNEexception(string message) : runtime_error(message.c_str()) {}
};

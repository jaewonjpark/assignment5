// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5


#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"

class DataBase
{
	private:
		BST<Student> * studentTree;
		BST<Faculty> * facultyTree;
	public:
		DataBase();
		~DataBase();
		void addStudent(Student s);
		void addFaculty(Faculty f);
		void removeStudent(Student s);
		void removeFaculty(Faculty f);
		void printStuTree();
		void printFacTree();
		void changedata();
		void studentInfo(int id);
		void facultyInfo(int id);
		void studentadvisor(int id);

};

// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"


using namespace std;

class FileReader
{
public:
	//constructor
	FileReader();
	//destructor
	~FileReader();
	//preset the files
	static const string studentFileName;
	static const string facultyFileName;

	static BST<int, Student*>* readStudentFile();
	static BST<int, Faculty*>* readFacultyFile();
	//Binary search tree called studentTree of int student IDs and of values students as a pointer
	static void writeToStudentFile(BST <int, Student*>* studentTree);
	//Binary search tree called facultyTree of int faculty IDs and of values faculty as a pointer
	static void writeToFacultyFile(BST <int, Faculty*>* facultyTree);
};

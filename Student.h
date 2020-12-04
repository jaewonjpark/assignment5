// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
	Student(int ID, string name, string grade, string major, double GPA, int adID);
	~Student();
	//overloading operators 
	friend ostream& operator << (ostream& out, const Student& c);
	friend istream& operator >> (istream& out, const Student& c);
	int ID;
	string name;
	string grade;
	string major;
	double GPA;
	int adID;
};

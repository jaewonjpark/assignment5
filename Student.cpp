// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	studentID = 0;
	advisorID = 0;
	name = " ";
	year = " ";
	major = " ";
	gpa = 0;
}

Student::~Student()
{
}

void Student::setStudentID(int id)
{
	studentID = id;
}

void Student::setAdvisorID(int id)
{
	advisorID = id;
}

void Student::setName(string n)
{
	name = n;
}

void Student::setYear(string y)
{
	year = y;
}

void Student::setMajor(string m)
{
	major = m;
}

void Student::setGPA(double g)
{
	gpa = g;
}

int Student::getStudentID()
{
	return studentID;
}

int Student::getAdvisorID()
{
	return advisorID;
}

string Student::getName()
{
	return name;
}

string Student::getYear()
{
	return year;
}

string Student::getMajor()
{
	return major;
}

double Student::getGPA()
{
	return gpa;
}

ostream& operator<<(ostream& os, const Student s)
{
  os << "Student ID: " << s.studentID << endl;
  os << "Name: " << s.name << endl;
  os << "Year: " << s.year << endl;
  os << "GPA: " << s.gpa << endl;
	os << "Advisor ID: " << s.advisorID << endl;
  return os;
}

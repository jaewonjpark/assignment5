// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "Faculty.h"
using namespace std;

Faculty::Faculty()
{
	name = " ";
	level = " ";
	dpt = " ";
}

Faculty::~Faculty()
{

}

void Faculty::setFacultyID(int id)
{
	facID = id;
}

void Faculty::addStudentID(int id)
{
	studentIDs->insertFront(id);
}

void Faculty::remStudentID(int id)
{
	studentIDs->remove(id);
}

void Faculty::setName(string n)
{
	name = n;
}

void Faculty::setLevel(string l)
{
	level = l;
}

void Faculty::setDpt(string d)
{
	dpt = d;
}

string Faculty::getName()
{
	return name;
}

int Faculty::getFacID()
{
	return facID;
}

string Faculty::getLevel()
{
	return level;
}

string Faculty::getDpt()
{
	return dpt;
}

ostream& operator<<(ostream& os, const Faculty f)
{
  os << "Faculty ID: " << f.facID << endl;
  os << "Name: " << f.name << endl;
  os << "Level: " << f.level << endl;
  os << "Department: " << f.dpt << endl;
  return os;

}

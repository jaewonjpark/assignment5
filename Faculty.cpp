// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "Faculty.h"
using namespace std;

//constructor
Faculty::Faculty(int ID, string name, string job, string department)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
	this->department = department;
	//this->studentIDs = studentIDs;
	//make an empty list of student IDs
	studentIDs = new DoublyLinkedList<int>();
}
Faculty::~Faculty()
{

}

//overloaded operator functions
ostream& operator <<(ostream& out, const Faculty& c)
{
	out << "ID: "<<c.ID << endl;
	out << "Name: "<<c.name << endl;
	out << "Job: " <<c.job << endl;
	out << "Department: " << c.department << endl;
	out << *(c.studentIDs) << endl;
	return out;
}

//add students to the faculty list
void Faculty::addStudent(int ID)
{
	studentIDs->insertFront(ID);
}

//remove students from the faculty list
void Faculty::removeStudent(int ID)
{
	studentIDs->remove(ID);
}

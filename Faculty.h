// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#pragma once
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

class Faculty
{
public:
	Faculty(int ID, string name, string job, string department);
	~Faculty();
	int ID;
	string name;
	string job;
	string department;
	DoublyLinkedList <int>* studentIDs;
	void addStudent(int ID);
	void removeStudent(int ID);

	friend ostream& operator << (ostream& out, const Faculty& c);
};

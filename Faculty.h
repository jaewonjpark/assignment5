// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#ifndef Faculty_H //checks whether Faculty_H  is not declared.
#define Faculty_H  //declare Faculty_H once #ifndef generates true.
//include guards / prevents double declaration of any identifiers such as type


#include <iostream>
#include "doublyLinked.h"
using namespace std;

class Faculty
{
	private:
		int facID;
		string name;
		string level;
		string dpt;
		DoublyLinkedList<int> *studentIDs;

	public:
		Faculty();
		~Faculty();

		void setFacultyID(int id);
		void setName(string n);
		void setLevel(string l);
		void setDpt(string dep);
		void addStudentID(int id);
		void remStudentID(int id);

		int getFacID();
		string getName();
		string getLevel();
		string getDpt();

		DoublyLinkedList<int>* getStudentIDs();

		friend ostream& operator<<(ostream& os, const Faculty f); //overloading operator
		friend bool operator<(const Faculty& facultyA, const Faculty& facultyB);
		friend bool operator>(const Faculty& facultyA, const Faculty& facultyB);
		friend bool operator<=(const Faculty& facultyA, const Faculty& facultyB);
		friend bool operator>=(const Faculty& facultyA, const Faculty& facultyB);
		friend bool operator==(const Faculty& facultyA, const Faculty& facultyB);
		friend bool operator!=(const Faculty& facultyA, const Faculty& facultyB);

};


#endif //to know end of #ifndef

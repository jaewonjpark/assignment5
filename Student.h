// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#ifndef Student_H //checks whether Student_H is not declared.
#define Student_H  //declare Student_H once #ifndef generates true.
//include guards / prevents double declaration of any identifiers such as type


#include <iostream>

using namespace std;
class Student
{
	private:
		int studentID;
		int advisorID;
		string name;
		string year;
		string major;
		double gpa;

	public:
		Student();
		~Student();
		void setStudentID(int id);
		void setAdvisorID(int id);
		void setName(string n);
		void setYear(string y);
		void setMajor(string m);
		void setGPA(double g);
		int getStudentID();
		int getAdvisorID();
		string getName();
		string getYear();
		string getMajor();
		double getGPA();

		friend ostream& operator<<(ostream& os, const Student s);
		friend bool operator<(const Student& studentA, const Student& studentB);
		friend bool operator>(const Student& studentA, const Student& studentB);
		friend bool operator<=(const Student& studentA, const Student& studentB);
		friend bool operator>=(const Student& studentA, const Student& studentB);
		friend bool operator==(const Student& studentA, const Student& stuentB);
		friend bool operator!=(const Student& studentA, const Student& stuentB);
};

#endif  //to know end of #ifndef

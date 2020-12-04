// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #5

#include <iostream>
#include "DataBase.h"

using namespace std;

int main(int argc, char** argv)
{
	DataBase* data = new DataBase();

	cout << "WELCOME" << endl;
	cout << "Open file?" << endl;
	cout << "Please enter y/n" << endl;

	string input;
	cin >> input;

	while ((input != "y") && (input != "n"))
	{
		cout << "Invalid answer, please try again (Answer should be y/n)" << endl;
		cout << "WELCOME" << endl;
		cout << "Open existing file?" << endl;
		cout << "please enter y/n" << endl;
		cin >> input;
	}
	if (input == "n")
	{
		cout << "starting with empty" << endl;
		data->changedata();
	}


	Student jae = Student();
	jae.setStudentID(24);
	jae.setAdvisorID(13);
	jae.setName("Jae");


	Student josie = Student();
	josie.setStudentID(23);
	josie.setAdvisorID(22);
	josie.setName("Josie");


	Student eda = Student();
	eda.setStudentID(2);
	eda.setAdvisorID(23);
	eda.setName("Eda");


	Faculty steven = Faculty();
	steven.setFacultyID(12);
	steven.addStudentID(53);
	steven.addStudentID(23);


	Faculty greg = Faculty();
	greg.setFacultyID(31);
	greg.addStudentID(24);
	greg.addStudentID(3);

	data->addFaculty(steven);
	data->addFaculty(greg);


	return 0;
}

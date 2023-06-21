#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

#include "Struct.h"

Node_ID* createNodeID(ID_User x);
void initListID(List_ID& l);
void inputOneID(ifstream& ListID, ID_User& x);
void inputListID(ifstream& ListID, List_ID& l);
void outputListID(List_ID l);
bool checkID(List_ID l, ID_User* User);



Node_Staff* createNodeStaff(Staff x);
void initListStaff(List_Staff& l);
void inputOneStaff(fstream& ListStaff, Staff& x);
void outputOneStaff(Staff x);
void inputListStaff(fstream& ListStaff, List_Staff& l);
void outputListStaff(List_Staff l);


void inputCourse(Course& a);
void initListCourse(List_Course& l);


Node_Student* createNodeStudent(Student x);
void initListStudent(List_Student& l);
void inputOneStudent(fstream& ListStudent, Student& x);
void outputOneStudent(Student x);
void inputListStudent(fstream& ListStudent, List_Student& l);
void outputListStudent(List_Student l);

void viewInfo(ID_User* User);

Node_ID* checkListID(List_ID l, ID_User* User);
void changePassword(ID_User* User, List_ID& l, string newPassword);
void outputFileListID(ofstream& ListID, List_ID l);


Node_School_Year* createNodeSchoolYear(List_Student x);
void initListSchoolYear(List_School_Year& l);
void inputOneSchoolYear(fstream& ListStudent, List_Student& x);
void inputListSchoolYear(List_School_Year& l, List_Student x);
void outputListSchoolYear(List_School_Year l);

Node_Year* createNodeYear(List_School_Year x);
void initListYear(List_Year& l);
void inputListYear(List_Year& l, List_School_Year x);
void outputListYear(List_Year l);

void inputListCourse(List_Course& l);
void outputListCourse(Semester a);




void loginSystem();



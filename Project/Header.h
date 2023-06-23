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
bool checkID(ID_User* User);



Node_Staff* createNodeStaff(Staff x);
void initListStaff(List_Staff& l);
void inputOneStaff(fstream& ListStaff, Staff& x);
void outputOneStaff(Staff x);
void inputListStaff(fstream& ListStaff, List_Staff& l);
void outputListStaff(List_Staff l);


void inputOneCourse(Course& a);
void initListCourse(List_Course& l);


Node_Student* createNodeStudent(Student x);
void initListStudent(List_Student& l, string ClassName);
void inputOneStudent(fstream& ListStudent, Student& x);
void outputOneStudent(Student x);
void inputListStudent(fstream& ListStudent, List_Student& l);
void outputListStudent(List_Student l);

Node_Staff* checkInfoInListStaff(List_Year lAll, ID_User* User);
Node_Student* checkInfoInListStudent(List_Year lAll, ID_User* User);
void viewInfo(List_Year lAll, ID_User* User);

Node_ID* checkListID(ID_User* User);
void changePassword(ID_User* User, List_ID& l, string newPassword);
void outputFileListID(ofstream& ListID, List_ID l);


Node_School_Year* createNodeSchoolYear(List_Student x);
void initListSchoolYear(List_School_Year& l, string name);
void inputOneSchoolYear(fstream& ListStudent, List_Student& x, string ClassName);
void inputListSchoolYear(List_School_Year& l, List_Student x);
void outputListSchoolYear(List_School_Year l);

Node_Year* createNodeYear(List_School_Year x);
void initListYear(List_Year& lAll);
void inputListYear(List_Year& l, List_School_Year x);
void outputListYear(List_Year l);

void inputListCourse(List_Course& l);
void outputListCourse(Semester a);

Student enterOneStudent();
void add1stStudent(List_School_Year& l, string addclass, Student x);
Node_School_Year* findListStudent(List_School_Year l, string classname);


void initListSemester(List_Semester& l);
void inputSemester(Semester& a);
void outputOneSemster(Semester a);
void inputListSemster(List_Year& lAll, Semester x);
void outputListSemester(List_Year& lAll);

void inputOneCourse(Course& a);
void outputOneCourse(Course x);
void outputCourseabb(Course x);
Node_Course* findCourse(Semester a, string courseid);
void updateCourse(Semester& a, string id);
void addStudenttoCourse(Semester& a, string id, Student extra);
void removeHead(List_Student& l);
void removeTail(List_Student& l);
void removeMiddle(List_Student& l, string IDStudent);
void removeStudentOfCourse(Semester& a, string id, string StudentID);
void deleteCourse(Semester& a, string id);

void viewListCourseOfStudent();
void viewAtAnyTime(List_Year lAll);

void loading(List_Year& lAll);
void loginSystem(List_Year& lAll);
void schoolYear(List_Year& lAll);
void semester(List_Year& lAll);



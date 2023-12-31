#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<string.h>
#include<iomanip>
using namespace std;

#include "Struct.h"

//Function of List ID
Node_ID* createNodeID(ID_User x);
void initListID(List_ID& l);
void inputOneID(ifstream& ListID, ID_User& x);
void inputListID(ifstream& ListID, List_ID& l);
void outputListID(List_ID l);
bool checkID(ID_User* User);

//Function of List Staff
Node_Staff* createNodeStaff(Staff x);
void initListStaff(List_Staff& l);
void inputOneStaff(fstream& ListStaff, Staff& x);
void outputOneStaff(Staff x);
void inputListStaff(fstream& ListStaff, List_Staff& l);
void outputListStaff(List_Staff l);

//Function of Course
void inputOneCourse(Course& a);
void initListCourse(List_Course& l);
void inputOneCourse(Course& a);
void outputOneCourse(Course x);
void outputCourseabb(Course x);
void inputListCourse(List_Course& l);
void outputListCourse(Semester a);

//Function of Scoreboard
Node_StudentMark* createNodeStudentMark(StudentMark x);
void initScoreboard(Scoreboard& l);
void inputOneStudentMark(fstream& ScoreboradFile, StudentMark& x);
void outputOneStudent(StudentMark x);
void inputScoreboard(fstream& ScoreboardFile, Scoreboard& l);
void outputScoreboard(Scoreboard l);

//Function of List Student
Node_Student* createNodeStudent(Student x);
void initListStudent(List_Student& l, string ClassName);
void inputOneStudent(fstream& ListStudent, Student& x);
void outputOneStudent(Student x);
void inputListStudent(fstream& ListStudent, List_Student& l);
void outputListStudent(List_Student l);

//Function of Viewing Info
Node_Staff* checkInfoInListStaff(List_Year lAll, ID_User* User);
Node_Student* checkInfoInListStudent(List_Year lAll, ID_User* User);
void viewInfo(List_Year lAll, ID_User* User);

//Function of Changing Password
Node_ID* checkListID(ID_User* User);
void changePassword(ID_User* User, List_ID& l, string newPassword);

//Function of List Class of 1 School year
Node_School_Year* createNodeSchoolYear(List_Student x);
void initListSchoolYear(List_School_Year& l, string name);
void inputOneSchoolYear(fstream& ListStudent, List_Student& x, string ClassName);
void inputListSchoolYear(List_School_Year& l, List_Student x);
void outputListSchoolYear(List_School_Year l);

//Function of List School year of School
Node_Year* createNodeYear(List_School_Year x);
void initListYear(List_Year& lAll);
void inputListYear(List_Year& l, List_School_Year x);
void outputListYear(List_Year l);

//Function of Semester
void initListSemester(List_Semester& l);
void inputSemester(Semester& a);
void outputOneSemster(Semester a);
void inputListSemster(List_Year& lAll, Semester x);
void outputListSemester(List_Year& lAll);

//Function of Removing
void removeHead(List_Student& l);
void removeTail(List_Student& l);
void removeMiddle(List_Student& l, string IDStudent);

//Function of Creating a school year
Student enterOneStudent();
void add1stStudent(List_School_Year& l, string addclass, Student x);
Node_School_Year* findListStudent(List_Year l, string classname);

//Function of Creating a semester
Node_Course* findCourse(Semester a, string courseid);
void updateCourse(Semester& a, string id);
void addStudenttoCourse(Semester& a, string id, Student extra);
void removeStudentOfCourse(Semester& a, string id, string StudentID);
void deleteCourse(Semester& a, string id);

//At any time, an academic staff member can
void viewListClasses(List_Year lAll);
void viewAClass(List_Year lAll, string name);
void viewListCourses(List_Year lAll, string name, string semester);
void viewListStudentOfCourse(List_Year lAll, string courseid);

//End Semester
void outputFileListStudent(ofstream& ListStudent, Semester a, string id); 
void reenterOneStudentMark(StudentMark& x);
void updateStudentResult(Course& a, string studentid);
void viewListFinalMark(List_Course a, string studentid);
float calGPAInOneSemester(Semester a, string studentid);
float calOverallGPA(List_Year lAll, string studentid);

void loading(List_Year& lAll);
void loginSystem(List_Year& lAll);
void schoolYear(List_Year& lAll);
void beginSemester(List_Year& lAll);
void viewListCourseOfStudent(Semester a, string StudentID);
void viewScoreboardOfStudent(List_Year lAll, string studentid);
void viewAtAnyTime(List_Year lAll);
void endSemester(List_Year& lAll);


